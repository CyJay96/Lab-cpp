#include "functions.h"

void writeDate(string date, Node::Students& st) {
	string day = "";
	for (int i = 0; i < 2; ++i) {
		day += date[i];
	}

	string month = "";
	for (int i = 3; i < 5; ++i) {
		month += date[i];
	}

	string year = "";
	for (int i = 6; i < 10; ++i) {
		year += date[i];
	}

	st.date.day = atoi(day.c_str());
	st.date.month = atoi(month.c_str());
	st.date.year = atoi(year.c_str());
}

string outputDate(Node::Students::DateOfBirth date) {
	return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

void fillList(ifstream& file, Node::Students* st) {
	int i = 0;
	while (!file.eof()) {
		string fio = "";
		string date = "";

		file >> st[i].name;
		file >> fio; st[i].name += " " + fio;
		file >> fio; st[i].name += " " + fio;
		file >> date; writeDate(date, st[i]);
		file >> st[i].course;
		file >> st[i].mark;

		i++;
	}
}

int compare_str(Node*& top, Node::Students& info) {
	const int SIZE = 50;

	string name_prev_str = top->stud.name;
	string name_next_str = info.name;
	char name_prev[SIZE] = { 0 };
	char name_next[SIZE] = { 0 };

	for (int i = 0; i < name_prev_str.length(); ++i) {
		name_prev[i] = name_prev_str[i];
	}
	for (int i = 0; i < name_next_str.length(); ++i) {
		name_next[i] = name_next_str[i];
	}

	return strcmp(name_next, name_prev);
}

void add(Node*& top, Node::Students& info) {
	Node* prev = nullptr;
	Node* next = new Node;

	next->stud = info;
	next->link = nullptr;

	if (!top) {
		top = next;
	}
	else {
		if (compare_str(top, info) <= 0) {
			next->link = top;
			top = next;
		}
		else {
			Node* real_el = top;
			prev = top;
			while (real_el && compare_str(real_el, info) >= 0) {
				prev = real_el;
				real_el = real_el->link;
			}

			next->link = prev->link;
			prev->link = next;
		}
	}
}

void output(Node* top) {
	int i = 1;
	while (top) {
		cout << i++ << ") " << top->stud.name << " " << outputDate(top->stud.date) << " " << top->stud.course << " " << top->stud.mark << endl;
		top = top->link;
	}
}