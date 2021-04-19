#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

template <class T>
void input(istream& in, T& data) {
	while (true) {
		in >> data;

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

string convertToRPN(string expression);
double calculateRPN(string polExpression);