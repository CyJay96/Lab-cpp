/*
Получить квадратную матрицу B порядка n, каждый элемент b[i, j] которой
равен максимуму из элементов исходной квадратной матрицы А порядка n,
расположенных в закрашенной области (включая границы), определяемой
соответствующими индексами i, j по рисунку.
*/


#include <iostream>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	int n, a[100][100], b[100][100];

	cout << "Введите порядок матрицы A: ";
	cin >> n;

	cout << "Элементы данной матрицы:" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = 10 + (rand() % 90);

			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "Элементы новой матрицы B:" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int max = a[i][j];

			for (int k = 0; k <= i; ++k) {
				for (int m = j; m < n; ++m) {
					if (max < a[k][m]) {
						max = a[k][m];
					}
				}
			}

			b[i][j] = max;

			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}