/*
Выполнить задание 2.3, используя алгоритм «решето Эратосфена» для нахождения
простых чисел. Найти максимальное простое число, которое возможно определить
по этому алгоритму в данной системе программирования.

Задание 2.3:
Сверхпростым называется число, если оно простое, и число, полученное
из исходного числа при записи цифр исходного числа в обратном порядке
(«перевертыш»), тоже будет простым. Написать программу, которая выводит
все сверхпростые числа в диапазоне от а до b.
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int a, b;

	cout << "Введите размеры диапазона:" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if (a > b) {
		cout << "a должно быть >= b";
		exit(0);
	}

	if (a <= 2) {
		a = 2;
	}

	cout << endl << "Сверхпростые числа в задонном диапозоне:" << endl;

	bool* prime_check = new bool[b];

	//заполним все ячейки числом 1
	for (int i = a; i < b; ++i) {
		prime_check[i] = true;
	}

	//вычеркиваем (обнуляем) кратные числа
	for (int i = 2; i <= sqrt(double(b)); ++i) {
		if (prime_check[i]) {
			for (int j = i * 2; j < b; j += i) {
				prime_check[j] = false;
			}
		}
	}

	//проверка на сверхпростое и вывод
	for (int i = a; i < b; ++i) {
		if (prime_check[i]) {
			int number = i;
			int rev = 0;

			while (number) {
				rev *= 10;
				rev += number % 10;
				number /= 10;
			}

			bool flag = true;
			for (int j = 2; j <= sqrt(double(rev)); ++j) {
				if (rev % j == 0) {
					flag = false;
				}
			}
			if (flag) {
				cout << "(" << i << "; " << rev << ")" << endl;
			}
		}
	}

	delete[] prime_check;

	return 0;
}