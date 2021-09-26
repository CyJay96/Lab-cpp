#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include "List.h"

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
class Graf {
private:
	template <class T>
	class NodeGraf {
	public:
		T data;
		NodeGraf<T>* next;

		List<T> vertexes;

		NodeGraf(T data = T(), NodeGraf<T>* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	int size;
	NodeGraf<T>* head;

	void pop_front();

public:
	Graf();
	Graf(int size, T data);
	Graf(const Graf<T>& graf);

	~Graf();

	Graf<T>& operator=(const Graf<T>& graf);

	void addConnect(int size);
	void input(int size);
	void push(T data);
	void remove(T data);
	void clear();
	void output();
	int getSize() const;

	bool checkGraf(T ver1, T ver2);
	int searchWay(const List<T>& vertexes, T ver2);
	void oneToOther(T ver1, T ver2);
};

template <class T>
Graf<T>::Graf() {
	this->size = 0;
	this->head = nullptr;
}

template <class T>
Graf<T>::Graf(int size, T data) {
	this->size = 0;
	this->head = nullptr;

	for (int i = 0; i < size; ++i) {
		push(data);
	}

	addConnect(size);
}

template <class T>
Graf<T>::Graf(const Graf<T>& graf) {
	size = 0;
	head = nullptr;

	NodeGraf<T>* current = graf.head;
	while (current) {
		push(current->data);
		current = current->next;
	}

	addConnect(size);
}

template <class T>
Graf<T>::~Graf() {
	clear();
}

template <class T>
Graf<T>& Graf<T>::operator=(const Graf<T>& graf) {
	if (this != &graf) {
		clear();

		NodeGraf<T>* currentGraf = graf.head;
		NodeGraf<T>* currentThis = nullptr;

		while (currentGraf) {
			push(currentGraf->data);

			if (currentThis) {
				currentThis = currentThis->next;
			}
			else {
				currentThis = head;
			}

			if (&currentThis->vertexes != &currentGraf->vertexes) {
				NodeList<T>* currentList = currentGraf->vertexes.head;
				while (currentList) {
					currentThis->vertexes.push_back(currentList->data);
					currentList = currentList->next;
				}
			}

			currentGraf = currentGraf->next;
		}
	}

	return *this;
}

template <class T>
void Graf<T>::addConnect(int size) {
	srand(static_cast<unsigned int>(time(nullptr)));

	int k_min = 3;
	int k_max = 5;

	NodeGraf<T>* current = head;
	while (current) {
		int k_connect = k_min + rand() % k_max;

		for (int i = 0; i < k_connect; ++i) {
			int randNumGraf = rand() % size;
			NodeGraf<T>* randGraf = head;
			for (int j = 0; j < randNumGraf; ++j) {
				randGraf = randGraf->next;
			}

			if (!current->vertexes.isExist(randGraf->data)) {
				current->vertexes.push_back(randGraf->data);
			}
		}

		current = current->next;
	}
}

template <class T>
void Graf<T>::input(int size) {
	for (int i = 0; i < size; ++i) {
		T data;
		enter(cin, data);
		push(data);
	}

	addConnect(size);
}

template <class T>
void Graf<T>::push(T data) {
	if (!head) {
		head = new NodeGraf<T>(data);
	}
	else {
		NodeGraf<T>* current = this->head;
		while (current->next) {
			current = current->next;
		}
		current->next = new NodeGraf<T>(data);
	}

	size++;
}

template <class T>
void Graf<T>::remove(T data) {
	if (!head) {
		return;
	}

	NodeGraf<T>* inCurrent = head;
	while (inCurrent) {
		inCurrent->vertexes.remove(data);
		inCurrent = inCurrent->next;
	}

	NodeGraf<T>* current = head;
	NodeGraf<T>* pred = head;
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
void Graf<T>::pop_front() {
	NodeGraf<T>* temp = head;
	head = head->next;

	temp->vertexes.clear();
	delete temp;

	size--;
}

template <class T>
void Graf<T>::clear() {
	while (size) {
		pop_front();
	}
}

template <class T>
void Graf<T>::output() {
	NodeGraf<T>* current = head;
	while (current) {
		cout << current->data << ": ";
		current->vertexes.output();
		current = current->next;
	}
}

template <class T>
int Graf<T>::getSize() const {
	return this->size;
}

template <class T>
bool Graf<T>::checkGraf(T ver1, T ver2) {
	bool flag1 = true;
	NodeGraf<T>* graf1 = head;
	if (graf1) {
		while (graf1) {
			if (graf1->data == ver1) {
				break;
			}
			else if (graf1->data != ver1 && !graf1->next) {
				flag1 = false;
				cout << "The first entered graph wasn't found" << endl;
			}
			graf1 = graf1->next;
		}
	}
	else {
		flag1 = false;
		cout << "The first entered graph wasn't found" << endl;
	}

	bool flag2 = true;
	NodeGraf<T>* graf2 = head;
	if (graf2) {
		while (graf2) {
			if (graf2->data == ver2) {
				break;
			}
			else if (graf2->data != ver2 && !graf2->next) {
				flag2 = false;
				cout << "The second entered graph wasn't found" << endl;
			}
			graf2 = graf2->next;
		}
	}
	else {
		flag2 = false;
		cout << "The second entered graph wasn't found" << endl;
	}

	return flag1 && flag2;
}

template <class T>
int Graf<T>::searchWay(const List<T>& vertexes, T ver2) {
	NodeList<T>* current = vertexes.head;

	while (current) {
		if (current->data == ver2) {
			return current->data;
		}
		current = current->next;
	}

	current = vertexes.head;
	while (current) {
		NodeGraf<T>* findGraf = head;
		while (findGraf && findGraf->data != current->data) {
			findGraf = findGraf->next;
		}

		NodeList<T>* top = findGraf->vertexes.head;
		while (top) {
			if (top->data == ver2) {
				return top->data * 10 + findGraf->data;
			}
			top = top->next;
		}

		current = current->next;
	}

	cerr << "There is no connection" << endl;
	exit(0);
}

template <class T>
void Graf<T>::oneToOther(T ver1, T ver2) {
	NodeGraf<T>* graf1 = head;
	while (graf1) {
		if (graf1->data == ver1) {
			break;
		}
		graf1 = graf1->next;
	}

	int way = searchWay(graf1->vertexes, ver2);

	way = way * 10 + ver1;

	while (way / 10) {
		cout << way % 10;
		cout << " -> ";
		way /= 10;
	}
	cout << way % 10;
	cout << endl;
}