#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
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
class Vector {
private:
	int size;
	T* arr;

	template <class T>
	friend istream& operator>>(istream& in, Vector<T>& obj);
	template <class T>
	friend ostream& operator<<(ostream& out, const Vector<T>& obj);

public:
	Vector();
	Vector(int size);
	Vector(const Vector& obj);

	~Vector();

	T& operator[](int index);
	T& operator[](int index) const;
	Vector<T>& operator=(const Vector& obj);

	void push_back(T data);
	void pushAt(int index, T data);
	void deleteAt(int index);
	void clear();
	void setSize(int size);
	int getSize() const;

	void fillRandom(T min, T max);
};

template <class T>
Vector<T>::Vector() {
	int size = 0;
	setSize(size);
}

template <class T>
Vector<T>::Vector(int size) {
	size < 0 ? size = 0, this->size = size : this->size = size;
	arr = new T[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = 0;
	}
}

template <class T>
Vector<T>::Vector(const Vector& obj) {
	size = obj.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = obj.arr[i];
	}
}

template <class T>
Vector<T>::~Vector() {
	clear();
}

template <class T>
T& Vector<T>::operator[](int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(900);
	}

	return arr[index];
}

template <class T>
T& Vector<T>::operator[](int index) const {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(900);
	}

	return arr[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& obj) {
	if (this != &obj) {
		delete[] arr;
		size = obj.size;
		arr = new T[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = obj.arr[i];
		}
	}

	return *this;
}

template <class T>
istream& operator>>(istream& in, Vector<T>& obj) {
	for (int i = 0; i < obj.size; ++i) {
		enter(in, obj.arr[i]);
	}

	return in;
}

template <class T>
ostream& operator<<(ostream& out, const Vector<T>& obj) {
	for (int i = 0; i < obj.size; ++i) {
		out << obj.arr[i] << " ";
	}

	return out;
}

template <class T>
void Vector<T>::push_back(T data) {
	setSize(size + 1);
	arr[size - 1] = data;
}

template <class T>
void Vector<T>::pushAt(int index, T data) {
	setSize(size + 1);
	for (int i = size - 1; i > index; --i) {
		arr[i] = arr[i - 1];
	}
	arr[index] = data;
}

template <class T>
void Vector<T>::deleteAt(int index) {
	for (int i = index; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	setSize(size - 1);
}

template <class T>
void Vector<T>::clear() {
	if (arr) {
		size = 0;
		delete[] arr;
		arr = nullptr;
	}
}

template <class T>
void Vector<T>::setSize(int size) {
	size < 0 ? size = 0 : true;

	int oldSize = 0;
	T* buf = nullptr;

	if (this->size) {
		oldSize = this->size;
		buf = new T[oldSize];
		for (int i = 0; i < oldSize; ++i) {
			buf[i] = arr[i];
		}
	}

	if (arr) {
		delete[] arr;
		arr = nullptr;
	}

	arr = new T[size];
	this->size = size;
	for (int i = 0; i < size; ++i) {
		arr[i] = 0;
	}

	if (buf) {
		int min_size = (oldSize < size ? oldSize : size);
		for (int i = 0; i < min_size; ++i) {
			arr[i] = buf[i];
		}
	}

	delete[] buf;
}

template <class T>
int Vector<T>::getSize() const {
	return this->size;
}

template <class T>
void Vector<T>::fillRandom(T min, T max) {
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < size; ++i) {
		arr[i] = min + rand() % (max - min + 1);
	}
}