/*
Дан массив целых чисел, содержащий n элементов. Для тестирования предусмотреть
возможность задавать элементы массива различным образом: при описании с
инициализацией, присвоением значений (в том числе случайных), или вводом
необходимых значений.
Найти в целочисленном массиве за один просмотр 5 наибольших элементов.
*/


#include <iostream>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	short pos;

	int* a;
	int* max = new int[5];

	cout << "Выберете один из пунктов:" << endl;
	cout << "1. Ввод с клавиатуры." << endl;
	cout << "2. Ввод случаных чисел." << endl;

	cin >> pos;

	switch (pos) {
	case 1:
		cout << "Введите количество чисел: ";
		cin >> n;

		a = new int[n];

		cout << "Введите эти числа: " << endl;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		break;
	case 2:
		cout << "Введите количество чисел: ";
		cin >> n;

		a = new int[n];

		srand(time(0));
		for (int i = 0; i < n; ++i) {
			a[i] = 1 + (rand() % 99);
		}

		cout << "Эти числа:" << endl;
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}

		cout << endl;
		break;
	default:
		cout << "Некорректные введённые данные";
		exit(0);
	}

	for (int i = 0; i < 5; ++i) {
		max[i] = a[i];
	}

	for (int i = 5; i < n; ++i) {
		if (max[0] <= a[i] || max[1] <= a[i] || max[2] <= a[i] || max[3] <= a[i] || max[4] <= a[i]) {
			if (max[0] < max[1] && max[0] < max[2] && max[0] < max[3] && max[0] < max[4]) {
				max[0] = a[i];
			} else if (max[1] < max[2] && max[1] < max[3] && max[1] < max[4]) {
				max[1] = a[i];
			} else if (max[2] < max[3] && max[2] < max[4]) {
				max[2] = a[i];
			} else if (max[3] < max[4]) {
				max[3] = a[i];
			} else {
				max[4] = a[i];
			}
		}
	}

	cout << "5 наибольших чисел:" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << max[i] << " ";
	}

	delete[] a, max;

	return 0;
}