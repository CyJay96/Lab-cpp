/*
Вводится последовательность целых чисел. Определить количество элемен-
тов в наиболее длинной подпоследовательности подряд идущих чисел, представ-
ляющих собой числа Фиббоначи.

Выполнить задание без хранения последовательности значений.

Ввод:
4 3 5 13 22 2 5 8 21 11 0
  3 5 13    2 5 8 21      - числа Фибоначчи

Вывод:
4
*/


#include <iostream>

using namespace std;

int main() {
	int a = 0;
	int b = 0;

	int k = 1;
	int k_max = 1;

	cout << "Enter a sequence of numbers (0 is the last element):" << endl;

	cin >> a;

	while (a != 0) {
		b = a;

		cin >> a;

		if (a == 0) {
			break;
		}

		if (a > b) {
			int x = 0;
			int y = 1;
			while (y < a) {
				int z = x + y;
				x = y;
				y = z;
			}

			int i = 0;
			int j = 1;
			while (j < b) {
				int z = i + j;
				i = j;
				j = z;
			}

			if (y == a && j == b) {
				k++;
			}
			else {
				k = 1;
			}
		}

		if (k_max < k) {
			k_max = k;
		}
	}
	
	cout << "Maximum number of elements: " << k_max << endl;

	return 0;
}