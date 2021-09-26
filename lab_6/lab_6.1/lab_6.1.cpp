/*

Дата сдачи: 11.02.2021

Выполнить задания 4.1, 4.2, 4.3, используя string-строки для представления данных.
Задания выполнить через функции.

4.1:
Заданное натуральное число от 1 до 1999 вывести римскими цифрами.

4.2:
Написать программу перевода вещественных чисел из шестнадцатеричной
системы счисления в двоичную.

4.3:
Записать в новую строку слова, которые состоят из тех же букв, что и послед-
нее слово заданной строки символов.
stop item lead temiem deal time
item temiem

*/


#include "functions.h"

int main() {
	/* LAB 4.1 */
	cout << "Lab 4.1:" << endl;
	cout << "Enter a natural number from 1 to 1999: ";

	int n = 0;
	input(n);

	cout << "This is a Roman number: " << roman(n) << endl << endl;
	/* КОНЕЦ LAB 4.1 */


	/* LAB 4.2 */
	cout << "Lab 4.2:" << endl;
	cout << "Enter a number in hexadecimal notation: ";

	string hex = "";
	input(hex);

	cout << "This number in binary notation: " << hex_to_bin(hex) << endl << endl;
	/* КОНЕЦ LAB 4.2 */


	/* LAB 4.3 */
	cout << "Lab 4.3:" << endl;
	cout << "Enter a text:" << endl;

	string str = "";

	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, str);

	cout << "New line:" << endl;
	cout << word_selection(str) << endl;
	/* КОНЕЦ LAB 4.3 */

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}