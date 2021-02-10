/*
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
	int dig[50];

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

	cout << "Сверхпростые числа в задонном диапазоне:" << endl;

	//нахождение простых чисел от a до b
	for (int i = a; i <= b; ++i) {
		bool check = true;
		for (int j = 2; j < sqrt(double(i)); ++j) {
			if (i % j == 0) {
				check = false;
				break;
			} // i - потенциально простое число
		}
		if (check) {
			//выделение цифр из числа в массив в обратном порядке
			int prime = i;
			int k = 0;
			while (prime) {
				dig[k] = prime % 10;
				prime /= 10;
				k++; //количество цифр в числе
			}
			prime = i;

			//переворот массива
			int l = 0;
			while (l < k - l - 1) {
				int m = dig[l];
				dig[l] = dig[k - l - 1];
				dig[k - l - 1] = m;
				l++;
			}

			//запись цифр из массива в число в обратном порядке
			int super_prime = 0;
			for (int m = 0; m < k; ++m) {
				super_prime += dig[m] * pow(10, m);
			}

			//проверка на сверхпростое
			bool prime_check = true;
			for (int k = 2; k <= sqrt(double(super_prime)); ++k) {
				if (super_prime % k == 0) {
					prime_check = false;
					break;
				}
			}
			if (prime_check) {
				cout << "(" << prime << "; " << super_prime << ")" << endl;
			}
		}
	}

	return 0;
}