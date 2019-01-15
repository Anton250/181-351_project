


#include <iostream>
#include <string>

/*int findMax(int * arr) {
	int len = sizeof(arr);
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
char findMax(char * arr) {
	int len = sizeof(arr);
	char max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
double findMax(double * arr) {
	int len = sizeof(arr);
	double max = arr[0];
	for (int i = 0; i < len; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}*/

/*template<typename TN>
class myList {
public:
	TN element;
	myList * prev;
	myList * next;
	myList * first_elem;

	myList();
	myList(TN el);
	~myList();

	void changer(myList<TN> & old, myList<TN> newt) {
		old.next = newt;
	};
	/*myList<TN> *prevent() {
		return (this->prev);
	};
	myList<TN> *next2() {
		return (this->next);
	};
	void print();
	void push_back(TN new_elem);

};*/
template<typename TN>
class root {
public:
	TN element;
	root<TN> * down;
	root<TN> * right;
	int levels;
	root();
	root(TN elem);
	~root();
	int add_son(TN new_elem);
	int add_brother(TN new_elem, int level);
	void print();

};

int main()
{
	/*int len;
	std::cin >> len;
	int* arr_int = new int[len];
	for (int i = 0; i < len; i++) {
		std::cin >> arr_int[i];
	}
	std::cout << findMax(arr_int) << std::endl;
	std::cin >> len;
	char* arr_char = new char[len];
	for (int i = 0; i < len; i++) {
		std::cin >> arr_char[i];
	}
	std::cout << findMax(arr_char) << std::endl;
	std::cin >> len;
	double* arr_double = new double [len];
	for (int i = 0; i < len; i++) {
		std::cin >> arr_double[i];
	}
	std::cout << findMax(arr_double) << std::endl;*/
	/*myList<int>list(1);
	list.push_back(2);
	list.push_back(3);
	list.print();*/
	std::string input;
	std::cin >> input;
	root<std::string> roots(input);
	std::cin >> input;
	roots.add_son(input);
	std::cin >> input;
	roots.add_son(input);
	std::cin >> input;
	roots.add_brother(input, 1);
	std::cin >> input;
	roots.add_brother(input, 2);
	roots.print();
	return 0;
}

/*template<typename TN>
myList<TN>::myList()
{
	prev = NULL;
	next = NULL;
}

template<typename TN>
myList<TN>::myList(TN el)
{
	prev = NULL;
	next = NULL;
	element = el;
}

template<typename TN>
myList<TN>::~myList()
{
	if (prev != NULL) {
		delete prev;
	}
	if (next != NULL) {
		delete next;
	}
}

template<typename TN>
void myList<TN>::print()
{
	myList<TN> *temp = new myList<TN>;
	temp = this;
	while (temp->prev != NULL)
	{
		*this = *(temp->prev);
		temp = this;
	}
	while (temp->next != NULL)
	{
		std::cout << temp->element << '\t';
		temp = temp->next;
		//*this = *temp;
	}
	std::cout << temp->element << '\t';
}

template<typename TN>
void myList<TN>::push_back(TN new_elem)
{
	myList<TN> *tmp = new myList<TN>;//указатель на новый элемент
	myList<TN> *tmp1 = new myList<TN>;//указатель на текущий элемент
	tmp1 = this;// создаём копию указателя
	tmp1->next = tmp;//изменяем указатель на следующий элемент для текущего элмента
	tmp->element = new_elem;
	tmp->prev = tmp1;//this
	tmp->next = NULL;
	//tmp1->next = tmp;//изменяем указатель на следующий элемент для текущего элмента

	this->element = tmp->element;
	this->prev = tmp1;
	this->next = NULL;//TMP


}




/*template<typename TN>
root<TN> root<TN>::operator=(root & new_element)
{
	this->element = new_element.element;
	this->down = new_element.down;
	this->right = new_element.right;
	this->head = new_element.head;
	return *this;
}*/

template<typename TN>
root<TN>::root()
{
	right = NULL;
	down = NULL;
	levels = 0;
	
	
}

template<typename TN>
root<TN>::root(TN elem)
{
	right = NULL;
	down = NULL;
	levels = 0;
	element = elem;
}

template<typename TN>
root<TN>::~root()
{
	
	if (down != NULL) {
		delete down;
	}

	if (right != NULL) {
		delete right;
	}
}





template<typename TN>
int root<TN>::add_son(TN new_elem)
{
	root <TN> * head_ptr = new root<TN>;
	levels++;
	head_ptr = this;
	while (head_ptr->down != NULL) {
		head_ptr = head_ptr->down;
	}
	root <TN> * tmp_ptr = new root<TN>;
	head_ptr->down = new root<TN>;
	head_ptr->down = tmp_ptr;
	tmp_ptr->element = new_elem;
	tmp_ptr->down = NULL;
	tmp_ptr->right = NULL;
	return 0;
}

template<typename TN>
int root<TN>::add_brother(TN new_elem, int level)
{
	if (level > levels) {
		return -1;
	}
	root <TN> * head_ptr = new root<TN>;
	head_ptr = this;
	for (int i = 0; i < level; i++) {
		head_ptr = head_ptr->down;
	}
	while (head_ptr->right != NULL) {
		head_ptr = head_ptr->right;
	}
	root <TN> * tmp_ptr = new root<TN>;
	head_ptr->right = new root<TN>;
	head_ptr->right = tmp_ptr;
	tmp_ptr->element = new_elem;
	tmp_ptr->down = NULL;
	tmp_ptr->right = NULL;
	return 0;
}

template<typename TN>
void root<TN>::print()
{
	root <TN> * head_ptr = new root<TN>;
	root <TN> * tmp = new root<TN>;
	head_ptr = this;
	while (head_ptr->down != NULL)
	{
		std::cout << head_ptr->element;
		tmp = head_ptr;
		while (tmp->right != NULL)
		{
			tmp = tmp->right;
			std::cout << " - " << tmp->element;
		}
		std::cout << std::endl << " |" << std::endl;
		head_ptr = head_ptr->down;
		
	}
	std::cout << head_ptr->element;
	tmp = head_ptr;
	while (tmp->right != NULL)
	{
		tmp = tmp->right;
		std::cout << " - " << tmp->element;
	}
}

 