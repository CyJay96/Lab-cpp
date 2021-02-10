/*

Дата сдачи: ...

Дата последнего редактирования: 06.02.2021

Выполнить задание, используя динамическое выделение памяти для одномерного массива.
Дано (в текстовом файле) n >= 10^9 натуральных чисел (каждое число <= 10^4).
Ограничение на объем используемой памяти 1 Мб. Получить массив за один просмотр элементов файла
в котором все числа исходного файла расположены по убыванию значений (без повторений).

*/


#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	const int N = 10000; // каждое число <= 10^4

	int size = 0;
	cout << "Enter a size of array: ";
	cin >> size;

	int* array = new int[size];
	int* sort_array = new int[N];
	for (int i = 0; i < N; ++i) {
		sort_array[i] = 0;
	}

	/* СОЗДАНИЕ ФАЙЛА ЧИСЕЛ */
	ofstream write_file("numbers.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 1;
	}

	for (int i = 0; i < size; ++i) {
		write_file << 1 + rand() % N << endl;
	}

	write_file.close();
	/* КОНЕЦ СОЗДАНИЯ ФАЙЛА ЧИСЕЛ */

	/* ЗАПИСЬ ИЗ ФАЙЛА В МАССИВ */
	ifstream read_file("numbers.txt");
	if (!read_file) {
		cout << "File error" << endl;
		return 2;
	}

	for (int i = 0; i < size; ++i) {
		int element = 0;
		read_file >> element;
		sort_array[element]++;
	}

	read_file.close();
	/* КОНЕЦ ЗАПИСИ ИЗ ФАЙЛА В МАССИВ */

	/* ЗАПИСЬ МАССИВА В ФАЙЛ */
	write_file.clear();
	write_file.open("sort_numbers.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 3;
	}

	for (int i = 0; i < N; ++i) {
		if (sort_array[i] != 0) {
			write_file << i << endl;
		}
	}

	write_file.close();
	/* КОНЕЦ ЗАПИСИ МАССИВА В ФАЙЛ */

	cout << "Text files are ready..." << endl;

	delete[] array, sort_array;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}