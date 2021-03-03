#include "functions.h"

Tree* find(Tree* top, int data) {
	if (!top) {
		return nullptr;
	}

	Tree* element;
	if (data < top->data) {
		element = find(top->left, data);
	}
	else {
		element = find(top->right, data);
	}

	return element ? element : top;
}

void add(Tree*& top, int data) {
	Tree* pnew = new Tree;

	pnew->data = data;
	pnew->left = nullptr;
	pnew->right = nullptr;

	if (!top) {
		top = pnew;
	}
	else {
		Tree* element = find(top, data);

		if (data < element->data) {
			element->left = pnew;
		}
		else {
			element->right = pnew;
		}
	}
}

void input(Tree*& top, int n) {
	for (int i = 0; i < n; ++i) {
		int element = 0;
		enter(element);
		add(top, element);
	}
}

void output(Tree* top) {
	if (top) {
		output(top->left);
		cout << top->data << " ";
		output(top->right);
	}
}

void delTree(Tree*& top) {
	if (top) {
		delTree(top->left);
		delTree(top->right);
		delete top;
		top = nullptr;
	}
}

int findLeaves(Tree* top) {
	if (!top) {
		return 0;
	}
	else {
		int l = findLeaves(top->left);
		int r = findLeaves(top->right);

		if (l == 0 && r == 0) {
			return 1;
		}
		else {
			return l + r;
		}
	}
}