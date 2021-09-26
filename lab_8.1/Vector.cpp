#include "Vector.h"

Vector::Vector() {
	int n = 100;
	this->setSize(n);
	this->arr = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); ++i) {
		this->arr[i] = 0;
	}
}

Vector::Vector(int size) {
	size < 0 ? this->size = 0 : this->size = size;
	this->arr = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); ++i) {
		this->arr[i] = 0;
	}
}

Vector::Vector(const Vector& obj) {
	this->size = obj.size;
	this->arr = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); ++i) {
		this->arr[i] = obj.arr[i];
	}
}

Vector::~Vector() {
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
	}
}

istream& operator >> (istream& file, Vector& obj) {
	while (!file.eof()) {
		int number = 0;
		enter(file, number);
		obj.arr[number]++;
	}

	return file;
}

ostream& operator << (ostream& file, const Vector& obj) {
	for (int i = 0; i < obj.getSize(); ++i) {
		file << obj.arr[i] << endl;
	}

	return file;
}

int& Vector::operator [] (int index) {
	if (index >= 0 && index < this->getSize()) {
		return this->arr[index];
	}
	else {
		cout << "Going out of the array" << endl;
		exit(0);
	}
}

int& Vector::operator [] (int index) const {
	if (index >= 0 && index < this->getSize()) {
		return this->arr[index];
	}
	else {
		cout << "Going out of the array" << endl;
		exit(0);
	}
}

void Vector::setSize(int size) {
	this->size = size;
}

int Vector::getSize() const {
	return this->size;
}

void Vector::fillRandom(int range) {
	for (int i = 0; i < this->getSize(); ++i) {
		this->arr[i] = 1 + rand() % range;
	}
}

int createResultSize(const Vector& sort_array, int N) {
	int sizeRes = 0;
	for (int i = 0; i < N; ++i) {
		if (sort_array[i] != 0) {
			sizeRes++;
		}
	}

	return sizeRes;
}

void createResult(Vector& result, const Vector& sort_array, int N) {
	int k = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (sort_array[i] != 0) {
			result[k++] = i;
		}
	}
}