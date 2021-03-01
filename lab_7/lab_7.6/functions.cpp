#include "functions.h"

void add(Node*& top, Node*& end, double number) {
	Node* real = nullptr;
	Node* pred = nullptr;

	Node* new_el = new Node;
	new_el->number = number;
	new_el->next = nullptr;
	new_el->pred = nullptr;

	if (!top) {
		top = new_el;
		end = new_el;
	}
	else {
		real = top;
		pred = top;

		while (real) {
			pred = real;
			real = real->next;
		}

		real = pred->next;
		new_el->next = real;
		new_el->pred = pred;

		if (real) {
			real->pred = new_el;
		}
		else {
			end = new_el;
		}

		pred->next = new_el;
	}
}

void input(Node*& top, Node*& end, int n) {
	for (int i = 0; i < n; ++i) {
		double number = 0;
		enter(number);
		add(top, end, number);
	}
}

void del(Node*& top, Node*& end, double number) {
	Node* real = nullptr;
	Node* pred = nullptr;

	if (top->number == number) {
		real = top;
		top = top->next;
		if (top) {
			top->pred = nullptr;
		}
		else {
			end = nullptr;
		}
		delete real;
		return;
	}

	real = top;
	pred = top;

	while (real && abs(real->number - number) > DBL_EPSILON) {
		pred = real;
		real = real->next;
	}

	real = pred->next;
	if (!real) {
		return;
	}

	pred->next = real->next;
	if (real->next) {
		real->next->pred = pred;
	}
	else {
		end = pred;
	}

	delete real;
}

void outputStart(Node* top) {
	while (top) {
		cout << top->number << " ";
		top = top->next;
	}
	cout << endl;
}

void outputEnd(Node* end) {
	while (end) {
		cout << end->number << " ";
		end = end->pred;
	}
	cout << endl;
}

double solve(Node* top, Node* end) {
	double res = 1;

	while (top && end) {
		res *= top->number + end->number;

		top = top->next;
		end = end->pred;
	}

	return res;
}
