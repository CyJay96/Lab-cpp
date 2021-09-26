/*

Дата сдачи: 09.11.2020

Дата последнего редактирования: 26.12.2020

Выполнить следующее задание для заданного текста. Оформить задание в
виде набора функций: функция выделение слова (лексемы), функция создания мас-
сива слов, функция получения результирующей строки.

В заданном тексте найти все слова, которые состоят из одинаковых наборов
символов (количество повторений символов не учитывать). Записать их в ре-
зультирующую строку.


Ввод:
stop item lead temiem deal time

Вывод:
item timeem time

*/


#include <iostream>
#include <conio.h>

using namespace std;

const int SIZE = 255;
const int SEP = 11;
const int N = 100;
const int M = 20;

char separators[SEP] = " .,:;!?-()";

bool search_char(char* str, char ch) {
	bool flag = false;

	for (int i = 0; i < strlen(str); ++i) {
		if (ch == str[i]) {
			flag = true;
			break;
		}
	}

	return flag;
}
bool search_str(char* s1, char* s2) {
	bool flag = true;

	for (int i = 0; i < strlen(s2); ++i) {
		if (!search_char(s1, s2[i])) {
			flag = false;
			break;
		}
	}

	return flag;
}

void select_word(char* str, char* tec_word, int start_pos) {
	int i = 0;
	while (!search_char(separators, str[start_pos]) && start_pos < strlen(str)) {
		tec_word[i++] = str[start_pos++];
	}
}
void create_arr(char words[N][M], char* tec_word, int pos) {
	for (int i = 0; i < strlen(tec_word); ++i) {
		words[pos][i] = tec_word[i];
	}
}
void create_new_str(char words[N][M], char* new_str, int k_words) {
	char new_str1[SIZE] = { 0 };

	for (int i = 0; i < k_words; ++i) {
		bool stop = false;

		char s1[M] = { 0 };

		for (int j = 0; j < strlen(words[i]); ++j) {
			s1[j] = words[i][j];
		}

		for (int j = i + 1; j < k_words; ++j) {
			char s2[M] = { 0 };

			for (int k = 0; k < strlen(words[j]); ++k) {
				s2[k] = words[j][k];
			}

			if (search_str(s1, s2)) {
				strcat_s(new_str1, s2);
				strcat_s(new_str1, " ");
			}
		}

		if (strcmp(new_str1, "")) {
			int k = 0;
			while (k < strlen(s1)) {
				new_str[k] = s1[k++];
			}

			new_str[k++] = ' ';

			int k1 = k;
			int m = 0;

			while (k1 < strlen(new_str1) + k) {
				new_str[k1++] = new_str1[m++];
			}

			break;
		}
	}
}
int main() {
	char str[SIZE] = { 0 };
	char new_str[SIZE] = { 0 };
	char words[N][M] = { 0 };

	cout << "Enter a text:" << endl;
	cin.getline(str, 255);

	int k_words = 0;

	int i = 0;
	while (i < strlen(str)) {
		char tec_word[SIZE] = { 0 };

		select_word(str, tec_word, i);
		create_arr(words, tec_word, k_words++);

		i += strlen(tec_word);

		while (search_char(separators, str[i])) {
			i++;
		}
	}

	create_new_str(words, new_str, k_words);

	cout << "New line:" << endl;
	cout << new_str << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}