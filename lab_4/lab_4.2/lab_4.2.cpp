/*

Дата сдачи: 02.11.2020

Дата последнего редактирования: 22.01.2021

Выполнить задание, используя C-строки для представления данных.

Написать программу перевода вещественных чисел из шестнадцатеричной
системы счисления в двоичную.

*/


#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	const int SIZE = 18;
	const int N = 2000;
	const int SIZE_BIN = 5;

	const char HEX[SIZE] = "0123456789ABCDEF.";
	const char hex[SIZE] = "0123456789abcdef.";

	const char bin[SIZE][SIZE_BIN] = { {"0000"}, {"0001"}, {"0010"}, {"0011"}, {"0100"}, {"0101"}, {"0110"}, {"0111"},
									   {"1000"}, {"1001"}, {"1010"}, {"1011"}, {"1100"}, {"1101"}, {"1110"}, {"1111"}, {"."} };

	char num16[N] = { 0 };
	char num2[N] = { 0 };

	cout << "Enter a number in hexadecimal notation: ";

	cin.getline(num16, SIZE);

	for (int i = 0; i < strlen(num16); ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (num16[i] == HEX[j] || num16[i] == hex[j]) {
				strcat_s(num2, bin[j]);
				strcat_s(num2, " ");
				break;
			}
		}
	}

	cout << "This number in binary notation: " << num2 << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}