#include "my_string.h"
#include <iostream>
#include <string>

int main()
{
	my_string arr2, arr5;
	std::string str = "String is working";
	my_string arr4(str);
	my_string arr3(arr4);
	std::cout << arr4 << std::endl;
	std::cout << arr3 << std::endl;
	//std::cin >> arr1;
	char adding[30] = "All is correct!";
	my_string arr1(adding);
	//arr1.insert(1, str);
	char d[20] = " Yes, it is. ";
	arr1.add(d);
	//arr1.add(adding);
	std::cin >> arr5;
	std::cout << arr1 << std::endl;
	arr1.insert(16, str);
	arr1.insert(10, d);
	//arr1.clear();
	//arr1.cut(3, 2);
	std::cout << arr1 << std::endl;
	//arr1.cut(3, 3);
	arr2 = arr5 + arr1;
	std::cout << arr2 << std::endl;
//	arr2.crypto();
	int pos = arr2.find((char*)"Yes");
	std::cout << pos << std::endl;
//	arr2.decrypto();
	std::cout << arr2 << std::endl;
	//arr2 = arr4 + arr1;
	//std::cout << arr2;
}

