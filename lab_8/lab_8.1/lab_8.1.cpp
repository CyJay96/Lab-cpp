/*

Дата сдачи: 15.03.2021

Разработать класс «вектор», моделирующий математическое понятие «одномерный массив» произвольного размера с возможностью изменения числа элементов.
Реализовать три вида конструктора (без аргументов, инициализации, копирования), деструктор.
Определить методы:
1) задания размерности вектора,
2) определения количества элементов заданного вектора;
3) заполнения элементов вектора случайными числами.
Реализовать:
1) перегрузку операторов индексирования [], возвращающие изменяемое значение элемента (L-value) и не изменяемое (R-value)
с контролем выхода за пределы размерности вектора (для получения элемента вектора по заданному индексу, занесения значения
элемента вектора по заданному индексу);
2) перегрузку операторов ввода/вывода значений элементов вектора;
Разместить описание класса в заголовочном файле, а определения методов и главную функцию программы – в отдельных файлах.
Используя объекты описанного класса «Вектор», реализовать алгоритм своего варианта задания 7.1.

7.1:
Выполнить задание, используя динамическое выделение памяти для одномерного массива.
Дано (в текстовом файле) n >= 10^9 натуральных чисел (каждое число <= 10^4).
Ограничение на объем используемой памяти 1 Мб. Получить массив за один просмотр элементов файла
в котором все числа исходного файла расположены по убыванию значений (без повторений).

*/


#include "Vector.h"

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));

	const int N = 10000;
	Vector sort_array(N);

	cout << "Enter a size of array:" << endl;
	cout << "N = ";
	int size = 0;
	enter(cin, size);

	ofstream write_file("numbers.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 1;
	}
	for (int i = 0; i < size; ++i) {
		int number = rand() % N;
		write_file << number << endl;
	}
	write_file.close();

	ifstream read_file("numbers.txt");
	if (!read_file) {
		cout << "File error" << endl;
		return 2;
	}
	while (!read_file.eof()) {
		int number = 0;
		read_file >> number;
		sort_array[number]++;
	}
	read_file.close();

	int sizeRes = createResultSize(sort_array, N);
	Vector result(sizeRes);
	createResult(result, sort_array, N);

	write_file.clear();
	write_file.open("sort_numbers.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 3;
	}
	write_file << result;
	write_file.close();

	cout << endl << "Text files are ready..." << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}
