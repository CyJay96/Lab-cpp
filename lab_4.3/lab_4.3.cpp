/*

Дата сдачи: 02.11.2020

Дата последнего редактирования: 26.12.2020

Выполнить задание для заданной строки символов, используя C-строки для
представления данных.

Текст – непустая последовательность символов.
Слово – непустая последовательность любых символов, кроме символов-
разделителей.
Предложение – последовательность слов, разделенных одним или несколь-
кими символами-разделителями.
Символы-разделители: «пробел», «.», «,», «:», «;», «!», «?», «-», «(», «)».

Записать в новую строку слова, которые состоят из тех же букв, что и послед-
нее слово заданной строки символов.

Ввод:
stop item lead temiem deal time

Вывод:
item temiem

*/


#include <iostream>
#include <conio.h>

using namespace std;

bool search_char(char str[], char ch) {
	bool flag = false;

	for (int i = 0; i < strlen(str); ++i) {
		if (ch == str[i]) {
			flag = true;
			break;
		}
	}

	return flag;
}

//найти в строке s1 все символы строки s2
bool search_str(char s1[], char s2[]) {
	bool flag = true;

	for (int i = 0; i < strlen(s2); ++i) {
		if (!search_char(s1, s2[i])) {
			flag = false;
			break;
		}
	}

	return flag;
}

int main() {
	const int SIZE = 255;
	const int SEP = 11;

	char separators[SEP] = " .,:;!?-()";

	char str[SIZE] = { 0 };
	char last_word[SIZE] = { 0 };
	char new_str[SIZE] = { 0 };

	cout << "Enter a text:" << endl;
	cin.getline(str, 255);

	//длина строки, есть на конце есть разделители
	int len = strlen(str) - 1;
	while (search_char(separators, str[len])) {
		len--;
	}

	//длина последнего слова
	int len_last = 0;
	while (!search_char(separators, str[len]) && len >= 0) {
		last_word[len_last++] = str[len--];
	}

	//поиск слов
	for (int i = 0; i < len; ++i) {
		char tec_word[SIZE] = { 0 };

		while (!search_char(separators, str[i])) {
			char buf[2] = { str[i] };
			strcat_s(tec_word, buf);
			i++;
		}

		while (search_char(separators, str[i])) {
			i++;
		}

		i--;

		if (search_str(last_word, tec_word)) {
			strcat_s(new_str, tec_word);
			strcat_s(new_str, " ");
		}
	}

	cout << "New line:" << endl;
	cout << new_str << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}