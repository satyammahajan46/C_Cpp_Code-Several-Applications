

//Preproccesor Directive
#include <iostream>
#include <ctime>
#include <cstdlib>
//Using Namespace standard
using namespace std;
//Contant declaration of ROW and COLUMN
const int MAX_ROW = 10;
const int MAX_COLUMN = 10;

//Prototype Declarations
void getNumbers(int& row, int& col);
int totalMatrixSum(int matrix[][MAX_COLUMN], int row, int col);
void randomFill(int matrix[][MAX_COLUMN], int row, int col);
bool findPath(int matrix[][MAX_COLUMN], char path[][MAX_COLUMN], int row, int col, int sum, int temp, int i = 0, int j = 0);
void intializePath(char path[][MAX_COLUMN], int row, int col);
void printMatrix(int matrix[][MAX_COLUMN], int row, int col);
void printPath(char path[][MAX_COLUMN], int row, int col);
void doStuff();


//Main function
int main() {
	doStuff();
	return 0;
}

//Function that do all the stuff including calling other function and variable declaration
void doStuff() {
	//variables declaration
	int row, column, sum;
	int matrix[MAX_ROW][MAX_COLUMN];
	char path[MAX_ROW][MAX_COLUMN];
	//setting seed for randam values
	srand(time(0));
	//get rows and columns from user
	getNumbers(row, column);
	//randomly fill the matrix
	randomFill(matrix, row, column);
	//intialize the path with all '-'
	intializePath(path, row, column);
	//print matrix
	printMatrix(matrix, row, column);
	//ask user for sum user is looking for
	cout << "what sum are you looking for:";
	//get the sum
	cin >> sum;
	//if total matrix sum is greater than do bother looking for path just quit and display message
	if (totalMatrixSum(matrix, row, column) < sum) {
		cout << "Path not available\n";
		exit(0);
	}
	//if path is found print path otherwise say path not found
	if (findPath(matrix, path, row, column, sum, matrix[0][0]))
		printPath(path, row, column);
	else
		cout << "Path not found\n";
}
/*
Function to intialize path with all '-'
@param row number of rows
@param col number of columns

*/
void intializePath(char m[][MAX_COLUMN], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			m[i][j] = '-';
		}
	}
}
//function to get rows and column from user
/*
@param row number of rows
@param col number of columns
*/
void getNumbers(int& row, int& col) {
	cout << "Enter row:";
	cin >> row;
	cout << "Enter column:";
	cin >> col;
	if ((row > 10 || row < 0) || (col > 10 || col < 0)) {
		cout << "MAX 10" << endl;
		getNumbers(row, col);
	}

}
//function to fill random numbers in matrix
/*
@param matrix matrix which have elements
@param row number of rows
@param col number of columns
*/
void randomFill(int matrix[][MAX_COLUMN], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = 1 + (rand() % 20);
		}
	}
}
//function to find path in matrix
/*
@param matrix matrix which have elements
@param row number of rows
@param col number of columns
@param i index location of row
@param j index location of column
@param temp temporary sum at that moment
@param sum sum we are looking for
@param path matrix which contains path
returns true if path was found, false if path was not found
*/
bool findPath(int matrix[][MAX_COLUMN], char path[][MAX_COLUMN], int row, int col, int sum, int temp, int i, int j) {
	//mark the path
	path[i][j] = 'Z';
	//temp is greater return false
	if (temp > sum) {
		path[i][j] = '-';
		return false;
	}
	//temp is equal to sum we are looking for return true 
	if (temp == sum) {
		path[i][j] = 'X';
		return true;
	}
	
	//right check to check if we can go right
	if ((j + 1 < col && path[i][j+1] == '-')) {
		//nested if to do recursive call and find path
		if (findPath(matrix, path, row, col, sum, temp + matrix[i][j + 1], i, j + 1)) {
			//set path
			path[i][j] = '>';
			return true;
		}
		//otherwise
		else
			//mark as path is not yet set but restrict going to that element
			path[i][j] = 'Z';
	}
	//down check to check if we can go down
	if (i + 1 < row && path[i+1][j] == '-') {
		//nested if to do recursive call and find path
		if (findPath(matrix, path, row, col, sum, temp + matrix[i + 1][j], i+1, j)) {
			//set path
			path[i][j] = 'V';
			return true;
		}
		//otherwise
		else
			//mark as path is not yet set but restrict going to that element
			path[i][j] = 'Z';
	}
	//left check to check if we can go left
	if (j - 1 >= 0 && path[i][j - 1] == '-') {
		//nested if to do recursive call and find path
		if (findPath(matrix, path, row, col, sum, temp + matrix[i][j - 1], i, j-1)) {
			//set path
			path[i][j] = '<';
			return true;
		}
		//otherwise
		else
			//mark as path is not yet set but restrict going to that element
			path[i][j] = 'Z';

	}
	//up check to check if we can go up
	if (i - 1 >= 0 && path[i-1][j] == '-') {
		//nested if to do recursive call and find path
		if (findPath(matrix, path, row, col, sum, temp + matrix[i-1][j], i-1, j)) {
			//set path
			path[i][j] = '^';
			return true;
		}
		//otherwise
		else
			//mark as path is not yet set but restrict going to that element
			path[i][j] = 'Z';
	
	}
	//set path to '-' because you can go there 
	path[i][j] = '-';
	return false;

}
//function to print matrix
/*
@param matrix matrix which have elements
@param row number of rows
@param col number of columns
*/
void printMatrix(int matrix[][MAX_COLUMN], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout.width(3);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
//function to print path
/*
@param path matrix which have path
@param row number of rows
@param col number of columns
*/
void printPath(char path[][MAX_COLUMN], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout.width(3);
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
}
//function to find total matrix sum
/*
@param matrix matrix which have elements
@param row number of rows
@param col number of columns
@return total sum
*/
int totalMatrixSum(int matrix[][MAX_COLUMN], int row, int col) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}









