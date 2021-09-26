/*

Дата сдачи: 14.12.2020

Дата последнего редактирования: 07.02.2021

Напишите функцию, возвращающую ссылку на минимальное число, встречающееся
в заданном массиве произвольного размера (аргумент функции) больше одного
раза. Если такого числа нет, то возвратить ссылку на минимальное число в
массиве. Замените этот элемент значением k.

Ввод:
10
9 4 7 6 5 8 6 8 6 9

Вывод:
9 4 7 0 5 8 6 8 6 9

*/

#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

enum options {
	one = 1,
	two = 2,
};

int input(int& n) {
	while (true) {
		cin >> n;

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

	return n;
}

int& search_min(int* a, int n) {
	int pos_min = 0;
	bool once = true;

	for (int i = 0; i < n && once; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] == a[j]) {
				pos_min = i;
				once = false;
				break;
			}
		}
	}

	if (once) {
		for (int i = 1; i < n; ++i) {
			if (a[pos_min] > a[i]) {
				pos_min = i;
			}
		}
	}
	else {
		for (int i = pos_min + 1; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (a[i] == a[j] && a[pos_min] > a[i]) {
					pos_min = i;
					break;
				}
			}
		}
	}

	return a[pos_min];
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	int n = 0;

	cout << "Enter the size of the array: ";
	n = input(n);

	int* a = new int[n];

	int p = 0;
	cout << "Select one of the following options:" << endl;
	cout << one << ". Keyboard input." << endl;
	cout << two << ". Filling with random numbers." << endl;
	p = input(p);

	switch (p) {
	case one:
		cout << "Enter the array elements:" << endl;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		cout << endl;
		break;
	case two:
		cout << "This array:" << endl;
		for (int i = 0; i < n; ++i) {
			a[i] = rand() % 99;
			cout << a[i] << " ";
		}
		cout << endl;
		break;
	default:
		cout << "An incorrect value." << endl;
		return 0;
	}

	int& min = search_min(a, n);

	cout << "The minimum number: " << min << endl << endl;
	cout << "Modified array:" << endl;

	min = 0;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}