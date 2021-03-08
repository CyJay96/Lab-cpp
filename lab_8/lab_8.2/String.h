#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

class String {
private:
	int size;
	char* str;

public:
	String();
	String(int size);
	String(const String& obj);

	~String();

	void setSize(int size);
	int getSize();

	friend ostream& operator << (ostream& out, const String& obj);
	friend istream& operator >> (istream& in, String& obj);

	char& operator [] (int index);
	bool operator == (const String& obj);
	bool operator > (const String& obj);
	bool operator < (const String& obj);
	String& operator = (const String& obj);
	String operator + (const String& obj);
	void operator += (const String& obj);

	void delChar(const char ch);
	void deletingSymbols(const String& s);
};

template <class Type>
void enter(Type& a) {
	while (true) {
		cin >> a;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << "An incorrect value. Please try again:" << endl;

			continue;
		}
		else {
			break;
		}
	}
}