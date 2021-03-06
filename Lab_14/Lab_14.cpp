#include <iostream> 
#include <iterator>

#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека 
#include <fstream>
#include <string>
#include <list>
#include <set>
#include <map>
/*
#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива
*/

int main()
{
	setlocale(LC_ALL, "rus");
	/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).

	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.

	Достоинство: операции удаления и добавления элемента делаются за const время.

	*/

	std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека 
	int i = 0, a = 0;
	char inputStr = 0;
	/*std::cout<< "Введите 5 целых чисел: "<< std::endl;
	while (i != 5) {
		std::cin>> a;
		stackInt.push(a); // добавляем введенное число 
		i++;
	}

	if (stackInt.empty()) // проверяем пуст ли стек (нет) 
		std::cout<< "Стек не пуст";

	std::cout<< "Верхний элемент стека: "<< stackInt.top()<< std::endl;
	stackInt.pop(); // удаляем верхний элемент 

	std::cout<< "Новый верхний элемент: "<< stackInt.top()<< std::endl;*/

	// ЗАДАНИЕ 1 
	/*
	Проверить правильность расстановки скобок (,),[,],{,}
	в введенном пользователем выражении за линейное время
	(один просмотр выражения).
	2+4-5(87192479_7348){72648]76823[] -> no
	({}) -> yes
	({)} -> no
	*/

	//решение 
	/*
	Считываем элемент.
	Если это (,[ или {, то помещаем ее в стек.
	Если это ),] или }, то сравниваем с верхним элементом стека.
	Если образовалась пара, то верхний элемент стека удаляем.
	Иначе - выражение неправильное.

	Когда все элементы считали, то проверяем стек на пустоту.
	Если стек пуст, то выражение правильное.
	Иначе - выражение неправильное.
	*/ 
	/* !!!!!!!!!!!!!!!!!!!!!!!
	bool correct = true;
	std::stack<char> Skobki;
	while (inputStr != '=') {
		std::cin >> inputStr;
		if (inputStr == '('  || inputStr == '{' || inputStr == '[') {
			Skobki.push(inputStr);
		}
		switch (inputStr) {
		case ')': if (Skobki.top() == '(') {
			Skobki.pop();
		}
				  else {
			std::cout << "Incorrect!";
			correct = false;
			break;
		}
				  break;
		case '}': if (Skobki.top() == '{') {
			Skobki.pop();
		}
				  else {
			std::cout << "Incorrect!";
			correct = false;
			break;
		}
				  break;
		case ']': if (Skobki.top() == '[') {
			Skobki.pop();
		}
				  else {
			std::cout << "Incorrect!";
			correct = false;
			break;
		}
				  break;
		default: break;
		}
		
	}
	 if (correct) std::cout << "All correct!";

	 */
	/*
	Очередь — это структура данных, которая построена по принципу
	LILO (last in — last out: последним пришел — последним вышел).
	*/

	std::queue <int> MyQueue; // создали очередь 
	/*std::cout<< "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a); // добавляем в очередь элементы 
	}
	std::cout << std::endl;
	std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
	MyQueue.pop(); // удаляем элемент из очереди 
	std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;

	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет) 
		std::cout << "Очередь не пуста!";*/
	/*
	Очередь с приоритетом (priority_queue) — это обычная очередь,
	но в ней новый элемент добавляется в такое место,
	чтобы очередь была отсортирована по убыванию.
	*/

	std::priority_queue <int> priority_q; // объявляем приоритетную очередь 

	/*std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a); // добавляем элементы в очередь 
		//std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
	}
	// выводим первый 
	std::cout << "Первый элемент очереди: " << priority_q.top();
	*/
	// ЗАДАНИЕ 2 
	/*
	Программа на вход получает список школьников.
	В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
	затем (через пробел) – фамилия.
	Необходимо вывести список по классам:
	сначала всех учащихся 9 класса, затем – 10, затем – 11.
	Внутри одного класса порядок вывода должен быть таким же, как на входе.
	*/
	/*
	!!!!!!!!!!!!!!!!!!!
	std::string pupils; 
	int grade = 0;
	std::queue <std::string> grade_9;
	std::queue <std::string> grade_10;
	std::queue <std::string> grade_11;
	while (grade != 1) {
		std::cin >> grade;
		switch (grade) {
		case 9: 
			std::getline(std::cin, pupils);
			grade_9.push(pupils); 
			break;
		case 10:
			std::getline(std::cin, pupils);
			grade_10.push(pupils);
			break;
		case 11:
			std::getline(std::cin, pupils);
			grade_11.push(pupils);
			break;
		default:break;
		}
	}
	std::cout << "9 класс: " << "\n";
	int k = grade_9.size();
	for (i = 0; i < k; i++) {
		std::cout << grade_9.front() << '\n';
		grade_9.pop();
	}
	std::cout << "10 класс: " << "\n";
	k = grade_10.size();
	for (i = 0; i < k; i++) {
		std::cout << grade_10.front() << '\n';
		grade_10.pop();
	}
	std::cout << "11 класс: " << "\n";
	k = grade_11.size();
	for (i = 0; i < k; i++) {
		std::cout << grade_11.front() << '\n';
		grade_11.pop();
	}
	*/
	/*
	Создаем 3 очереди (свою для каждого класса).

	Считываем очередную строку. В зависимости от класса
	добавляем фамилию в соответствующую очередь

	Когда все считали, выводим очереди последовательно:

	сначала для 9 класса, затем очередь 10 класса,
	а в самом конце очередь 11 класса.
	*/

	/*
	Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно
	/*удалять и добавлять элементы
		как в начало, так и в конец.

		Дек хранится в памяти так же, как и очередь.
	
	*/

	/*std::deque<int> dequeInt;//deque <тип данных> <имя>; -создание дека
	std::cout << "Введите 5 целых чисел: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		dequeInt.push_back(a); // добавляем введенное число 
		dequeInt.push_front(a);
		i++;
	}

	if (dequeInt.empty()) // проверяем пуст ли стек (нет) 
		std::cout << "Дек не пуст";

	std::cout << "Верхний элемент дека: " << dequeInt.back() << std::endl;
	dequeInt.pop_back(); // удаляем верхний элемент 

	std::cout << "Новый верхний элемент: " << dequeInt.back() << std::endl;
	*/

		//ЗАДАЧА 3 
		/*
		Проверить, является ли введенная строка палиндромом
		(читается одинаково слева направо и справа налево). Использовать дек.
		*/

		/*

		Считываем строку посимвольно. каждый символ добавляем в хвост дека.
		Далее сравниваем первый и последний символ дека.
		*/
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	std::deque<char> Inout_Str;
	correct = true;
	std::cout << '(';
	while (inputStr != ')') {
		std::cin >> inputStr;
		if (inputStr != ')')
		Inout_Str.push_back(inputStr);
	}
	k = Inout_Str.size();
	for (i = 0; i < k / 2; i++) {
		if (Inout_Str.front() != Inout_Str.back()) {
			std::cout << "Не полиндром.";
			correct = false;
			break;
		}
		Inout_Str.pop_back();
		Inout_Str.pop_front();
	}
	if (correct) std::cout << "Полиндром.";
	*/
		//ЗАДАЧА 4 
		/*
		Описать структуру данных List.
		Продемонстрировать работу с этой структурой:
		ввод, вывод,
		добавление элемента и удаление,
		сортировка.
		*/
	std::list <int> listCon;
	int symbol = 0;
	while (symbol != 11) {
		std::cin >> symbol;
		listCon.push_back(symbol);
	}
	std::copy(listCon.begin(), listCon.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << listCon.back() << '\n';
	listCon.pop_back();
	std::cout << listCon.back() << '\n';
	listCon.sort();
	int k = listCon.size();
	for (i = 0; i < k; i++) {
		std::cout << listCon.back();
		listCon.pop_back();
	}




		//ЗАДАЧА 5 
		/*
		Описать структуру данных Set.
		Продемонстрировать работу с этой структурой:
		ввод, вывод,
		добавление элемента и удаление.
		*/
	std::set <int> setCon;


		//ЗАДАЧА 6 
		/*
		Описать структуру данных map.
		Продемонстрировать работу с этой структурой:
		ввод, вывод,
		добавление элемента и удаление.
		*/
	
		// ЗАДАЧА 7 
		/*
		Составить таблицу сравнения по времени выполнения операций
		для дека, стека, очереди, списка, множества, массива из n элементов.
		Список операций:
		добавление в начало
		добавление в конец
		добавление в середину
		удаление из начала
		удаление с конца
		удаление из середины
		значение элемента из начала
		значение элемента с конца
		значение элемента из середины
		*/
		system("pause");
	return 0;
}



