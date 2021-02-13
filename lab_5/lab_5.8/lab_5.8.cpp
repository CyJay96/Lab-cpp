/*

Дата сдачи: 11.02.2021

Дата последнего редактирования: 13.02.2021

1) Дан массив чисел произвольной длины. Отсортировать массив, используя сортировку слияниями.
2) Создать шаблоны функций для сортировок, заполнения массивов, вывода результатов.
Сравнение элементов массива оформить отдельной функцией. Перегрузить функцию сравнения
элементов для массива С-строк.
3) Выполнить сортировки массивов для данных разных типов: целых, вещественных, символьных, С-строк,
используя написанные функции.

*/

#include "functions.h"
#include "mergeSort.h"

int main() {
	int n = 0;
	int option = 0;

	cout << "Enter the size of the array: ";
	input(n);
	cout << endl;

	int* a = new int[n];

	cout << "Choose the method of filling the array:" << endl;
	cout << one << ". Keyboard input." << endl;
	cout << two << ". Random numbers." << endl;
	input(option);
	cout << endl;

	draw_line(widthLine);

	/* INT */
	switch (option) {
	case one:
		cout << "Enter the array elements of type INT:" << endl;
		input_mas(a, n);
		break;
	case two:
		rand_mas(a, n);
		break;
	default:
		cout << "Invalid data entered" << endl;
		exit(0);
		break;
	}

	cout << "Array of INT elements:" << endl;
	output_mas(a, n);
	cout << endl;

	mergeSort(a, 0, n - 1);
	cout << "Merge sort:" << endl;
	output_mas(a, n);
	cout << endl;

	delete[] a;
	/* КОНЕЦ INT */

	draw_line(widthLine);

	/* DOUBLE */
	double* d = new double[n];

	switch (option) {
	case one:
		cout << "Enter the array elements of type DOUBLE:" << endl;
		input_mas(d, n);
		break;
	case two:
		rand_mas(d, n);
		break;
	default:
		cout << "Invalid data entered" << endl;
		exit(0);
		break;
	}

	cout << "Array of DOUBLE elements:" << endl;
	output_mas(d, n);
	cout << endl;

	mergeSort(d, 0, n - 1);
	cout << "Merge sort:" << endl;
	output_mas(d, n);
	cout << endl;

	delete[] d;
	/* КОНЕЦ DOUBLE */

	draw_line(widthLine);

	/* CHAR */
	char* ch = new char[n];

	switch (option) {
	case one:
		cout << "Enter the array elements of type CHAR:" << endl;
		input_mas(ch, n);
		break;
	case two:
		rand_mas(ch, n);
		break;
	default:
		cout << "Invalid data entered" << endl;
		exit(0);
		break;
	}

	cout << "Array of CHAR elements:" << endl;
	output_mas(ch, n);
	cout << endl;

	mergeSort(ch, 0, n - 1);
	cout << "Merge sort:" << endl;
	output_mas(ch, n);
	cout << endl;

	delete[] ch;
	/* КОНЕЦ CHAR	 */

	draw_line(widthLine);

	/* C-СТРОКИ */
	const int SIZE = 10;

	char** str = new char* [n];
	for (int i = 0; i < n; ++i) {
		str[i] = new char[SIZE];
	}

	switch (option) {
	case one:
		cout << "Enter n C-strings, where n = " << n << ":" << endl;
		for (int i = 0; i < n; ++i) {
			cin >> str[i];
		}
		break;
	case two:
		for (int i = 0; i < n; ++i) {
			rand_mas(str[i], SIZE);
		}
		break;
	default:
		cout << "Invalid data entered" << endl;
		exit(0);
		break;
	}

	cout << "Array of C-strings elements:" << endl;
	for (int i = 0; i < n; ++i) {
		output_c_mas(str[i], n);
	}
	cout << endl;

	mergeSort(str, 0, n - 1);
	cout << "Merge sort:" << endl;
	for (int i = 0; i < n; ++i) {
		output_c_mas(str[i], n);
	}
	cout << endl;

	for (int i = 0; i < n; ++i) {
		delete[] str[i];
	}
	delete[] str;
	/* КОНЕЦ C-СТРОКИ */

	draw_line(widthLine);

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}
