#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

const double y = 0.577216;

enum options {
	one = 1,
	two = 2,
	three = 3,
	four = 4,

	widthLine = 35,
};

void draw_line(int n);

template <class Type>
void input(Type& a) {
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

// перегрузка для записи по возрастанию
void inc_mas(int* a, int n);
void inc_mas(char* a, int n);
void inc_mas(double* a, int n);

// перегрузка для записи по убыванию
void dec_mas(int* a, int n);
void dec_mas(char* a, int n);
void dec_mas(double* a, int n);

// шаблон функции для рандомной записи
template <class Type>
void rand_mas(Type* a, int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = (rand() % 100) * 1.1;
	}
}

void rand_mas(char* a, int n);

// шаблон функции для ввода с клавиатуры
template <class Type>
void input_mas(Type* a, int n) {
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

// сортировка массива типа int
void selectSort(int* a, int n, int& compare, int& move);
void insertSort(int* a, int n, int& compare, int& move);

// шаблон функции сортировки массивов разных типов
template <class Type>
void selectSort(Type* a, int n) {
	for (int i = 0; i < n - 1; ++i) {
		Type min = a[i];
		int min_pos = i;

		for (int j = i + 1; j < n; ++j) {
			if (a[j] < min) {
				min = a[j];
				min_pos = j;
			}
		}

		a[min_pos] = a[i];
		a[i] = min;
	}
}

template <class Type>
void insertSort(Type* a, int n) {
	for (int i = 1; i < n; ++i) {
		Type x = a[i];
		int j = i - 1;

		while (x < a[j] && j >= 0) {
			a[j + 1] = a[j--];
		}

		a[j + 1] = x;
	}
}