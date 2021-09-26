/*

Дата сдачи: 09.11.2020

Дата последнего редактирования: 26.12.2020

Выполнить задание, используя C-строки для представления данных.

Заданное натуральное число от 1 до 1999 вывести римскими цифрами.

*/


#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	const int SIZE = 255;
	const int K_RIM_ARAB = 13;
	const int SIZE_RIM = 3;

	const char rim[K_RIM_ARAB][SIZE_RIM] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	const int arab[K_RIM_ARAB] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

	int n = 0;

	cout << "Enter a natural number from 1 to 1999: ";
	cin >> n;

	char res[SIZE] = { 0 };
	int k = K_RIM_ARAB - 1;

	if (n <= 0) {
		strcat_s(res, "0");
	}

	while (n > 0) {
		while (n < arab[k]) {
			k--;
		}
		strcat_s(res, rim[k]);
		n -= arab[k];
	}

	cout << "This is a Roman number: " << res << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}