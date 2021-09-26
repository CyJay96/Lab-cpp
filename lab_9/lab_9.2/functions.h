#pragma once
#include <iostream>
#include <vector>
#include <list>
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

void input(vector<char>& vctr, int n);
void output(const vector<char>& vctr);
bool repeat(const vector<char>& vctr1, const vector<char>& vctr2, char data);
void createList(const vector<char>& vctr1, vector<char>& vctr2);

void vectorToList(const vector<char>& vctr, list<char>& lst);

void input(list<char>& lst, int n);
void output(const list<char>& lst);
bool repeat(const list<char>& lst1, const list<char>& lst2, char data);
void createList(const list<char>& lst1, list<char>& lst2);