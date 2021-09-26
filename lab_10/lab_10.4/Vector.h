#pragma once
#include <map>
#include "GameObject.h"
#include "Stone.h"
#include "Chest.h"
#include "Merchant.h"
#include "Civilian.h"
#include "Player.h"
#include "ObjectFactory.h"

class Vector {
private:
	int size;
	GameObject** arr;

	map<string, int> types;

	friend ostream& operator<<(ostream& file, const Vector& vctr);

public:
	Vector();
	Vector(int size);
	Vector(const Vector& vctr);
	Vector(Vector&& vctr);

	~Vector();

	GameObject*& operator[](int index);
	GameObject*& operator[](int index) const;
	Vector& operator=(const Vector& vctr);
	Vector& operator=(Vector&& vctr);

	void input(int size);
	void read(istream& in);

	void push_back(GameObject* data);
	void pushAt(int index, GameObject* obj);
	void deleteAt(int index);
	void clear();

	void setSize(int size);
	int getSize() const;
};

Vector::Vector() {
	size = 0;
	arr = new GameObject * [size];

	int i = 1;
	types.try_emplace(STONE, STONE_ID);
	types.try_emplace(CHEST, CHEST_ID);
	types.try_emplace(MERCHANT, MERCHANT_ID);
	types.try_emplace(CIVILIAN, CIVILIAN_ID);
	types.try_emplace(PLAYER, PLAYER_ID);
}

Vector::Vector(int size) {
	try {
		if (size < 0) {
			throw size;
		}
	}
	catch (int) {
		cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	this->size = size;
	arr = new GameObject * [size];
	for (int i = 0; i < size; ++i) {
		arr[i] = nullptr;
	}

	int i = 1;
	types.try_emplace(STONE, STONE_ID);
	types.try_emplace(CHEST, CHEST_ID);
	types.try_emplace(MERCHANT, MERCHANT_ID);
	types.try_emplace(CIVILIAN, CIVILIAN_ID);
	types.try_emplace(PLAYER, PLAYER_ID);
}

Vector::Vector(const Vector& vctr) {
	size = vctr.size;
	arr = new GameObject * [size];
	for (int i = 0; i < size; ++i) {
		arr[i] = vctr.arr[i];
	}
}

Vector::Vector(Vector&& vctr) {
	size = vctr.size;
	arr = new GameObject * [size];
	for (int i = 0; i < size; ++i) {
		arr[i] = vctr.arr[i];
	}
	vctr.size = 0;
	vctr.arr = nullptr;
}

Vector::~Vector() {
	clear();
}

ostream& operator<<(ostream& out, const Vector& vctr) {
	for (int i = 0; i < vctr.size; ++i) {
		if (vctr.arr[i]) {
			out << *vctr.arr[i] << endl;
		}
	}

	return out;
}

GameObject*& Vector::operator[](int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	return arr[index];
}

GameObject*& Vector::operator[](int index) const {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	return arr[index];
}

Vector& Vector::operator=(const Vector& vctr) {
	if (this == &vctr) {
		return *this;
	}

	clear();
	size = vctr.size;
	arr = new GameObject * [size];
	for (int i = 0; i < size; ++i) {
		arr[i] = vctr.arr[i];
	}

	return *this;
}

Vector& Vector::operator=(Vector&& vctr) {
	if (this == &vctr) {
		return *this;
	}

	swap(size, vctr.size);
	swap(arr, vctr.arr);

	return *this;
}

void Vector::input(int size) {
	setSize(size);
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
			arr[i] = factory.create(STONE);
			break;
		case CHEST_ID:
			arr[i] = factory.create(CHEST);
			break;
		case MERCHANT_ID:
			arr[i] = factory.create(MERCHANT);
			break;
		case CIVILIAN_ID:
			arr[i] = factory.create(CIVILIAN);
			break;
		case PLAYER_ID:
			arr[i] = factory.create(PLAYER);
			break;
		default:
			break;
		}
		arr[i]->input();
		cout << endl;
	}
}

void Vector::read(istream& in) {
	int size = 0;
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
				setSize(size + 1);
				arr[size] = factory.create(STONE);
				arr[size++]->read(in);
				break;
			case CHEST_ID:
				setSize(size + 1);
				arr[size] = factory.create(CHEST);
				arr[size++]->read(in);
				break;
			case MERCHANT_ID:
				setSize(size + 1);
				arr[size] = factory.create(MERCHANT);
				arr[size++]->read(in);
				break;
			case CIVILIAN_ID:
				setSize(size + 1);
				arr[size] = factory.create(CIVILIAN);
				arr[size++]->read(in);
				break;
			case PLAYER_ID:
				setSize(size + 1);
				arr[size] = factory.create(PLAYER);
				arr[size++]->read(in);
				break;
			default:
				break;
			}
		}
	}
}

void Vector::push_back(GameObject* obj) {
	setSize(size + 1);
	arr[size - 1] = obj;
}

void Vector::pushAt(int index, GameObject* obj) {
	try {
		if (index < 0 || index > size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	setSize(size + 1);
	if (index != size - 1) {
		for (int i = size - 1; i > index; --i) {
			arr[i] = arr[i - 1];
		}
	}
	arr[index] = obj;
}

void Vector::deleteAt(int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	for (int i = index; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	setSize(size - 1);
}

void Vector::clear() {
	if (arr) {
		size = 0;
		delete[] arr;
		arr = nullptr;
	}
}

void Vector::setSize(int size) {
	try {
		if (size < 0) {
			throw size;
		}
	}
	catch (int) {
		cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	GameObject** newArr = new GameObject * [size];
	for (int i = 0; i < size; ++i) {
		if (i < this->size) {
			newArr[i] = arr[i];
		}
		else {
			newArr[i] = nullptr;
		}
	}

	delete[] arr;
	this->size = size;
	arr = newArr;
}

int Vector::getSize() const {
	return size;
}