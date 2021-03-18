#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;

class Number {
private:
	int size;
	int* arr;

public:
	Number();
	Number(int size);
	Number(const Number& obj);

	~Number();

	friend istream& operator >> (istream& stream, Number& obj);
	friend ostream& operator << (ostream& stream, const Number& obj);

	int& operator [] (int index);
	int& operator [] (int index) const;

	void setDigits(int number);

	void setSize(int size);
	int getSize() const;
};

template <class Type>
void enter(istream& in, Type& a) {
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