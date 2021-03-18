#include "Number.h"

Number::Number() {
	int n = 100;
	this->setSize(n);
	this->arr = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); ++i) {
		this->arr[i] = 0;
	}
}

Number::Number(int size) {
	size < 0 ? this->size = 0 : this->size = size;
	this->arr = new int[size];
	for (int i = 0; i < size; ++i) {
		this->arr[i] = 0;
	}
}

Number::Number(const Number& obj) {
	this->size = obj.size;
	this->arr = new int[this->getSize()];
	for (int i = 0; i < this->getSize(); ++i) {
		this->arr[i] = obj.arr[i];
	}
}

Number::~Number() {
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
	}
}

istream& operator >> (istream& stream, Number& obj) {
	int number = 0;
	int numberInvert = 0;
	stream >> number;

	obj.setDigits(number);

	for (int i = 0; i < obj.getSize(); ++i) {
		numberInvert *= 10;
		numberInvert += number % 10;
		number /= 10;
	}

	for (int i = 0; i < obj.getSize(); ++i) {
		obj.arr[i] = numberInvert % 10;
		numberInvert /= 10;
	}

	return stream;
}

ostream& operator << (ostream& stream, const Number& obj) {
	for (int i = 0; i < obj.getSize(); ++i) {
		stream << obj.arr[i];
	}

	return stream;
}

int& Number::operator [] (int index) {
	if (index >= 0 && index < this->getSize()) {
		return this->arr[index];
	}
	else {
		cout << "Going out of the array" << endl;
		exit(0);
	}
}

int& Number::operator [] (int index) const {
	if (index >= 0 && index < this->getSize()) {
		return this->arr[index];
	}
	else {
		cout << "Going out of the array" << endl;
		exit(0);
	}
}

void Number::setDigits(int number) {
	int k = 0;
	while (number) {
		number /= 10;
		k++;
	}

	this->setSize(k);
}

void Number::setSize(int size) {
	this->size = size;
}

int Number::getSize() const {
	return this->size;
}