#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

struct Tree {
	int data;
	Tree* left;
	Tree* right;
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

Tree* find(Tree* top, int data);
void add(Tree*& top, int data);
void input(Tree*& top, int n);
void outputLeft(Tree* top);
void outputRight(Tree* top);
void delTree(Tree*& top);

int findLeaves(Tree* top);