/*
Квадратные матрицы (треугольные или симметричные) порядка n в целях
экономии памяти задаются в виде одномерных массивов из (n + 1) * n/2 чисел:
сначала идет n элементов первой строки, затем n – 1 элементов второй строки,
начиная со второго элемента, и т. д. (из последней n-й строки берется только
n-й элемент).

Задана левая треугольная вещественная матрица А. Найти матрицу В = (А^2)^T.

Матрица A:
1
2 3
4 5 6
7 8 9 10

A^2:
0*0               0             0         0
1*0+2*1           2*2           0         0
3*0+4*1+5*3       4*2+5*4       5*5       0
6*0+7*1+8*3+9*6   7*2+8*4+9*7   8*5+9*8   9*9
*/


#include <iostream>

using namespace std;

int main() {
	int n = 0;

	cout << "Enter rang of matrix A: ";
	cin >> n;

	int m = (n + 1) * n / 2;

	int* a = new int[m];
	int* b = new int[m];

	for (int i = 0; i < m; ++i) {
		a[i] = 0;
		b[i] = 0;
	}

	cout << endl << "Enter the elements of matrix A:" << endl;

	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	int size = 0;
	int str = 0;
	for (int i = 0; i < n; ++i) {
		str += i;

		int* inc = new int[n];
		int p = 0;
		for (int i = 1; i <= n; ++i) {
			inc[i - 1] = p;
			p += i;
		}

		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= i - j; ++k) {
				b[size] += a[str + j + k] * a[inc[k]];
			}
			size++;

			for (int k = 0; k < n - 1; ++k) {
				inc[k] = inc[k + 1] + 1;
			}
		}

		delete[] inc;
	}

	cout << endl << "Matrix B = (A^2)^T:" << endl;

	int* inc = new int[n];
	int s = 0;
	int s_inc = 0;
	for (int i = 0; i < n; ++i) {
		s += s_inc++;
		inc[i] = s;
	}

	int n_dec = n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			cout << "\t";
		}

		for (int j = 0; j < n_dec; ++j) {
			cout << b[inc[j]] << "\t";
		}
		cout << endl;

		for (int j = 0; j < n_dec - 1; ++j) {
			inc[j] = inc[j + 1] + 1;
		}

		n_dec--;
	}

	delete[] a, b, inc;

	return 0;
}
