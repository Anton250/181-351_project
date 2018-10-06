/*1. СИНТАКСИС ОБЪЯВЛЕНИЯ КЛАССА
 class Имя_Класса 
 {
	int hp; число ХП
	double speed; скорость персонажа
	void heal(); восстановление ХП
	void move(); проигрывание анимации
 }
*/
/* Определение класса и объекта
СВОЙСТВО (PROPERTY) - переменная в составе класса
МЕТОД (method) - функция в составе класса
ИНКАПСУЛЯЦИЯ - фактически, объединение данных и методов, объединённых 
единым смыслом, в одну конструкцию языка
НАСЛЕДОВАНИЕ - создание производных классов от родительского и заимствование
его свойств и методов
ПОЛИМОРФИЗМ простыми словами: экземпляры одного класса ведут себя по-разному
инкапсуляция, наследование и полиморфизм - три основные идеи ООП
*/
#include "pch.h"
#include <iostream>
#include <string>

class vehicle // скорость
{
private: //спецификатор класса можно обратиться через метод класса
public:
	double speed; //скорость

	char regnumber[6] = { 0 };//госномер
	unsigned char capacity;//число пассажиров

	bool check_regnumber() //если зарегестрирован - true
	{

	};
	//void add_passenger(int passsengers);
	//void accelerate(double delta_velocity);
}; 
class user_data {
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthdate[10];
public:
	bool set_firstname(char p_firstname[255]) {
		int lenght = strlen(p_firstname);
		for (int i = 0; i < lenght; i++) {
			if (p_firstname[i] < 'A' || (p_firstname[i] > 'Z' &&
				p_firstname[i] < 'a') || p_firstname[i] > 'z' || 
				p_firstname[i] != '-') {
				return false;
			}
		}
		return true;
		//проверять на отсутствие цифр, точек и других знаков препинания кроме "-"
	}
	bool set_birthdate(char p_birthdate[10]) {
		for (int i = 0; i < 2; i++) {
			if (p_birthdate[i] < '0' || p_birthdate[i] > '9') {
				return false;
			}
		}
		for (int i = 3; i < 5; i++) {
			if (p_birthdate[i] < '0' || p_birthdate[i] > '9') {
				return false;
			}
		}
		for (int i = 6; i < 10; i++) {
			if (p_birthdate[i] < '0' || p_birthdate[i] > '9') {
				return false;
			}
		}
		if (p_birthdate[2] != '.' || p_birthdate[5] != '.') {
			return false;
		}
		//должно соответствовать формату 00.00.0000
		return true;
	};
	bool set_passport(char p_passport[10]) {
		for (int i = 0; i < 10; i++) {
			if (p_passport[i] < '0' || p_passport[i] > '9') {
				return false;
			}
		}
		//строка должна содержать 10 цифр
		return true;
	};
};
//2. СИНТАКСИС ОБЪЯВЛЕНИЯ ОБЪЕКТА И ОБРАЩЕНИЯ К СВОЙСТВАМ И МЕТОДАМ
//Имя_Класса объект1;
//vehicle car;
//car.speed = 123;
//обЪект1.свойство1 = 1;
//обЪект1.метод3();

/*3. СПЕЦИФИКАТОРЫ ДОСТУПА
К полям (свойсвтвам и методам), объявленным в разделе public:
можно обращаться везде (и из методов класса, и снаружи, где виден объект)
К полям private и protected 
*/

int main()
{
	user_data birthdate;
	char birthdate_array[11] = "25.09.2000";
	if (birthdate.set_birthdate(birthdate_array)) {
		std::cout << "All is fine.";
	}
	else {
		std::cout << "Error";
	}

	int *arr;
	int num;
	std::cin >> num;
	arr = (int*)malloc(num * sizeof(int));
}
