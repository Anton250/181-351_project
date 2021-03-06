#include "pch.h"
#include <iostream>
template<typename T>
class tree {
	tree * up;
	tree * down;
	tree * right;
	tree * left;
	T element;
	int count_of_sons, count_of_brothers;
	int count_of_element[2], element_number[2];


	tree();
	tree(T elem);
	~tree();
	int add_son(T new_elem, int son, int broth);
	int add_brother(T new_elem);
	int go_up();
	int go_down();
	int go_right();
	int go_left();
	int print();
	
};

int main()
{
   
}

template<typename T>
tree<T>::tree()
{
	right = NULL;
	up = NULL;
	down = NULL;
	left = NULL;
	count_of_sons = 0;
	count_of_brothers = 0;

}

template<typename T>
tree<T>::tree(T elem)
{
	right = NULL;
	up = NULL;
	down = NULL;
	left = NULL;
	count_of_sons = 0;
	count_of_brothers = 0;
	element = elem;
}

template<typename T>
tree<T>::~tree()
{
	if (down != NULL) {
		delete down;
	}
	if (up != NULL) {
		delete up;
	}
	if (right != NULL) {
		delete right;
	}
	if (left != NULL) {
		delete left;
	}
}

template<typename T>
int tree<T>::add_son(T new_elem, int son, int broth)
{
	tree<T> * header = new tree<T>;
	header = this;
	if (son < count_of_sons || broth < count_of_brothers) {
		std::cout << "Failed to add.\n";
		return 0;
	}
	for (int i = 0; i < son; i++) {
		header = header->down;
	}
	for (int i = 0; i < broth; i++) {
		header = header->right;
	}
	header->count_of_sons++;


}
