#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
class NodeList {
public:
	T data;
	NodeList* next;

	NodeList(T data = T(), NodeList* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

template <class T>
class List {
public:
	int size;
	NodeList<T>* head;

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
	bool isExist(T data);
	NodeList<T>* search_data(T data);
	NodeList<T>* search_index(int index);
	void insert(T data, int index);
	void remove(T data);
	void removeAt(int index);
	void pop_front();
	void pop_back();
	void clear();
	void output();
	int getSize() const;
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
	NodeList<T>* current = list.head;
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
	NodeList<T>* current = this->head;
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
	NodeList<T>* current = this->head;
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

		NodeList<T>* current = list.head;
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
	head = new NodeList<T>(data, head);
	size++;
}

template <class T>
void List<T>::push_back(T data) {
	if (!head) {
		head = new NodeList<T>(data);
	}
	else {
		NodeList<T>* current = this->head;
		while (current->next) {
			current = current->next;
		}
		current->next = new NodeList<T>(data);
	}

	size++;
}

template <class T>
bool List<T>::isExist(T data) {
	NodeList<T>* current = head;
	while (current) {
		if (current->data == data) {
			return true;
		}
		current = current->next;
	}

	return false;
}

template <class T>
NodeList<T>* List<T>::search_data(T data) {
	NodeList<T>* current = head;
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
NodeList<T>* List<T>::search_index(int index) {
	if (index < 0 || index >= this->size) {
		cerr << "Index out of range" << endl;
		exit(0);
	}

	NodeList<T>* current = head;
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
		NodeList<T>* pred = search_index(index - 1);
		pred->next = new NodeList<T>(data, pred->next);

		size++;
	}
}

template <class T>
void List<T>::remove(T data) {
	if (!head) {
		return;
	}

	NodeList<T>* current = head;
	NodeList<T>* pred = head;
	while (current && current->data != data) {
		pred = current;
		current = current->next;
	}

	if (pred == head && head->data == data) {
		head = head->next;
		delete pred;
		size--;
		return;
	}

	current = pred->next;
	if (!current) {
		return;
	}

	pred->next = current->next;
	delete current;
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
		NodeList<T>* pred = search_index(index - 1);

		NodeList<T>* toDelete = pred->next;
		pred->next = toDelete->next;

		delete toDelete;

		size--;
	}
}

template <class T>
void List<T>::pop_front() {
	NodeList<T>* temp = head;
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
	NodeList<T>* current = head;
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