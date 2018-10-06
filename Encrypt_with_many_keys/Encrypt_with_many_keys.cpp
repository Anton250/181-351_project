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
long lenght;
char * user_text_array;
void get_str_to_array(std::string user_text_str) {
	lenght = user_text_str.length();
	user_text_array = (char *) malloc(lenght * sizeof(char));
	strcpy_s(user_text_array, lenght + 1, user_text_str.c_str());
}
void cycle_for_encrypt(char * user_text_array, int limit, char * key, int number_of_char, int * k) {
	key_lenght = strlen(key);
	for (j = number_of_char; j < limit; j++, number_of_key_char++) {
		if ((user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') ||
			(user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
			char_for_array = int(user_text_array[j]);
			shift_number = int(key[number_of_key_char]) - 97;
			char_for_array += shift_number;
			if ((char_for_array > 90 && user_text_array[j] <= 90) || char_for_array > 122) {
				char_for_array -= 26;
			}
			if (number_of_key_char < key_lenght) {
				number_of_key_char = 0;
			}
			user_text_array[j] = char(char_for_array);
			k++;
		}
		else {
			user_text_array[j] = user_text_array[j];
			k++;
		}
	}
}
void cycle_for_decode(char * user_text_array, int limit, char * key, int number_of_char, int * k) {
	key_lenght = strlen(key);
	for (j = number_of_char; j < limit; j++, number_of_key_char++) {
		if ((user_text_array[j] >= 'A' && user_text_array[j] <= 'Z') ||
			(user_text_array[j] >= 'a' && user_text_array[j] <= 'z')) {
			char_for_array = int(user_text_array[j]);
			shift_number = int(key[number_of_key_char]) - 97;
			char_for_array -= shift_number;
			if ((char_for_array > 90 && user_text_array[j] <= 90) || char_for_array > 122) {
				char_for_array += 26;
			}
			if (number_of_key_char < key_lenght) {
				number_of_key_char = 0;
			}
			user_text_array[j] = char(char_for_array);
			k++;
		}
		else {
			user_text_array[j] = user_text_array[j];
			k++;
		}
	}
}
void encryption(char * user_text_array) {
	int lenght = strlen(user_text_array);
	otherwise = lenght;
	std::cout << "Number of keys: ";
	std::cin >> number_of_keys;
	std::cin.get();
	lenght_for_one_key = lenght / number_of_keys;
	for (i = 1; i <= number_of_keys; i++) {
		std::cout << "Key number " << i << " ";
		std::cin.getline(key, 20);
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		key_lenght = strlen(key);
		number_of_char = k;
		number_of_key_char = 0;
		if (lenght >= 0) {
			cycle_for_encrypt(user_text_array, limit, key, number_of_char, &k);
		}
		else {
			
			cycle_for_encrypt(user_text_array, otherwise, key, number_of_char, &k);
		}

	}
}
void decode(std::string user_text_str) {
	int lenght = strlen(user_text_array);
	otherwise = lenght;
	std::cout << "Number of keys: ";
	std::cin >> number_of_keys;
	std::cin.get();
	lenght_for_one_key = lenght / number_of_keys;
	for (i = 1; i <= number_of_keys; i++) {
		std::cout << "Key number " << i << " ";
		std::cin.getline(key, 20);
		lenght -= lenght_for_one_key;
		limit = lenght_for_one_key * i;
		key_lenght = strlen(key);
		number_of_char = k;
		number_of_key_char = 0;
		if (lenght >= 0) {
			cycle_for_decode(user_text_array, limit, key, number_of_char, &k);
		}
		else {
			cycle_for_decode(user_text_array, otherwise, key, number_of_char, &k);
		}

	}
}
int main()
{
	std::getline(std::cin, user_text_str);
	get_str_to_array(user_text_str);
	
}


