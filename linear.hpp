double** create(int rows,int cols);

class Matrix{
public:
	double** array;
	int rows() const {return rows_ ;}
	int cols() const {return cols_ ;}

	///////////////initializing functions//////////////////
	void create(int rows,int cols);
	void display();
	void release();
	void fill(int rows,int cols,double value);
	void eye(int rows);
	///////////////////////////////////////////////////////

	//////////////unary operations on matrix///////////////
	double trace();
	double determinant();
	Matrix copy();
	Matrix transpose();
	Matrix inverse();
	///////////////////////////////////////////////////////
private:
	int rows_;
	int cols_;
};


//////////////binary operations on matrices//////////////
Matrix add(Matrix matrix1,Matrix matrix2);
Matrix subtract(Matrix matrix1,Matrix matrix2);
Matrix dot(Matrix matrix, double scalar);
Matrix dot(Matrix matrix1,Matrix matrix2);
///////////////////////////////////////////////////////




