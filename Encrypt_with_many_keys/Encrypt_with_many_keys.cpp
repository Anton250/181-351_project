#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>

std::string user_text_str;
char key[20] = {};
int number_of_keys, i, j, lenght_for_one_key, limit, otherwise, number_of_char,
number_of_key_char, char_for_array, shift_number;
int k = 0;
long key_lenght;

void encryption(std::string user_text_str) {
	long lenght = user_text_str.length();
	otherwise = int(lenght);
	char * user_text_array = (char *) malloc(lenght + 1);
	strcpy_s(user_text_array, lenght+1, user_text_str.c_str());
	std::cout << "Number of keys: ";
	std::cin >> number_of_keys;
	std::cin.get();
	lenght_for_one_key = int(lenght) / number_of_keys;
	for (i = 1; i <= number_of_keys; i++) {
		std::cout << "Key number " << i << " ";
		std::cin.getline(key, 20);
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		key_lenght = strlen(key);
		number_of_char = k;
		number_of_key_char = 0;
		if (lenght >= 0) {
			for (j = number_of_char; j < limit; j++, number_of_key_char++) {
				if (user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array += shift_number;
					if (char_for_array > 90) {
						char_for_array -= 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					k++;
				}
				else if ((user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array += shift_number;
					if (char_for_array > 122) {
						char_for_array -= 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					k++;
				}
				else {
					user_text_array[j] = user_text_array[j];
					k++;
				}
			}
		}
		else {
			for (j = number_of_char; j < otherwise; j++, number_of_key_char++) {
				if (user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array += shift_number;
					if (char_for_array > 90) {
						char_for_array -= 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					k++;
				}
				else if ((user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array += shift_number;
					if (char_for_array > 122) {
						char_for_array -= 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					k++;
				}
				else {
					user_text_array[j] = user_text_array[j];
					k++;
				}
			}
		}

	}
	for (i = 0; i < otherwise; i++) {
		std::cout << user_text_array[i];
	}
}
void decode(std::string user_text_str) {
	long lenght = user_text_str.length();
	otherwise = int(lenght);
	char * user_text_array = (char *)malloc(lenght + 1);
	strcpy_s(user_text_array, lenght + 1, user_text_str.c_str());
	std::cout << "Number of keys: ";
	std::cin >> number_of_keys;
	std::cin.get();
	lenght_for_one_key = int(lenght) / number_of_keys;
	for (i = 1; i <= number_of_keys; i++) {
		std::cout << "Key number " << i << " ";
		std::cin.getline(key, 20);
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		key_lenght = strlen(key);
		number_of_char = k;
		number_of_key_char = 0;
		if (lenght >= 0) {
			for (j = number_of_char; j < limit; j++, number_of_key_char++) {
				if (user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array -= shift_number;
					if (char_for_array < 65) {
						char_for_array += 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					k++;
				}
				else if ((user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array -= shift_number;
					if (char_for_array > 97) {
						char_for_array += 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					k++;
				}
				else {
					user_text_array[j] = user_text_array[j];
					k++;
				}
			}
		}
		else {
			for (j = number_of_char; j < otherwise; j++, number_of_key_char++) {
				if (user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array -= shift_number;
					if (char_for_array < 65) {
						char_for_array += 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					k++;
				}
				else if ((user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
					char_for_array = int(user_text_array[j]);
					shift_number = int(key[number_of_key_char]) - 97;
					char_for_array -= shift_number;
					if (char_for_array < 97) {
						char_for_array += 26;
					}
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					user_text_array[j] = char(char_for_array);
					if (number_of_key_char < key_lenght) {
						number_of_key_char = 0;
					}
					k++;
				}
				else {
					user_text_array[j] = user_text_array[j];
					k++;
				}
			}
		}

	}
	for (i = 0; i < otherwise; i++) {
		std::cout << user_text_array[i];
	}
}
int main()
{
	std::getline(std::cin, user_text_str);
	std::cout << user_text_str << std::endl;
	encryption(user_text_str);
	std::getline(std::cin, user_text_str);
	std::cout << "\n";
	decode(user_text_str);

}


