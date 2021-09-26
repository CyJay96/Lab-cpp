/*

Дата сдачи: 09.11.2020

Дата последнего редактирования: 26.12.2020

Выполнить задание, оформив его через функции. Передачу массивов в функции
организовать несколькими способами.

Получить квадратную матрицу порядка n, элементами которой являются заданные
числа а1, ..., аnn, расположенные в ней по спирали.

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

*/


#include <iostream>
#include <conio.h>

using namespace std;

void matrix(int* a, int n) {
	int** b = new int* [n];
	for (int i = 0; i < n; ++i) {
		b[i] = new int[n];
	}

	int k = 0;

	for (int m = 0; m < n / 2 + 1; ++m) {
		for (int j = n - m - 1; j >= m; --j) {
			b[n - m - 1][j] = a[k++];
		}

		for (int i = n - m - 2; i >= m; --i) {
			b[i][m] = a[k++];
		}

		for (int j = m + 1; j < n - m; ++j) {
			b[m][j] = a[k++];
		}

		for (int i = m + 1 ; i < n - m - 1; ++i) {
			b[i][n - m - 1] = a[k++];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < n; ++i) {
		delete[] b[i];
	}
	delete[] b;
}

int main() {
	int n = 0;

	cout << "Enter rang of the matrix: ";
	cin >> n;

	int* a = new int[n * n];

	cout << "Enter the matrix elements:" << endl;

	for (int i = 0; i < n * n; ++i) {
		cin >> a[i];
	}

	cout << "Elements of this matrix, located in it in a spiral:" << endl;

	matrix(a, n);

	delete[] a;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}