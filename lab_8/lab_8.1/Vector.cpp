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
	this->setSize(size);
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

int& Vector::operator [] (int index) {
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

int Vector::getSize() {
	return this->size;
}

void Vector::fillRandom(int range) {
	for (int i = 0; i < this->getSize(); ++i) {
		this->arr[i] = 1 + rand() % range;
	}
}