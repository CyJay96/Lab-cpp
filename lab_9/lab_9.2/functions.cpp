#include "functions.h"

void input(vector<char>& vctr, int n) {
	for (int i = 0; i < n; ++i) {
		char data = 0;
		enter(data);
		vctr.push_back(data);
	}
}

void output(const vector<char>& vctr) {
	vector<char>::const_iterator iter = vctr.begin();
	while (iter != vctr.end()) {
		cout << *iter << " ";
		++iter;
	}
}

bool repeat(const vector<char>& vctr1, const vector<char>& vctr2, char data) {
	int k = 0;

	vector<char>::const_iterator iterV1 = vctr1.begin();
	while (iterV1 != vctr1.end() && k < 2) {
		if (*iterV1 == data) {
			k++;
		}
		++iterV1;
	}

	if (k == 1) {
		return false;
	}
	else {
		vector<char>::const_iterator iterV2 = vctr2.begin();
		while (iterV2 != vctr2.end()) {
			if (data == *iterV2) {
				return false;
			}
			++iterV2;
		}
	}

	return true;
}

void createList(const vector<char>& vctr1, vector<char>& vctr2) {
	vector<char>::const_iterator iter = vctr1.begin();
	while (iter != vctr1.end()) {
		if (repeat(vctr1, vctr2, *iter)) {
			vctr2.push_back(*iter);
		}
		++iter;
	}
}

void vectorToList(const vector<char>& vctr, list<char>& lst) {
	vector<char>::const_iterator iter = vctr.begin();
	while (iter != vctr.end()) {
		lst.push_back(*iter);
		++iter;
	}
}

void input(list<char>& lst, int n) {
	for (int i = 0; i < n; ++i) {
		char data = 0;
		enter(data);
		lst.push_back(data);
	}
}

void output(const list<char>& lst) {
	list<char>::const_iterator iter = lst.begin();
	while (iter != lst.end()) {
		cout << *iter << " ";
		++iter;
	}
}

bool repeat(const list<char>& lst1, const list<char>& lst2, char data) {
	int k = 0;

	list<char>::const_iterator iterV1 = lst1.begin();
	while (iterV1 != lst1.end() && k < 2) {
		if (*iterV1 == data) {
			k++;
		}
		++iterV1;
	}

	if (k == 1) {
		return false;
	}
	else {
		list<char>::const_iterator iterV2 = lst2.begin();
		while (iterV2 != lst2.end()) {
			if (data == *iterV2) {
				return false;
			}
			++iterV2;
		}
	}

	return true;
}

void createList(const list<char>& lst1, list<char>& lst2) {
	list<char>::const_iterator iter = lst1.begin();
	while (iter != lst1.end()) {
		if (repeat(lst1, lst2, *iter)) {
			lst2.push_back(*iter);
		}
		++iter;
	}
}