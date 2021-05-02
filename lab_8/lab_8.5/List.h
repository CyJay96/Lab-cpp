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
		Node* pred;

		Node(T data = T(), Node* next = nullptr, Node* pred = nullptr) {
			this->data = data;
			this->next = next;
			this->pred = pred;
		}
	};

	int size;
	Node<T>* head;
	Node<T>* end;

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
	void output_start();
	void output_end();
	int getSize() const;

	double solve();
};

template <class T>
List<T>::List() {
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
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


	if (index < size / 2) {
		int k = 0;
		Node<T>* current = this->head;
		while (current) {
			if (k == index) {
				return current->data;
			}
			current = current->next;
			k++;
		}
	}
	else {
		int k = 0;
		Node<T>* current = this->end;
		while (current) {
			if (k == index) {
				return current->data;
			}
			current = current->pred;
			k++;
		}
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

	if (index < size / 2) {
		int k = 0;
		Node<T>* current = this->head;
		while (current) {
			if (k == index) {
				return current->data;
			}
			current = current->next;
			k++;
		}
	}
	else {
		int k = 0;
		Node<T>* current = this->end;
		while (current) {
			if (k == index) {
				return current->data;
			}
			current = current->pred;
			k++;
		}
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
	if (!size) {
		head = new Node<T>(data, head);
		end = head;
	}
	else {
		head = new Node<T>(data, head);
		Node<T>* next = head->next;
		next->pred = head;
	}

	size++;
}

template <class T>
void List<T>::push_back(T data) {
	if (!size) {
		head = new Node<T>(data);
		end = head;
	}
	else {
		Node<T>* current = end;
		current->next = new Node<T>(data, nullptr, current);
		end = current->next;
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
		Node<T>* next = pred->next;

		pred->next = new Node<T>(data, pred->next, next->pred);
		next->pred = pred->next;

		size++;
	}
}

template <class T>
void List<T>::remove(T data) {
	Node<T>* toDelete = search_data(data);

	toDelete->pred->next = toDelete->next;
	toDelete->next->pred = toDelete->pred;
	delete toDelete;

	size--;
}

template <class T>
void List<T>::removeAt(int index) {
	if (index < 0 || index >= this->size) {
		cerr << "Going out of the array" << endl;
		exit(0);
	}

	if (!index) {
		pop_front();
	}
	else if (index == size - 1) {
		pop_back();
	}
	else {
		Node<T>* pred = search_index(index - 1);
		Node<T>* toDelete = pred->next;
		Node<T>* next = toDelete->next;

		pred->next = toDelete->next;
		next->pred = toDelete->pred;

		delete toDelete;

		size--;
	}
}

template <class T>
void List<T>::pop_front() {
	Node<T>* temp = head;
	head = head->next;
	if (!head) {
		end = nullptr;
	}
	if (head) {
		head->pred = nullptr;
	}
	delete temp;
	size--;
}

template <class T>
void List<T>::pop_back() {
	Node<T>* temp = end;
	end = end->pred;
	if (!end) {
		head = nullptr;
	}
	if (end) {
		end->next = nullptr;
	}
	delete temp;
	size--;
}

template <class T>
void List<T>::clear() {
	while (size) {
		pop_front();
	}
}

template <class T>
void List<T>::output_start() {
	Node<T>* current = head;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template <class T>
void List<T>::output_end() {
	Node<T>* current = end;
	while (current) {
		cout << current->data << " ";
		current = current->pred;
	}
	cout << endl;
}

template <class T>
int List<T>::getSize() const {
	return this->size;
}

template <class T>
double List<T>::solve() {
	double res = 1;

	Node<T>* temp_head = head;
	Node<T>* temp_end = end;

	while (temp_head && temp_end) {
		res *= temp_head->data + temp_end->data;

		temp_head = temp_head->next;
		temp_end = temp_end->pred;
	}

	return res;
}
