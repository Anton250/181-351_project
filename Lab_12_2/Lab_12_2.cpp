

#define CURL_STATICLIB 

#include "curl/curl.h" 
#include <stdio.h> 
#include <string> 
#include <iostream> 

#ifdef _WIN64 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#elif _WIN32 
#pragma comment (lib, "Normaliz.lib") 
#pragma comment (lib, "Ws2_32.lib") 
#pragma comment (lib, "Wldap32.lib") 
#pragma comment (lib, "Crypt32.lib") 
#pragma comment (lib, "advapi32.lib") 
#endif 


/*
https://github.com/curl/curl.git https://github.com/curl/curl
1. Запустить от учётки админа консоль разработчика VS (x64 Native tools)
2. С помощью CD /D <путь> перейти в папку curl
3. Выполнить buildconf.bat (команда buildconf) - предварительные настройки переменных среды и генерация необходимых файлов
4. Перейти с помощью CD в winbuild
5. Выполнить строку из файла справки BUILD.WINDOWS.txt
*/

static int writer(char *data,
	size_t size,
	size_t nmemb,
	std::string *writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size*nmemb);

	return size * nmemb;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	CURL *curl = nullptr;
	std::string buffer;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://moskva.bankiros.ru/currency/usd");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	//std::cout << buffer << std::endl;
	std::string textToOutput;
	//char courses[20] = {0};
	int pos = 0;
	int lastPos = 0;
	pos = buffer.find("src=\"https://store.bankiros.ru/images/empty.png\" alt=\"", 0);
	buffer.erase(0, pos + 55);
	std::cout << "Bank" << "\t\t" << "Buy" << "\t" << "Sell" << "\t" << "Time of update" << "\n";
	while (pos != std::string::npos) {
		pos = buffer.find("\"https://api.mainfin.ru/bank_logo/icons/", 0);
		if (pos == std::string::npos) {
			break;
		}
		buffer.erase(0, pos + 40);
		//buffer.copy(courses, 8, '.');
		pos = buffer.find('.', 0);
		textToOutput = buffer.substr(0, pos);
		std::cout << buffer.substr(0, pos);
		if (textToOutput.length() < 8) {
			std::cout << "\t\t";
		}
		else {
			std::cout << "\t";
		}
		//printf_s(courses);
		//std::cout << "\t";
		pos = buffer.find("_buy\">", 0);
		buffer.erase(0, pos + 6);
		//buffer.copy(courses, 5);
		pos = buffer.find('<', 0);
		std::cout << buffer.substr(0, pos);
		//printf_s(courses);
		std::cout << '\t';
		pos = buffer.find("_sell\">", 0);
		buffer.erase(0, pos + 7);
		//buffer.copy(courses, 5);
		//printf_s(courses);
		pos = buffer.find('<', 0);
		std::cout << buffer.substr(0, pos);
		std::cout << '\t';
		pos = buffer.find("<div class=\"actual-currency\">", 0);
		buffer.erase(0, pos + 29);
		pos = buffer.find('<', 0);
		std::cout << buffer.substr(0, pos);
		std::cout << "\n";
		/*if (pos == std::string::npos) {
			break;
		}*/
	}
	getchar();
	return 0;
}

