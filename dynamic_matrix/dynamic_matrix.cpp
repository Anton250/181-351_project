#include "pch.h"
#include <iostream>

class dynamic_matrix {
private:
	int columns;
	int rows;
	double * matr;
public:
	dynamic_matrix();

	~dynamic_matrix() {
	};

	//dynamic_matrix(const dynamic_matrix & matrix) {

	//};
	void clear() {
		delete[] matr; 
		matr = nullptr;
	};

	int getRows()
	{
		return rows;
	}

	int getColumns()
	{
		return columns;
	}

	bool summMatrix(dynamic_matrix matrix2);

	bool multMatrix(dynamic_matrix matrix2);

	double getElem(int row, int col);

	bool input();

	void transpMatrix();

	void print();
};

int main()
{
	dynamic_matrix matr1, matr2;
	matr1.input();
	matr1.print();
	matr2.input();
	//matr1.multMatrix(matr2);
	//matr1.summMatrix(matr2);
	matr1.transpMatrix();
	matr1.print();
	//matr1.clear();
	//matr2.clear();
	return 0;
	
}

dynamic_matrix::dynamic_matrix()
{
}



bool dynamic_matrix::summMatrix(dynamic_matrix matrix2)
{
	if ((columns == matrix2.getColumns()) && (rows == matrix2.getRows())) {
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				matr[i*columns + j] += matrix2.getElem(i, j);
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool dynamic_matrix::multMatrix(dynamic_matrix matrix2)
{
	double * matrix3 = new double[matrix2.getColumns()*rows];
	if (columns == matrix2.getRows()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < matrix2.getColumns(); j++) {
				double sum = 0;
				for (int k = 0; k < columns; k++) {
					sum += matr[i*columns + k] * matrix2.getElem(k, j);
				}
				matrix3[i * matrix2.getColumns() + j] = sum;
			}
		}
		columns = matrix2.getColumns();
		delete[] matr;
		matr = nullptr;
		matr = new double[columns*rows];
		for (int i = 0; i < columns*rows; i++) {
		
				matr[i] = matrix3[i];
		}
		delete[] matrix3;
		matrix3 = nullptr;
		return true;
	}
	else {
		return false;
	}
}

double dynamic_matrix::getElem(int row, int col)
{
	if (row <= rows && col <= columns && row > -1 && col > -1) {
		return matr[row * columns + col];
	}
	std::cout << "Index Error!\n";
	return -1;
}

bool dynamic_matrix::input()
{
	std::cin >> rows;
	if (rows <= 0) {
		return false;
	}
	std::cin >> columns;
	if (columns <= 0) {
		return false;
	}

	matr = new double[columns*rows];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i * columns + j];
		}
	}
	return true;
}

void dynamic_matrix::transpMatrix()
{
	int k = 0;
	double * matrix3 = new double[rows * columns];
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			matrix3[k] = matr[j * columns + i];
			k++;
		}
	}
	for (int i = 0; i < columns*rows; i++) {

		matr[i] = matrix3[i];
	}
	delete[] matrix3;
	matrix3 = nullptr;
	/*for (int i = 0; i < columns; i++) {
		for (int j = i; j < rows; j++) {
			double temporary = matr[j * columns + i];
			matr[j * columns + i] = matr[i * columns + j];
			matr[i * columns + j] = temporary;
		}
	}*/
	int temporary = columns;
	columns = rows;
	rows = temporary;
	
}

void dynamic_matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i * columns + j] << "\t";
		}
		std::cout << "\n";
	}
}
