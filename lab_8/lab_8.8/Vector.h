#pragma once
#include <iostream>

using namespace std;

template <class T>
void enter(istream& in, T& a) {
	while (true) {
		in >> a;

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
	friend istream& operator>>(istream& file, Vector<T>& vctr);
	template <class T>
	friend ostream& operator<<(ostream& file, const Vector<T>& vctr);

public:
	Vector();
	Vector(int size, T data);
	Vector(const Vector<T>& vctr);

	~Vector();

	T& operator[](int index);
	T& operator[](int index) const;
	Vector<T>& operator=(const Vector& vctr);

	void setSize(int size, T data);
	int getSize() const;
	void push_back(T data);
	void pushAt(int index, T data);
	void deleteAt(int index);
	void clear();
};

template <class T>
Vector<T>::Vector() {
	size = 0;
	arr = nullptr;
}

template <class T>
Vector<T>::Vector(int size, T data) {
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
	arr = new T[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = data;
	}
}

template <class T>
Vector<T>::Vector(const Vector<T>& vctr) {
	size = vctr.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = vctr.arr[i];
	}
}

template <class T>
Vector<T>::~Vector() {
	clear();
}

template <class T>
istream& operator>>(istream& in, Vector<T>& vctr) {
	for (int i = 0; i < vctr.size; ++i) {
		enter(in, vctr.arr[i]);
	}

	return in;
}

template <class T>
ostream& operator<<(ostream& out, const Vector<T>& vctr) {
	for (int i = 0; i < vctr.size; ++i) {
		out << vctr.arr[i] << " ";
	}

	return out;
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
		exit(0);
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
		exit(0);
	}

	return arr[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& vctr) {
	if (this == &vctr) {
		return *this;
	}

	size = vctr.size;
	delete[] arr;
	arr = new T[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = vctr.arr[i];
	}

	return *this;
}

template <class T>
void Vector<T>::push_back(T data) {
	setSize(size + 1);
	arr[size - 1] = data;
}

template <class T>
void Vector<T>::pushAt(int index, T data) {
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
	arr[index] = data;
}

template <class T>
void Vector<T>::deleteAt(int index) {
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

template <class T>
void Vector<T>::clear() {
	if (arr) {
		size = 0;
		delete[] arr;
		arr = nullptr;
	}
}

template <class T>
void Vector<T>::setSize(int size, T data) {
	try {
		if (size < 0) {
			throw size;
		}
	}
	catch (int) {
		cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	T* newVector = new T[size];
	for (int i = 0; i < size; ++i) {
		if (i < this->size) {
			newVector[i] = arr[i];
		}
		else {
			newVector[i] = data;
		}
	}

	this->size = size;
	delete[] arr;
	arr = newVector;
}

template <class T>
int Vector<T>::getSize() const {
	return this->size;
}
