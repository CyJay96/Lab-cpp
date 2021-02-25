#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

struct Node {
	char symbol;
	Node* link;
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

void input(Node*& top, int n);
void add(Node*& top, char ch);
void output(Node* top);

bool repeat(Node* head1, Node* head2, Node* top1);
void createList(Node* top1, Node*& top2);