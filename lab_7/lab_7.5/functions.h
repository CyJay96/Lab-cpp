#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

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

void input(char* list, int* p, int n);
void output(char* list, int* p);

bool repeat(char* list1, char* list2, int* p1, int* p2, char symbol);
void createList(char* list1, char* list2, int* p1, int* p2);