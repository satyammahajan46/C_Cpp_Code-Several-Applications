/*
Name- Satyam Mahajan
Course - CPSC 1160
Section - 002
Date - 26-05-2018
Purpose - To perform multiplication between two matrices entered by user
*/

//Required Preprocessor directives
#include <iostream>

//Namespace standard
using namespace std;

//Constant global variables
const int MAX_ROW = 5;
const int MAX_COLUMN = 5;

//Prototype Declaration
void readMatrix(int matrix[][MAX_COLUMN], int& row, int& column);
void printMatrix(const int matrix[][MAX_COLUMN], const int row, const int column);
void matrixMultiplication(const int matrix1[][MAX_COLUMN], const int row1, const int column1, const int matrix2[][MAX_COLUMN], const int row2, const int column2, int mul[][MAX_COLUMN], int i=0, int j=0, int k=0 );
int product(int a, int b);
void doStuff();
//main function
int main(){
	//function that do all the multiplication process and all other function are called into this
	doStuff();
	//return statement
	return 0;
}


//function to read matrix
/*
@param matrix matrix to be read
@param row number to rows to be asked from user passed by reference
@param column number to column to be asked from user passed by reference
*/
void readMatrix(int matrix[][MAX_COLUMN], int& row, int& column) {
	//print statement
	cout << "Enter matrix row (max 5) :";
	//input row
	cin >> row;
	//print statement
	cout << "Enter matrix column (max 5) :";
	//input column
	cin >> column;
	//condition to check if given row and column doesnt exceed max row column
	if (row > MAX_ROW || column > MAX_COLUMN) {
		//yes, print message
		cout << "MAX 5" << endl;
		//take input again
		readMatrix(matrix, row, column);
	}
	//otherwise just take values and store them
	else {
		//loop to go thru row
		for (int i = 0; i < row; i++) {
			//loop to go thru column 
			for (int j = 0; j < column; j++) {
				//print statement
				cout << "Enter pos (" << i << ", " << j << ")" << endl;
				//taking input
				cin >> matrix[i][j];
			}
		}
	}
}
//function to print values
/*
@param matrix matrix to be printed
@param row number of rows to be printed
@param column number of column to be printed
*/
void printMatrix(const int matrix[][MAX_COLUMN], const int row, const int column) {
	//loop to go thru row
	for (int i = 0; i < row; i++) {
		//loop to go thru column 
		for (int j = 0; j < column; j++) {
			//printing matrix element
			cout.width(5);
			cout << matrix[i][j] << " ";
		}
		//new line
		cout << endl;
	}
}
//recursive function to perform matrix multiplication
/*
@param matrix1 matrix to be multiplied
@param matrix2 matrix to be multiplied
@param row1 number of rows of matrix1
@param row2 number of rows of matrix2
@param column1 number of column of matrix1
@param column2 number of column of matrix2
@param mul matrix in which multiplication result is stored
@params i,j,k required for recurvise method
*/
void matrixMultiplication(const int matrix1[][MAX_COLUMN],const int row1,const int column1,const int matrix2[][MAX_COLUMN],const int row2, const int column2, int mul[][MAX_COLUMN], int i, int j, int k) {
	//condtion to check all rows are processed
	if (i < row1) {
		//condtion to check all required column are processed
		if (j < column2) {
			//condtion to check required column are processed
			if (k < column1) {
				//if k is zero
				if (k == 0)
					//set matrix element to zero
					mul[i][j] = 0;
				//satement to call recursive product function and add it to required element position
				mul[i][j] += product(matrix1[i][k], matrix2[k][j]);
				//call function again but this time with k+1
				matrixMultiplication(matrix1, row1, column1, matrix2, row2, column2, mul, i, j, k + 1);
			}
			//else case for k
			else
				//call function again but this time when j+1, means next column of matrix2 that is to be processed
				matrixMultiplication(matrix1, row1, column1, matrix2, row2, column2, mul, i, j + 1, k = 0);
		}
		//else case for j
		else
			//call function again but this time when i+1, means next row of matrix1 that is to be processed
			matrixMultiplication(matrix1, row1, column1, matrix2, row2, column2, mul, i + 1, j = 0, k = 0);
	}
}
//recursive function to perform multiplication
/*
@param a, a to be multiplied
@param b, b to be multiplied
@return product of a and b
*/
int product(int a, int b) {
	//if a is greter than b swap numbers
	if (a > b)
		//return swaped numbers
		return product(b, a);
	//else case to check b is not equal to zero
	else if (b != 0)
		//return a + call function again this b-1
		return a + product(a, b - 1);
	//if b is 0 then return 0
	else
		return 0;
}


//function that that has variables declaration and all function calling that fullfil purpose of the program 
void doStuff() {
	//variable declaration
	int mOneRow = 0, mOneColumn = 0, mSecRow = 0, mSecColumn = 0;
	int matrix1[MAX_ROW][MAX_COLUMN], matrix2[MAX_ROW][MAX_COLUMN], result[MAX_ROW][MAX_COLUMN];
	//call function to read matrix1
	readMatrix(matrix1, mOneRow, mOneColumn);
	//call function to read matrix2
	readMatrix(matrix2, mSecRow, mSecColumn);
	//call function to print matrix1
	printMatrix(matrix1, mOneRow, mOneColumn);
	cout << "*" << endl;
	//call function to print matrix2
	printMatrix(matrix2, mSecRow, mSecColumn);
	cout << "=" << endl;
	//condition to check that multiplication between matrix is possible or not
	if (mOneColumn == mSecRow) {
		//call function to perform multiplication
		matrixMultiplication(matrix1, mOneRow, mOneColumn, matrix2, mSecRow, mSecColumn, result);
		//call function to print result
		printMatrix(result, mOneRow, mSecColumn);
	}
	//if condition fails print multiplication not possible
	else
		cout << "Multiplication not possible";
	
}
