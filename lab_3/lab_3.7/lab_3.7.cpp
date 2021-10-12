﻿/*
Квадратные матрицы (треугольные или симметричные) порядка n в целях
экономии памяти задаются в виде одномерных массивов из (n + 1) * n/2 чисел:
сначала идет n элементов первой строки, затем n – 1 элементов второй строки,
начиная со второго элемента, и т. д. (из последней n-й строки берется только
n-й элемент).

Задана вещественная левая треугольная матрица А. Найти матрицу В = A * А^T.

1
2 3
4 5 6
7 8 9 1
2 3 4 5 6

1
2 3
4 5 6
7 8 9 10


0*0   0*1       0*3           0*6
1*0   1*1+2*2   1*3+2*4       1*6+2*7
3*0   3*1+4*2   3*3+4*4+5*5   3*6+4*7+5*8
6*0   6*1+7*2   6*3+7*4+8*5   6*6+7*7+8*8+9*9
*/


#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int n;

	cout << "Введите порядок матрицы A: ";
	cin >> n;

	int m = (n + 1) * n / 2;

	int* a = new int[m];

	int** b = new int* [n];
	for (int i = 0; i < n; ++i) {
		b[i] = new int[n];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[i][j] = 0;
		}
	}

	cout << endl << "Введите элементы матрицы A:" << endl;

	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}


	int str = 0;    // 0, 1, 3, 6, 10, 15, ...
	int str_inc = 0; // 0, 1, 2, 3, 4, 5, ...

	for (int i = 0; i < n; ++i) {
		str += str_inc++;

		int stl = 0;  // 0, 1, 3, 6, 10, 15, ...
		int stl_inc = 0;  // 0, 1, 2, 3, 4, 5, ...

		for (int j = 0; j < n; ++j) {
			stl += stl_inc++;

			for (int k = 0; k <= i; ++k) {
				b[i][j] += a[str + k] * a[stl + k];

				if (k == j) {
					break;
				}
			}
		}
	}


	//0*0   0*1       0*3           0*6
	//1*0   1*1+2*2   1*3+2*4       1*6+2*7
	//3*0   3*1+4*2   3*3+4*4+5*5   3*6+4*7+5*8
	//6*0   6*1+7*2   6*3+7*4+8*5   6*6+7*7+8*8+9*9


	cout << endl << "Матрица B = A * A^T:" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i) {
		delete[] b[i];
	}
	delete[] a, b;

	return 0;
}