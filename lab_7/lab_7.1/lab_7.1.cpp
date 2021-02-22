/*

Дата сдачи: 22.02.2021

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
	int* sort_array = new int[N];
	for (int i = 0; i < N; ++i) {
		sort_array[i] = 0;
	}

	int size = 0;
	cout << "Enter a size of array: ";
	cin >> size;

	ofstream write_file("numbers.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 1;
	}

	for (int i = 0; i < size; ++i) {
		int number = 1 + rand() % N;
		sort_array[number]++;
		write_file << number << endl;
	}

	write_file.close();

	write_file.clear();
	write_file.open("sort_numbers.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 2;
	}

	for (int i = N - 1; i >= 0; --i) {
		if (sort_array[i] != 0) {
			write_file << i << endl;
		}
	}

	write_file.close();

	cout << "Text files are ready..." << endl;

	delete[] sort_array;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}
