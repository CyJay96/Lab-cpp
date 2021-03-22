#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
void enter(istream& in, T& data) {
	while (true) {
		in >> data;

		if (in.fail()) {
			in.clear();
			in.ignore(INT_MAX, '\n');

			cout << "An incorrect value. Please try again:" << endl;

			continue;
		}
		else {
			break;
		}
	}
}

template <class T>
class List {
private:
	template <class T>
	class Node {
	public:
		T data;
		Node* next;

		Node(T data = T(), Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	int size;
	Node<T>* head;
	
public:
	List();
	List(int size, T data);
	List(const List<T>& list);

	~List();

	T& operator[](int index);
	T& operator[](int index) const;
	List<T>& operator=(const List<T>& list);

	void input(int n);
	void push_front(T data);
	void push_back(T data);
	List<T>::Node<T>* search_data(T data);
	List<T>::Node<T>* search_index(int index);
	void insert(T data, int index);
	void remove(T data);
	void removeAt(int index);
	void pop_front();
	void pop_back();
	void clear();
	void output();
	int getSize() const;

	bool repeat(Node<T>* current, Node<T>* this_head);
	void createList(List<T>& list);
};

template <class T>
List<T>::List() {
	this->size = 0;
	this->head = nullptr;
}

template <class T>
List<T>::List(int size, T data) {
	for (int i = 0; i < size; ++i) {
		push_back(data);
	}
}

template <class T>
List<T>::List(const List<T>& list) {
	Node<T>* current = list.head;
	while (current) {
		push_back(current->data);
		current = current->next;
	}
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
T& List<T>::operator[](int index) {
	if (index < 0 || index >= this->size) {
		cerr << "Index out of range" << endl;
		exit(0);
	}

	int k = 0;
	Node<T>* current = this->head;
	while (current) {
		if (k == index) {
			return current->data;
		}
		current = current->next;
		k++;
	}

	cerr << "The specified element wasn't found" << endl;
	exit(0);
}

template <class T>
T& List<T>::operator[](int index) const {
	if (index < 0 || index >= this->size) {
		cerr << "Index out of range" << endl;
		exit(0);
	}

	int k = 0;
	Node<T>* current = this->head;
	while (current) {
		if (k == index) {
			return current->data;
		}
		current = current->next;
		k++;
	}

	cerr << "The specified element wasn't found" << endl;
	exit(0);
}

template <class T>
List<T>& List<T>::operator=(const List<T>& list) {
	if (&list != this) {
		clear();

		Node<T>* current = list.head;
		while (current) {
			push_back(current->data);
			current = current->next;
		}
	}

	return *this;
}

template <class T>
void List<T>::input(int n) {
	for (int i = 0; i < n; ++i) {
		T data;
		enter(cin, data);
		push_back(data);
	}
}

template <class T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	size++;
}

template <class T>
void List<T>::push_back(T data) {
	if (!head) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->next) {
			current = current->next;
		}
		current->next = new Node<T>(data);
	}

	size++;
}

template <class T>
List<T>::Node<T>* List<T>::search_data(T data) {
	Node<T>* current = head;
	while (current) {
		if (current->data == data) {
			return current;
		}
		current = current->next;
	}

	cerr << "The specified element wasn't found" << endl;
	exit(0);
}

template <class T>
List<T>::Node<T>* List<T>::search_index(int index) {
	if (index < 0 || index >= this->size) {
		cerr << "Index out of range" << endl;
		exit(0);
	}

	Node<T>* current = head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}

	return current;
}

template <class T>
void List<T>::insert(T data, int index) {
	if (index < 0 || index >= this->size) {
		cerr << "Index out of range" << endl;
		exit(0);
	}

	if (!index) {
		push_front(data);
	}
	else {
		Node<T>* pred = search_index(index - 1);
		pred->next = new Node<T>(data, pred->next);

		size++;
	}
}

template <class T>
void List<T>::remove(T data) {
	Node<T>* toDelete = search_data(data);

	Node<T>* pred = head;
	while (pred && pred->next->data != toDelete->data) {
		pred = pred->next;
	}

	pred->next = toDelete->next;
	delete toDelete;

	size--;
}

template <class T>
void List<T>::removeAt(int index) {
	if (index < 0 || index >= this->size) {
		cerr << "Index out of range" << endl;
		exit(0);
	}

	if (!index) {
		pop_front();
	}
	else {
		Node<T>* pred = search_index(index - 1);

		Node<T>* toDelete = pred->next;
		pred->next = toDelete->next;

		delete toDelete;

		size--;
	}
}

template <class T>
void List<T>::pop_front() {
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}

template <class T>
void List<T>::pop_back() {
	removeAt(size - 1);
}

template <class T>
void List<T>::clear() {
	while (size) {
		pop_front();
	}
}

template <class T>
void List<T>::output() {
	Node<T>* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template <class T>
int List<T>::getSize() const {
	return this->size;
}

template <class T>
bool List<T>::repeat(Node<T>* current, Node<T>* this_head) {
	bool flag = true;

	int k = 0;

	Node<T>* top = current;
	while (top && k < 2) {
		if (current->data == top->data) {
			k++;
		}
		top = top->next;
	}

	if (k == 1) {
		flag = false;
	}
	else {
		while (this_head) {
			if (current->data == this_head->data) {
				flag = false;
				break;
			}
			this_head = this_head->next;
		}
	}

	return flag;
}

template <class T>
void List<T>::createList(List<T>& list) {
	Node<T>* current = list.head;
	for (int i = 0; i < list.size; ++i) {
		if (repeat(current, this->head)) {
			push_back(current->data);
		}
		current = current->next;
	}
}
