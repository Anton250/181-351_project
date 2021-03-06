#include "pch.h"
#include <iostream>
#include <string>
char user_text[256] = {};
char original_alphabet[52] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K','L', 'M', 'N', 'O', 'P',
'Q', 'R', 'S', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
'p','q','r','s','t','u','v','w','x','y','z' };
char code_alphabet[52] = { 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O',
'P', 'Q', 'R', 'S', 'U', 'V', 'W', 'X','y', 'z', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
'o','p','q','r','s','t','u','v','w','x' };
char code_text[256] = {};
int i, n, k, answer;
void decode() { //Функция дешифратор.
		std::cout << "Your choice is decode.\n";
		std::cout << "Write your message:\n";
		std::cin.getline(code_text, 256, '\n');
		n = strlen(code_text);
		for (i = 0; i < n; i++) {
			for (k = 0; k < 52; k++) {
				if (code_alphabet[k] == code_text[i]) {
					user_text[i] = original_alphabet[k];
					break;
				}
				if (code_text[i] == ' ' || code_text[i] == '.' ||
					code_text[i] == ',' || code_text[i] == '!' ||
					code_text[i] == '?' || code_text[i] == '-' ||
					code_text[i] == '\'') {
					user_text[i] = code_text[i];
					break;
				}
			}
		}
		std::cout << "Your text:\n\n" << user_text << "\n\n";
}
void encrypt() { //Функция шифратор.
	std::cout << "Your choice is encrypt.\n";
	std::cout << "Write your message:\n";
	std::cin.getline(user_text, 256, '\n');
	n = strlen(user_text);
	for (i = 0; i < n; i++) {
		for (k = 0; k < 52; k++) {
			if (original_alphabet[k] == user_text[i]) {
				code_text[i] = code_alphabet[k];
				break;
			} 
			if (user_text[i] == ' ' || user_text[i] == '.' ||
				user_text[i] == ',' || user_text[i] == '!' ||
				user_text[i] == '?' || user_text[i] == '-' ||
				user_text[i] == '\'') {
				code_text[i] = user_text[i];
				break;
			}
		}
	}
	std::cout << "Your text:\n\n" << code_text << "\n\n";
}
int main()
{	
	bool exit = true;
	while (exit) {
		std::cout << "What you want to do?\n";
		std::cout << "1.Encrypt.\n";
		std::cout << "2.Decode.\n";
		std::cout << "3.Exit.\n";
		std::cout << "Choose the number.\n";
		std::cin >> answer;
		std::cin.get();
		switch (answer) {
		case 1:
			encrypt();
			break;
		case 2:
			decode();
			break;
		case 3:
			exit = false;
			break;
		default:
			std::cout << "Wrong number!\n";
			break;
		}
		
	}
}
