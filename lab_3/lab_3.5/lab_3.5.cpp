﻿/*
В следующих заданиях построить матрицу B по заданной целочисленной матрице А
порядка n (n <= 100). Обосновать алгоритм, выбранный для решения задачи.

Построить матрицу B, столбцы которой будут состоять из различных элементов
соответствующего столбца матрицы А. Количество строк построенной матрицы B
равно наибольшему количеству различных элементов в столбце, столбцы с меньшим
числом элементов дополнить нулями.

2 4 2 3 2
---------
1 2 3 4 5
1 3 3 5 5
1 4 4 5 5
2 2 3 6 5
1 5 4 4 4
*/


#include <iostream>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	int n;

	cout << "Введите порядок матрицы n: ";
	cin >> n;

	int** a = new int*[n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
	}

	cout << endl << "Элементы матрицы A:" << endl;
	

	//заполнение матрицы A
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

			//a[i][j] = 1 + (rand() % 9);
			//cout << a[i][j] << " ";

			cin >> a[i][j];
		}
		cout << endl;
	}

	int max_n = 0;

	for (int j = 0; j < n; ++j) {
		int k_nun = n;

		for (int i = 0; i < n; ++i) {

			for (int k = i + 1; k < n; ++k) { //зануление неуникальных элементов
				if (a[i][j] == a[k][j]) {
					a[k][j] = 0;
				}
			}

			for (int k = i; k < n; ++k) { //сдвиг при нахождении нулевого элемента
				if (a[k][j] == 0) {
					for (int m = k; m < n - 1; ++m) {
						a[m][j] = a[m + 1][j];
						a[m + 1][j] = 0;
					}
				}
			}

			if (a[i][j] == 0) { //определение количества ненулевых элементов
				k_nun--;
			}
		}

		max_n < k_nun ? max_n = k_nun : true;
	}

	cout << endl << "Элементы матрицы B:" << endl;

	//вывод матрицы B
	for (int i = 0; i < max_n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;

	return 0;
}