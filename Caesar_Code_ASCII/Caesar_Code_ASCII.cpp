#include "pch.h"
#include <iostream>
#include <string>
char user_text[256] = {};
int shift_number, lenght, i, code;
void encrypt(char * user_text, int key){
	lenght = strlen(user_text);
	for (i = 0; i < lenght; i++) {
		if (user_text[i] >= 'A' && user_text[i] <= 'z') {
			code = user_text[i] + key;
			if ((code > 122) || (code > 90 && int(user_text[i]) <= 90)) {
				code -= 26;
			}
			user_text[i] = char(code);
		}
		else {
			 user_text[i] = user_text[i];
		}
	}
}
void decode(char * user_text, int key) {
	lenght = strlen(user_text);
	for (i = 0; i < lenght; i++) {
		if (user_text[i] >= 'A' && user_text[i] <= 'z') {
			code = user_text[i] - key;
			if ((code < 65) || (code < 97 && int(user_text[i]) >= 97)) {
				code += 26;
			}
			user_text[i] = char(code);
		}
		else {
			user_text[i] = user_text[i];
		}
	}
}
void print_array(char * arr) {
	int lenght = strlen(arr);
	for (int i = 0; i < lenght; i++) {
		std::cout << arr[i];
	}
}
//mollock
int main()
{
	std::cout << "Shift: ";
	std::cin >> shift_number;
	std::cin.get();
	std::cout << "Your text: " << std::endl;
	std::cin.getline(user_text, 256);
	std::cout << "Encrypted text: " << std::endl;
	encrypt(user_text, shift_number);
	print_array(user_text);
	std::cout << "\n";
	std::cout << "Decoded text: " << std::endl;
	decode(user_text, shift_number);
	print_array(user_text);
}

