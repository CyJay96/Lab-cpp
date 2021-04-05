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
	static const int bits = 64;
	bool sign;

	int size;
	int num[bits];

	friend istream& operator>>(istream& out, Number& number);
	friend ostream& operator<<(ostream& out, const Number& number);

public:
	Number();
	Number(int decData);
	Number(const Number& number);

	~Number();

	int& operator[](int index);
	int operator[](int index) const;

	Number& operator=(const Number& number);
	Number& operator=(int decData);

	Number operator+(const Number& number);
	Number operator*(const Number& number);
	Number operator^(const Number& power);
	Number operator^(int power);

	Number& operator+=(const Number& number);
	Number& operator*=(const Number& number);
	Number& operator^=(const Number& power);
	Number& operator^=(int power);

	bool operator==(const Number& number);
	bool operator==(int number);
	bool operator!=(const Number& number);
	bool operator!=(int number);

	void decToBin(int data);
	int binToDec() const;

	void printBinary();
	void reverse();
	Number shift(int k);
	void optimizeSize();

	void setSize(int binSize);
	int getSize(int data);
	int getSizeDec();
	int getSizeBin() const;
	bool getSign() const;
	void clear();
};
