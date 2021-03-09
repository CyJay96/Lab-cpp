#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

struct Vertexes {
	int numVer;
	Vertexes* next;
};

struct Graf {
	int numVer;
	Graf* next;

	Vertexes* listAdVer;
};

const int MAX_SIZE = 65000;

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