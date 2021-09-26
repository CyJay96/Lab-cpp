/*

Дата сдачи: 11.02.2021

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


	/* TEXT FILE */
	ofstream write_file("f.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 1;
	}

	create_numbers(write_file, n);
	write_file.close();

	ifstream read_file("f.txt");
	if (!read_file) {
		cout << "File error" << endl;
		return 2;
	}

	write_file.clear();
	write_file.open("g.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 3;
	}

	unsigned_sort(read_file, write_file, n);
	read_file.close();
	write_file.close();


	/* BINARY FILE */
	write_file.clear();
	write_file.open("f.bin", ios::binary);
	if (!write_file) {
		cout << "File error" << endl;
		return 4;
	}

	create_numbers_bin(write_file, n);
	write_file.close();

	read_file.clear();
	read_file.open("f.bin", ios::binary);
	if (!read_file) {
		cout << "File error" << endl;
		return 5;
	}

	write_file.clear();
	write_file.open("g.bin", ios::binary);
	if (!write_file) {
		cout << "File error" << endl;
		return 6;
	}

	unsigned_sort_bin(read_file, write_file, n);
	read_file.close();
	write_file.close();


	cout << "The text file is ready..." << endl;
	cout << "The binary file is ready..." << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}