/*

Дата сдачи: ...

Дата последнего редактирования: 22.01.2021

Выполнить задания для текстового и бинарного файлов. Задания выполнить через функции.
Размер файлов <= 64GiB.

Компоненты файла f - целые числа. Получить файл g из чисел исходного файла, в котором
записаны сначала все положительные числа, затем все отрицательные.

*/


#include "functions.h"

int main() {
	srand(static_cast<unsigned>(time(NULL)));

	cout << "Enter amount of numbers: ";
	int n = 0;
	input(n);
	cout << endl;


	// text file
	ofstream write_f("f.txt");
	if (!write_f) {
		cout << "File error" << endl;
		return 1;
	}
	create_numbers(write_f, n);
	write_f.close();

	ifstream read_f("f.txt");
	if (!read_f) {
		cout << "File error" << endl;
		return 2;
	}
	ofstream write_g("g.txt");
	if (!write_g) {
		cout << "File error" << endl;
		return 3;
	}
	unsigned_sort(read_f, write_g, n);
	read_f.close();
	write_g.close();


	// binary file
	ofstream write_f_bin("f.bin", ios::binary);
	if (!write_f_bin) {
		cout << "File error" << endl;
		return 4;
	}
	create_numbers(write_f_bin, n);
	write_f_bin.close();

	ifstream read_f_bin("f.bin", ios::binary);
	if (!read_f_bin) {
		cout << "File error" << endl;
		return 5;
	}
	ofstream write_g_bin("g.bin", ios::binary);
	if (!write_g_bin) {
		cout << "File error" << endl;
		return 6;
	}
	unsigned_sort(read_f_bin, write_g_bin, n);
	read_f_bin.close();
	write_g_bin.close();


	cout << "The text file is ready..." << endl;
	cout << "The binary file is ready..." << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}