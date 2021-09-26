#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

enum options {
	one = 1,
	two = 2,

	widthLine = 35,
};

void draw_line(int n) {
	for (int i = 0; i < n; ++i) {
		cout << "-";
	}
	cout << endl;
}

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

template <class Type>
void rand_mas(Type* a, int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = (rand() % 100) * 1.1;
	}
}

void rand_mas(char* a, int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = 65 + rand() % 26;
	}
}

template <class Type>
void input_mas(Type* a, int n) {
	for (int i = 0; i < n; ++i) {
		input(a[i]);
	}
}

template <class Type>
void output_mas(Type* a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
}

void output_c_mas(char* a, int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i];
	}
	cout << " ";
}