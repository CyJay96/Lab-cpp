/*
Дана действительная матрица порядка n × m. Перебор строк/столбцов матрицы
осуществить с использованием указателей. Обосновать выбор метода сортировки.

Упорядочить столбцы по невозрастанию первых элементов.

a[i][j] = *(*(a + i) + j).
*/


#include <iostream>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));

	int n, m;
	int a[100][100], b[100][100];

	cout << "Введите порядок матрицы n и m:" << endl;

	cout << "n = ";
	cin >> n;

	cout << "m = ";
	cin >> m;

	cout << "Элементы данной матрицы:" << endl;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = 10 + (rand() % 90);

			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < m - 1; ++i) {
		for (int j = 0; j < m - i - 1; ++j) {
			if (a[0][j] <= a[0][j + 1]) {
				//сортируем столбцы по первому элементу
				int* buf = new int[n];

				for (int k = 0; k < n; ++k) {
					buf[k] = a[k][j];
					a[k][j] = a[k][j + 1];
					a[k][j + 1] = buf[k];
				}

				delete[] buf;
			}
		}
	}

	cout << endl;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}

	return 0;
}