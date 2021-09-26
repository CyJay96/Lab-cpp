/*

Дата сдачи: 16.11.2020

Дата последнего редактирования: 26.12.2020

Написать функцию замены подстроки S1 (задаваемую позицией первого символа
и количеством символов) на подстроку S2 в строке S. Используя эту функцию,
выполнить сжатие заданной строки, т. е. заменить всякую серию подряд идущих
символов на (k)s, где s – повторяемый символ, a k – количество его повторений.

Ввод:
abbcdeeefghiiiijkk

Вывод:
a(2)bcd(3)efgh(4)ij(2)k

*/


#include <iostream>
#include <conio.h>

using namespace std;

void replace(char* s, char* ins, int pos, int kol) {
	for (int i = 0; i < kol; ++i) {
		for (int j = pos; j < strlen(s); ++j) {
			s[j] = s[j + 1];
		}
	}

	for (int i = strlen(ins) - 1; i >= 0; --i) {
		int j = strlen(s);
		while (j >= pos) {
			s[j] = s[j - 1];
			j--;
		}
		s[++j] = ins[i];
	}
}

int main() {
	const int SIZE = 255;
	const int ASCII_SHIFT = 48;
	const int SIZE_ARR_INS = 5;

	char s[SIZE] = { 0 };

	cout << "Enter a text:" << endl;
	cin.getline(s, SIZE);

	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] == s[i + 1]) {
			char ins[SIZE_ARR_INS] = { 0 };

			int kol = 0;

			int j = i;
			while (s[i] == s[j++]) {
				kol++;
			}

			ins[0] = '(';
			ins[1] = static_cast<char>(kol + ASCII_SHIFT);
			ins[2] = ')';
			ins[3] = s[i];

			replace(s, ins, i, kol);
		}
	}

	cout << "New line:" << endl;
	cout << s << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}