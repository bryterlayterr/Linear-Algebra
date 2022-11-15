//The trace of a matrix is defined as the sum of the elements in its diagonals
#include <iostream>
#include <stdexcept>
#include "linear.hpp"

std::invalid_argument square( "Not a square matrix");
std::runtime_error existence("Inverse does not exist");

double swap(double &a, double b);

//calculates trace of matrix(sum of diagonal elements). throws error if the matrix is not a square
Matrix swap(Matrix &matrix,Matrix I,int i,bool &t);
	double Matrix::trace(){
	if (rows_ == cols_){
		double sum=0;
		for (int i=0;i<rows_;i++){
			sum+=array[i][i];
		}
		return sum;
	}
	else{
		throw square;
	}
}
//calulates determinant recursively.
double Matrix::determinant(){
	if (rows_ != cols_){
		throw square;
	}
	else{
		if (rows_==2){
			return array[0][0] * array[1][1] - array[0][1]*array[1][0];
		}
		else{
			double d = 0;
			for (int i=0;i<rows_;i++){
				if (array[0][i] == 0) continue;
				else{
					Matrix sub_matrix;
					sub_matrix.create(rows_-1,cols_-1);
					for (int j=0;j<rows_-1;j++){
						for (int k=0;k<cols_-1;k++){
							sub_matrix.array[j][k] = (k<i) ? array[j+1][k] : array[j+1][k+1];
						}
					}
					d += /*pow(-1,i%2)*/array[0][i] * sub_matrix.determinant();
					sub_matrix.release();
				}
			}
			return d;
		}
	}
}
//copies matrix into another matrix
Matrix Matrix::copy(){
	Matrix copy_matrix;
	copy_matrix.create(rows_,cols_);
	for (int i=0;i<copy_matrix.rows_;i++){
		for (int j=0;j<copy_matrix.cols_;j++){
			copy_matrix.array[i][j] = array[i][j];
		}
	}
	return copy_matrix;
}
//transposes a matrix
Matrix Matrix::transpose(){
	Matrix transpose_matrix;
	transpose_matrix.create(cols_,rows_);
	for (int i=0;i<rows_;i++){
		for (int j=0;j<cols_;j++){
			transpose_matrix.array[j][i] = array[i][j];
		} 
	}
	return transpose_matrix;	
}

//calculates inverse of the matrix using gauss jordan method.
Matrix Matrix::inverse(){
	if (rows_!=cols_) throw square;
	Matrix A=copy(),I;
	I.eye(rows_);
	for (int i=0;i<rows_;i++){		
		if (A.array[i][i] != 0){
			for (int j=0;j<cols_;j++){
				I.array[i][j]/=A.array[i][i];
				if (i!=j) A.array[i][j]/=A.array[i][i];
			}
			A.array[i][i]=1;
			for (int j=0;j<rows_;j++){
				if (i!=j){
					for (int k=0;k<cols_;k++){
						I.array[j][k]-=A.array[j][i]*I.array[i][k];
						if (k!=i) A.array[j][k]-=A.array[j][i]*A.array[i][k];
					}
					A.array[j][i]=0;
				}
			}		
		}
		else{
			bool t=true;
			I=swap(A,I,i,t);
			A.release();
			if (! t) throw existence;	
		}
	}
	A.release();
	return I;
}

Matrix swap(Matrix &matrix,Matrix I,int i,bool &t){
	for(int j=i;j<matrix.rows();j++){
		if (i != j){
			for (int k=0;k<matrix.rows();k++){
				matrix.array[i][k] = swap(matrix.array[j][k],matrix.array[i][k]);
				I.array[i][k] = swap(I.array[j][k],I.array[i][k]);
			}
			if (matrix.array[i][i] != 0){
				return I;
			}
			else{
				for (int k=0;k<matrix.rows();k++){
					matrix.array[i][k] = swap(matrix.array[j][k],matrix.array[i][k]);
					I.array[i][k] = swap(I.array[j][k],I.array[i][k]);
				}
			}
			
		}
	}
	t=false;
	return I;
}

double swap(double &a, double b){
	double temp;
	temp=a;
	a=b;
	b=temp;
	return b;
}
