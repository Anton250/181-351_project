
#include "pch.h"
#include <iostream>
#include "dynamic_matrix_with_operators.h"
//Перегрузка функций, методов и операторов
//Перегрузка - объявление нескольких функций
//(а так же методов классов и операторов, которые 
/*
matrix & matrix::operator += (matrix & second_matr){
this-> setElem(i, j, first_matr[i][j] + second_matr.getElem(i, j))
return (*this);
}
matrix operator +;

*/
int main()
{
	dynamic_matrix_with_operators matr1, matr2, matr3;
	matr1.input();
	matr1.print();
	matr2.input();
	matr3 = matr1 + matr2;
	std::cout << matr3 << std::endl;
	matr3 = matr1 * matr2;
	std::cout << matr3 << std::endl;
	//matr1.multMatrix(matr2);
	//matr1.summMatrix(matr2);
	//matr1.transpMatrix();
	//matr1.print();
	//matr1.clear();
	//matr2.clear();
	return 0;

}
