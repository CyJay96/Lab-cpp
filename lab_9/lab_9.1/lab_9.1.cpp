/*

Дата сдачи: 25.03.2021

Реализовать задание 5.3, используя объявление и методы соответствующего параметризированного
класса vector из стандартной библиотеки шаблонов STL.

5.3:
Выполнить следующее задание для заданного текста. Оформить задание в
виде набора функций: функция выделение слова (лексемы), функция создания
массива слов, функция получения результирующей строки.

В заданном тексте найти все слова, которые состоят из одинаковых наборов
символов (количество повторений символов не учитывать). Записать их в
результирующую строку.


Ввод:
stop item lead temiem deal time

Вывод:
item timeem time

*/


#include "functions.h"

int main() {
	string str = "";
	vector<string> words;

	cout << "Enter a text:" << endl;
	getline(cin, str);

	int i = 0;
	while (i < str.length()) {
		string current_word = select_word(str, i);
		create_arr(words, current_word);

		i += current_word.length();

		while (search_char(separators, str[i])) {
			i++;
		}
	}

	string new_str = create_new_str(words);

	cout << "New line:" << endl;
	cout << new_str << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}