
#include "pch.h"
#include <iostream>

class matrix {
private:
	double matr[10][10];
	int columns, rows;
public:
	matrix();
	~matrix();
	int getRows()
	{
		return rows;
	}

	int getColumns()
	{
		return columns;
	}

	bool summMatrix(matrix matrix2);

	bool multMatrix(matrix matrix2); 

	double getElem(int row, int col);

	bool input();

	bool transpMatrix() {
		for (int i = 0; i < rows; i++) {
			for (int j = i; j < columns; j++) {
				matr[i][j] = matr[j][i];
			}
		}
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << matr[i][j];
			}
		}
	}
};

int main()
{
   
}

bool matrix::summMatrix(matrix matrix2)
{
	if ((columns == matrix2.getColumns()) && (rows == matrix2.getRows())) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				matr[i][j] += matrix2.getElem(i, j);
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool matrix::multMatrix(matrix matrix2)
{
	double matrix3[10][10];
	if (rows == matrix2.getColumns()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < matrix2.getColumns(); j++) {
				int sum = 0;
				for (int k = 0; k < rows; k++) {
					sum += matr[i][k] * matrix2.getElem(k, j);
				}
				matrix3[i][j] = sum;
			}
		}

		return true;
	}
	else {
		return false;
	}
}

double matrix::getElem(int row, int col)
{
	if (row < rows && col < columns && row > -1 && col > -1) {
		return matr[row][col];
	}
	std::cout << "Index Error!\n";
	return -1;
}

bool matrix::input()
{
	std::cin >> rows;
	if (rows >= 10 || rows <= 0) {
		return false;
	}
	std::cin >> columns;
	if (columns >= 10 || columns <= 0) {
		return false;
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i][j];
		}
	}
	return true;
}
