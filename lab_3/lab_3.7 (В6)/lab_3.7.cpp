/*
Квадратные матрицы (треугольные или симметричные) порядка n в целях
экономии памяти задаются в виде одномерных массивов из (n + 1) * n/2 чисел:
сначала идет n элементов первой строки, затем n – 1 элементов второй строки,
начиная со второго элемента, и т. д. (из последней n-й строки берется только
n-й элемент).

Заданы две левые треугольные целочисленные матрицы А, B.
Найти матрицу С = A(Е + B^2), где Е – единичная матрица.

Матрица A:
1
2 3
4 5 6
7 8 9 10

Матрица B:
2
3 4
5 6 7
8 9 10 11

B^2:
0*0               0             0         0
1*0+2*1           2*2           0         0
3*0+4*1+5*3       4*2+5*4       5*5       0
6*0+7*1+8*3+9*6   7*2+8*4+9*7   8*5+9*8   9*9
*/


#include <iostream>

using namespace std;

int main() {
	int n = 0;

	cout << "Enter rang of A and B matrices: ";
	cin >> n;

	int m = (n + 1) * n / 2;

	int* a = new int[m];
	int* b = new int[m];

	int* c = new int[m];
	int* d = new int[m];

	cout << endl << "Enter the elements of matrix A:" << endl;

	for (int i = 0; i < m; ++i) {
		cin >> a[i];

		c[i] = 0;
		d[i] = 0;
	}

	cout << endl << "Enter the elements of matrix B:" << endl;

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}


	/* НАЧАЛО B^2 */
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
				d[size] += b[str + j + k] * b[inc[k]];
			}
			size++;

			for (int k = 0; k < n - 1; ++k) {
				inc[k] = inc[k + 1] + 1;
			}
		}

		delete[] inc;
	}
	/* КОНЕЦ B^2 */

	/* НАЧАЛО E + B^2 */
	size = 0;
	for (int i = 0; i < n; ++i) {
		size += i;
		d[size++]++;
	}
	/* КОНЕЦ E + B^2 */


	/* НАЧАЛО A(E + B^2) */
	size = 0;
	str = 0;
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
				c[size] += a[str + j + k] * d[inc[k]];
			}
			size++;

			for (int k = 0; k < n - 1; ++k) {
				inc[k] = inc[k + 1] + 1;
			}
		}

		delete[] inc;
	}
	/* КОНЕЦ A(E + B^2) */


	cout << endl << "Matrix C = A(E + B^2):" << endl;

	size = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << c[size++] << " ";
		}
		cout << endl;
	}

	delete[] a, b, c, d;

	return 0;
}