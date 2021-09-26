/*

Дата сдачи: 22.02.2021

Выполнить задание, используя динамическое выделение памяти для двумерного массива, двумя способами:
1) описывая двумерный массив как одномерный, с расчетом смещения элемента массива по линейной формуле;
2) описывая двумерный массив как указатель на массив указателей.

Даны вещественные квадратные матрицы А, В, C порядка n. Составить функцию для получения матрицы D = А * (В + С).

A, B, C:
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

D:
180  200  220  240
404  456  508  560
628  712  796  880
852  968  1084 1200

*/


#include "functions.h"

int main() {
	int n = 0;
	cout << "Enter rang of A, B and C matrices: ";
	cin >> n;

	int* a1 = new int[n * n];
	int* b1 = new int[n * n];
	int* c1 = new int[n * n];
	int* d1 = new int[n * n];

	int** a2 = new int* [n];
	int** b2 = new int* [n];
	int** c2 = new int* [n];
	int** d2 = new int* [n];
	for (int i = 0; i < n; ++i) {
		a2[i] = new int[n];
		b2[i] = new int[n];
		c2[i] = new int[n];
		d2[i] = new int[n];
	}

	cout << endl << "Enter the elements of matrix A:" << endl;
	input(a1, a2, n);

	cout << endl << "Enter the elements of matrix B:" << endl;
	input(b1, b2, n);


	cout << endl << "Enter the elements of matrix C:" << endl;
	input(c1, c2, n);
	cout << endl << endl;

	// addition
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b1[i * n + j] += c1[i * n + j];
			b2[i][j] += c2[i][j];
			d1[i * n + j] = 0;
			d2[i][j] = 0;
		}
	}

	// multiplication
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				d1[i * n + j] += a1[i * n + k] * b1[k * n + j];
				d2[i][j] += a2[i][k] * b2[k][j];
			}
		}
	}

	cout << "Matrix D = A * (B + C):" << endl;

	cout << endl << "Way namber 1:" << endl;
	output(d1, n);

	cout << endl << "Way namber 2:" << endl;
	output(d2, n);

	for (int i = 0; i < n; ++i) {
		delete[] a2[i], b2[i], c2[i], d2[i];
	}
	delete[] a1, b1, c1, d1;
	delete[] a2, b2, c2, d2;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}