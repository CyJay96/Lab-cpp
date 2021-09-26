#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

struct Node {
	double number;
	Node* next;
	Node* pred;
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

void add(Node*& top, Node*& end, double number);
void input(Node*& top, Node*& end, int n);
void del(Node*& top, Node*& end, double number);

void outputStart(Node* top);
void outputEnd(Node* end);

double solve(Node* top, Node* end);