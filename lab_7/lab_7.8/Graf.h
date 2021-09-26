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
void enter(istream& in, Type& a) {
	while (true) {
		in >> a;

		if (in.fail()) {
			in.clear();
			in.ignore(INT_MAX, '\n');

			cout << "An incorrect value. Please try again:" << endl;

			continue;
		}
		else {
			break;
		}
	}
}

void add(Vertexes*& top, int number);
void add(Graf*& top, int number);
void del(Vertexes*& top, int number);
void del(Graf*& top, int number);

void addConnect(Graf*& top, int n);

void input(Graf*& top, int n);
void output(Graf* top);

bool checkGraf(Graf* top, int ver1, int ver2);

int searchWay(Graf* top, Vertexes* head, int ver2);
void oneToOther(Graf* top, int ver1, int ver2);