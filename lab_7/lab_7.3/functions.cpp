#include "functions.h"

void writeDate(string date, Node::Students& st) {
	int i = 0;
	const char sep1 = '.';
	const char sep2 = '/';

	string day = "";
	while (date[i] != sep1 && date[i] != sep2) {
		day += date[i++];
	}
	i++;

	string month = "";
	while (date[i] != sep1 && date[i] != sep2) {
		month += date[i++];
	}
	i++;

	string year = "";
	for (i; i < date.length(); ++i) {
		year += date[i];
	}

	st.date.day = atoi(day.c_str());
	st.date.month = atoi(month.c_str());
	st.date.year = atoi(year.c_str());
}

string outputDate(Node::Students::DateOfBirth date) {
	return to_string(date.day) + "." + to_string(date.month) + "." + to_string(date.year);
}

void masToList(Node* top, Node::Students*& infoSort) {
	int i = 0;

	while (top) {
		infoSort[i++] = top->stud;
		top = top->link;
	}
}

void fillList(ofstream& file, Node::Students* st, int n) {
	for (int i = 0; i < n; ++i) {
		string fio = "";
		string date = "";

		cin >> st[i].name;
		cin >> fio; st[i].name += " " + fio;
		cin >> fio; st[i].name += " " + fio;
		cin >> date; writeDate(date, st[i]);
		cin >> st[i].course;
		cin >> st[i].mark;

		file << st[i].name << " " << outputDate(st[i].date) << " " << st[i].course << " " << st[i].mark << endl;
	}
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
		if (top->stud.name >= info.name) {
			next->link = top;
			top = next;
		}
		else {
			Node* real_el = top;
			prev = top;
			while (real_el && real_el->stud.name <= info.name) {
				prev = real_el;
				real_el = real_el->link;
			}

			next->link = prev->link;
			prev->link = next;
		}
	}
}

void del(Node*& top, Node::Students& info) {
	if (!top) {
		return;
	}

	Node* real_el = top;
	Node* prev = top;

	while (real_el && real_el->stud.name != info.name) {
		prev = real_el;
		real_el = real_el->link;
	}

	if (prev == top && top->stud.name == info.name) {
		top = top->link;
		delete prev;
		return;
	}

	real_el = prev->link;
	if (!real_el) {
		return;
	}

	prev->link = real_el->link;

	delete real_el;
}

void output(Node* top) {
	int i = 1;
	while (top) {
		cout << i++ << ") " << top->stud.name << " " << outputDate(top->stud.date) << " " <<
			top->stud.course << " " << top->stud.mark << endl;
		top = top->link;
	}
}

int searchOldest(Node::Students* students, Node::Students* studentsOldest, int n) {
	const int MIN_COURSE = 1;
	const int MAX_COURSE = 4;

	time_t days = time(NULL) / (3600 * 24);

	int k_oldest = 0;
	for (int course = MIN_COURSE; course <= MAX_COURSE; ++course) {
		int pos_oldest = 0;
		while (students[pos_oldest].course != course && pos_oldest < n) {
			pos_oldest++;
		}

		for (int i = pos_oldest + 1; i < n; ++i) {
			int ageOldest = days -
				(students[pos_oldest].date.year * 365 + students[pos_oldest].date.month * 12 + students[pos_oldest].date.day);
			int age = days - (students[i].date.year * 365 + students[i].date.month * 12 + students[i].date.day);

			if (ageOldest < age && students[i].course == course) {
				pos_oldest = i;
			}
		}

		for (int i = 0; i < n; ++i) {
			int ageOldest = days -
				(students[pos_oldest].date.year * 365 + students[pos_oldest].date.month * 12 + students[pos_oldest].date.day);
			int age = days - (students[i].date.year * 365 + students[i].date.month * 12 + students[i].date.day);

			if (age == ageOldest && students[i].course == course) {
				studentsOldest[k_oldest++] = students[i];
			}
		}
	}

	return k_oldest;
}