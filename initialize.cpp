#include <iostream>
#include "linear.hpp"

//creates a new matrix with r rows and c columns
void Matrix::create(int r,int c){
	rows_=r;
	cols_=c;
	array = new double* [rows_];
	for (int i=0;i<rows_;i++){
		array[i] = new double [cols_];
	}
}

//creates a matrix of r rows and c columns and fills each element with the same value
void Matrix::fill(int r,int c,double value){
	rows_=r;
	cols_=c;
	array = new double* [rows_];
	for (int i=0;i<rows_;i++){
		array[i] = new double [cols_];
		for (int j=0;j<cols_;j++){
			array[i][j]=value;
		}
	}
}

//creates an identity matrix of r by r dimensions
void Matrix::eye(int r){
	rows_=r;
	cols_=r;
	array = new double* [rows_];
	for (int i=0;i<rows_;i++){
		array[i] = new double [rows_];
		for (int j=0;j<rows_;j++){
			array[i][j]=(i==j) ? 1:0;
		}
	}
}



//releases the matrix from memory
void Matrix::release(){
	for (int i=0;i<rows_;i++){
		delete[] array[i];
	}
	delete[] array;
}

//displays the matrix
void Matrix::display(){
	for (int i=0;i<rows_;i++){
		for (int j=0;j<cols_;j++){
			std::cout<<array[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}