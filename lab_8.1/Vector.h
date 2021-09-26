#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;

class Vector {
private:
	int size;
	int* arr;

public:
	Vector();
	Vector(int size);
	Vector(const Vector& obj);

	~Vector();

	friend istream& operator >> (istream& file, Vector& obj);
	friend ostream& operator << (ostream& file, const Vector& obj);

	int& operator [] (int index);
	int& operator [] (int index) const;

	void setSize(int size);
	int getSize() const;

	void fillRandom(int range);
};

int createResultSize(const Vector& sort_array, int N);
void createResult(Vector& result, const Vector& sort_array, int N);

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