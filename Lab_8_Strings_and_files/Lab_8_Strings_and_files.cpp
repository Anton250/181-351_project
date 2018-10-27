

#include "pch.h"
#include <iostream>
#include <cstring>// strcat(), strlen(), strcmp()
//библиотека для работы с C строками
#include <string>
#include <fstream>
using std::cout; using std::string; using std::cin;


/* 
Строки и файлы
строки старого С-типа представляют из себя всего лишь массив
символов с нулевым окончанием:

char cstr1[] = "C-style string1";
char cstr2[] = { 'C', '-', 's', 't', 'y', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', '1', '\0' };
char cstr3[] = {'\67', '\0'};
std::string cppstr1 = "C++ - style string 1"; 
std::string cppstr2 = "";

 

 в типе char на самом деле хранится знаковое целое число. Можно
 складывать делить 


 ФУНКЦИИ ДЛЯ РАБОТЫ С С-СТРОКАМИ
 вывод на печать printf(char[], , ,) или printf(* char, ...)
 */


int main()
{
	std::fstream fs;
	std::fstream text;
	text.open("Text.txt", std::fstream::in); 
	fs.open("Some text.txt", std::fstream::out);

	string user_str;
	getline(text, user_str);
	string user_str2;
	getline(text, user_str2);
	cout << "input string: \n";
	cout << user_str << std::endl;
	cout << "input underline: \n";
	cout << user_str2 << std::endl;
	int pos = 0;
	while (pos != string::npos) {
		pos = user_str.find(user_str2, pos);
		if (pos == string::npos) {
			break;
		}
		fs << pos + 1 << '\t';

		pos++;
	}
	text.close();
	fs.close();
    
}