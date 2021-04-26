#pragma once
#include "GameObject.h"
#include "Stone.h"
#include "Chest.h"
#include "Civilian.h"
#include "Merchant.h"
#include "Player.h"

class Vector {
private:
	int size;
	GameObject** arr;

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
		cout << " 1. Stone" << endl;
		cout << " 2. Chest" << endl;
		cout << " 3. Civilian" << endl;
		cout << " 4. Merchant" << endl;
		cout << " 5. Player" << endl;

		int x = 0, y = 0;
		unsigned int width = 0, height = 0;
		unsigned int id = 0, coinsNum = 0, codeType = 0;
		char name[100] = { 0 };
		char colorClothes[100] = { 0 };

		int option = 0;
		cin >> option;

		cout << "Enter coordinates:" << endl;
		cout << "X = "; cin >> x;
		cout << "Y = "; cin >> y;

		switch (option) {
		case 1:
			cout << "Enter the width: "; cin >> width;
			cout << "Enter the height: "; cin >> height;
			cout << "Enter the ID: "; cin >> id;
			arr[i] = new Stone(x, y, width, height, id);
			break;
		case 2:
			cout << "Enter the width: "; cin >> width;
			cout << "Enter the height: "; cin >> height;
			cout << "Enter number of coins: "; cin >> coinsNum;
			arr[i] = new Chest(x, y, width, height, coinsNum);
			break;
		case 3:
			cout << "Enter the name: "; cin >> name;
			arr[i] = new Civilian(x, y, name);
			break;
		case 4:
			cout << "Enter the name: "; cin >> name;
			cout << "Enter code of type: "; cin >> codeType;
			arr[i] = new Merchant(x, y, name, codeType);
			break;
		case 5:
			cout << "Enter the name: "; cin >> name;
			cout << "Enter the color of clothes: "; cin >> colorClothes;
			arr[i] = new Player(x, y, name, colorClothes);
			break;
		default:
			break;
		}
		cout << endl;
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