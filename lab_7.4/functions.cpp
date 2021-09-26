#include "functions.h"

void input(Node*& top, int n) {
	for (int i = 0; i < n; ++i) {
		char ch = 0;
		enter(ch);
		add(top, ch);
	}
}

void add(Node*& top, char ch) {
	Node* prev = nullptr;
	Node* next = new Node;

	next->symbol = ch;
	next->link = nullptr;

	if (!top) {
		top = next;
	}
	else {
		Node* real_el = top->link;
		Node* prev = top;

		while (real_el) {
			prev = real_el;
			real_el = real_el->link;
		}

		next->link = prev->link;
		prev->link = next;
	}
}

void output(Node* top) {
	while (top) {
		cout << top->symbol << " ";
		top = top->link;
	}
	cout << endl;
}

bool repeat(Node* head1, Node* head2, Node* top1) {
	bool flag = true;

	int k = 0;

	while (head1 && k < 2) {
		if (top1->symbol == head1->symbol) {
			k++;
		}
		head1 = head1->link;
	}

	if (k == 1) {
		flag = false;
	}
	else {
		while (head2) {
			if (top1->symbol == head2->symbol) {
				flag = false;
				break;
			}
			head2 = head2->link;
		}
	}

	return flag;
}

void createList(Node* top1, Node*& top2) {
	while (top1) {
		Node* head1 = top1;
		Node* head2 = top2;

		if (repeat(head1, head2, top1)) {
			add(top2, top1->symbol);
		}
		top1 = top1->link;
	}
}