#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
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

void create_numbers(ofstream& file, int n);
void unsigned_sort(ifstream& file1, ofstream& file2, int n);