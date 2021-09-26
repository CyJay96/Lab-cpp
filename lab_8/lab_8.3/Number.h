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

class Number {
private:
	static const int size = 64;
	bool num[size];

	friend istream& operator>>(istream& out, Number& number);
	friend ostream& operator<<(ostream& out, const Number& number);

public:
	Number();
	Number(long long decData);
	Number(string binData);
	Number(const Number& number);

	~Number();

	bool& operator[](int index);
	bool operator[](int index) const;

	Number& operator=(const Number& number);
	Number& operator=(long long decData);
	Number& operator=(string binData);

	Number operator+(const Number& number);
	Number operator*(const Number& number);
	Number operator^(const Number& power);
	Number operator^(int power);

	Number& operator+=(const Number& number);
	Number& operator*=(const Number& number);
	Number& operator^=(const Number& power);
	Number& operator^=(int power);

	void decToBin(long long data);
	long long binToDec() const;

	void printBinary();
	void reverse();
	Number shift(int k);
	void clear();
};