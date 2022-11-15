#include "linear.hpp"
#include <stdexcept>
std::invalid_argument dimension("dimension mismatch, both should be of same dimension");
//adds two matrices. throws error if the dimensions are not same
Matrix add(Matrix matrix1,Matrix matrix2){
	if (matrix1.rows() != matrix2.rows() || matrix1.cols() != matrix2.cols()) throw dimension;
	Matrix sum;
	int rows=matrix1.rows();
	int cols=matrix1.cols();
	sum.create(rows,cols);
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			sum.array[i][j] = matrix1.array[i][j] + matrix2.array[i][j];		
		}
	}
	return sum;
}
//subtracts two matrices. throws error if the dimensions are not same
Matrix subtract(Matrix matrix1,Matrix matrix2){
	if (matrix1.rows() != matrix2.rows() || matrix1.cols() != matrix2.cols()) throw dimension;
	Matrix diff;
	int rows=matrix1.rows();
	int cols=matrix1.cols();
	diff.create(rows,cols);
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			diff.array[i][j] = matrix1.array[i][j] - matrix2.array[i][j];		
		}
	}
	return diff;
}

//returns the multiplication of a matrix with a scalar
Matrix dot(Matrix matrix, double scalar){
	Matrix matrix_new;
	int rows=matrix.rows();
	int cols=matrix.cols();
	matrix_new.create(rows,cols);
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			matrix_new.array[i][j] = scalar*matrix.array[i][j];
		} 
	}
	return matrix_new;
}
//returns matrix multiplication of two matrices. 
Matrix dot(Matrix matrix1,Matrix matrix2){
	int rows1=matrix1.rows(), rows2=matrix2.rows();
	int cols1=matrix1.cols(), cols2=matrix2.cols();
	if (cols1 != rows2) throw dimension;
	Matrix product;
	product.create(rows1,cols2);
	for (int i=0;i<rows1;i++){
		for (int j=0;j<cols2;j++){
			double sum=0;

			for (int k=0;k<rows2;k++){
				sum+=matrix1.array[i][k]*matrix2.array[k][j];
			}
			product.array[i][j]=sum;
		}
	}
	return product;
}


