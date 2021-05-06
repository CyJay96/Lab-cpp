#pragma once
#include <iostream>
#include <map>
#include "Stone.h"
#include "Chest.h"
#include "Merchant.h"
#include "Civilian.h"
#include "Player.h"
#include "ObjectFactory.h"

class List {
private:
	class Node {
	public:
		GameObject* data;
		Node* next;

		Node(GameObject* data, Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	int size;
	Node* head;

	map<string, int> types;

public:
	List();
	List(int size, GameObject* data);
	List(const List& list);
	List(List&& list);

	~List();

	GameObject*& operator[](int index);
	GameObject*& operator[](int index) const;
	List& operator=(const List& list);
	List& operator=(List&& list);

	void input(int size);
	void read(istream& in);

	void push_front(GameObject* data);
	void push_back(GameObject* data);
	List::Node* search_data(GameObject* data);
	List::Node* search_index(int index);
	void insert(GameObject* data, int index);
	void remove(GameObject* data);
	void removeAt(int index);
	void pop_front();
	void pop_back();
	void clear();
	void output(ostream& out);
	int getSize() const;
};

List::List() {
	size = 0;
	head = nullptr;

	int i = 1;
	types.try_emplace(STONE, STONE_ID);
	types.try_emplace(CHEST, CHEST_ID);
	types.try_emplace(MERCHANT, MERCHANT_ID);
	types.try_emplace(CIVILIAN, CIVILIAN_ID);
	types.try_emplace(PLAYER, PLAYER_ID);
}

List::List(int size, GameObject* data) {
	for (int i = 0; i < size; ++i) {
		push_back(data);
	}

	int i = 1;
	types.try_emplace(STONE, STONE_ID);
	types.try_emplace(CHEST, CHEST_ID);
	types.try_emplace(MERCHANT, MERCHANT_ID);
	types.try_emplace(CIVILIAN, CIVILIAN_ID);
	types.try_emplace(PLAYER, PLAYER_ID);
}

List::List(const List& list) {
	Node* current = list.head;
	while (current) {
		push_back(current->data);
		current = current->next;
	}
}

List::List(List&& list) {
	Node* current = list.head;
	while (current) {
		push_back(current->data);
		current = current->next;
	}
	list.clear();
}

List::~List() {
	clear();
}

GameObject*& List::operator[](int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	int pos = 0;
	Node* current = head;
	while (current && pos++ != index) {
		current = current->next;
	}

	return current->data;
}

GameObject*& List::operator[](int index) const {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(1);
	}

	int pos = 0;
	Node* current = head;
	while (current && pos++ != index) {
		current = current->next;
	}

	return current->data;
}

List& List::operator=(const List& list) {
	if (&list == this) {
		return *this;
	}

	clear();
	Node* current = list.head;
	while (current) {
		push_back(current->data);
		current = current->next;
	}

	return *this;
}

List& List::operator=(List&& list) {
	if (&list == this) {
		return *this;
	}

	clear();
	Node* current = list.head;
	while (current) {
		push_back(current->data);
		current = current->next;
	}
	list.clear();

	return *this;
}

void List::input(int size) {
	for (int i = 0; i < size; ++i) {
		cout << "Enter the type of the object " << i + 1 << ":" << endl;
		cout << " " << STONE_ID << ". " << STONE << endl;
		cout << " " << CHEST_ID << ". " << CHEST << endl;
		cout << " " << MERCHANT_ID << ". " << MERCHANT << endl;
		cout << " " << CIVILIAN_ID << ". " << CIVILIAN << endl;
		cout << " " << PLAYER_ID << ". " << PLAYER << endl;

		int option = 0;
		cin >> option;

		ObjectFactory factory;

		switch (option) {
		case STONE_ID:
			push_back(factory.create(STONE));
			break;
		case CHEST_ID:
			push_back(factory.create(CHEST));
			break;
		case MERCHANT_ID:
			push_back(factory.create(MERCHANT));
			break;
		case CIVILIAN_ID:
			push_back(factory.create(CIVILIAN));
			break;
		case PLAYER_ID:
			push_back(factory.create(PLAYER));
			break;
		default:
			break;
		}
		Node* current = search_index(this->size - 1);
		current->data->input();
		cout << endl;
	}
}

void List::read(istream& in) {
	while (!in.eof()) {
		string currentLine;
		currentLine.clear();

		getline(in, currentLine);

		if (currentLine.empty()) {
			continue;
		}

		ObjectFactory factory;

		map<string, int>::iterator it = types.find(currentLine);
		if (it != types.end()) {
			switch (it->second) {
			case STONE_ID:
				push_back(factory.create(STONE));
				break;
			case CHEST_ID:
				push_back(factory.create(CHEST));
				break;
			case MERCHANT_ID:
				push_back(factory.create(MERCHANT));
				break;
			case CIVILIAN_ID:
				push_back(factory.create(CIVILIAN));
				break;
			case PLAYER_ID:
				push_back(factory.create(PLAYER));
				break;
			default:
				break;
			}
			Node* current = search_index(size - 1);
			current->data->read(in);
		}
	}
}

void List::push_front(GameObject* data) {
	head = new Node(data, head);
	size++;
}

void List::push_back(GameObject* data) {
	if (!head) {
		head = new Node(data);
	}
	else {
		Node* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = new Node(data);
	}

	size++;
}

List::Node* List::search_data(GameObject* data) {
	Node* current = head;
	while (current) {
		if (current->data == data) {
			return current;
		}
		current = current->next;
	}

	return nullptr;
}

List::Node* List::search_index(int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(2);
	}

	Node* current = head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}

	return current;
}

void List::insert(GameObject* data, int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(3);
	}

	if (!index) {
		push_front(data);
	}
	else {
		Node* pred = search_index(index - 1);
		pred->next = new Node(data, pred->next);

		size++;
	}
}

void List::remove(GameObject* data) {
	Node* toDelete = search_data(data);

	Node* pred = head;
	while (pred && pred->next->data != toDelete->data) {
		pred = pred->next;
	}

	pred->next = toDelete->next;
	delete toDelete;

	size--;
}

void List::removeAt(int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(4);
	}

	if (!index) {
		pop_front();
	}
	else {
		Node* pred = search_index(index - 1);

		Node* toDelete = pred->next;
		pred->next = toDelete->next;

		delete toDelete;

		size--;
	}
}

void List::pop_front() {
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void List::pop_back() {
	removeAt(size - 1);
}

void List::clear() {
	while (size) {
		pop_front();
	}
}

void List::output(ostream& out) {
	Node* current = head;
	while (current) {
		out << *current->data << endl;
		current = current->next;
	}
	out << endl;
}

int List::getSize() const {
	return size;
}