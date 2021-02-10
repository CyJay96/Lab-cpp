#pragma once
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

template <class Type>
void input(Type& a) {
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

bool search_char(string str, char ch);
bool search_str(string s1, string s2);

string roman(int n);
string hex_to_bin(string num16);
string word_selection(string str);