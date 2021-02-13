/*

Дата сдачи: 08.02.2021

Дата последнего редактирования: 13.02.2021

1) Дан массив чисел произвольной длины. Отсортировать массив сортировкой выбором и вставками.
2) Для тестирования программы заполнять массив значениями тремя способами:
по возрастанию, по убыванию, случайным образом.
3) Каждый метод сортировки, каждый способ заполнения массивов оформить отдельными функциями.
Функции оформить в виде отдельного файла.
4) Для каждого метода сортировки определить число сравнений и перемещений (перестановок с
одного места на другое) элементов в процессе выполнения программы.
5) Сравнить экспериментальные результаты с известными теоретическими оценками этих показателей
для заданных методов сортировки.
6) Обеспечить перегрузку и шаблоны необходимых функций для выполнения задания с типами элементов
массивов char, int, float, double.

*/

#include "functions.h"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	int n = 0;
	int option = 0;

	cout << "Enter the size of the array: ";
	input(n);
	cout << endl;

	cout << "Choose the method of filling the array:" << endl;
	cout << one << ". Ascending order" << endl; // по возрастанию
	cout << two << ". Descending order" << endl; // по убыванию
	cout << three << ". Random numbers" << endl;
	cout << four << ". Keyboard input" << endl;
	input(option);
	cout << endl;

	/* INT */
	int* a = new int[n];
	int* b = new int[n];

	switch (option) {
		case one:
			inc_mas(a, n);
			break;
		case two:
			dec_mas(a, n);
			break;
		case three:
			rand_mas(a, n);
			break;
		case four:
			cout << "Enter the array elements of type INT:" << endl;
			input_mas(a, n);
			break;
		default:
			cout << "Invalid data entered" << endl;
			return 0;
			break;
	}

	cout << "Array of INT elements:" << endl;
	for (int i = 0; i < n; ++i) {
		b[i] = a[i];
		cout << a[i] << " ";
	}
	cout << endl << endl;

	draw_line(widthLine);

	/* СОРТИРОВКА ВЫБОРОМ */
	int compare = 0;
	int move = 0;

	selectSort(a, n, compare, move);
	cout << "Sorting by choice:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl << endl;

	cout << "Experimental results:" << endl;
	cout << "1. Number of comparisons = " << compare << endl;
	cout << "2. Number of moves = " << move << endl << endl;

	cout << "Theoretical estimates:" << endl;

	compare = (n * n - n) / 2;
	cout << "1. Number of comparisons = " << compare << endl;

	cout << "2. Number of moves:" << endl;
	cout << "  а) Minimum = "; move = 3 * (n - 1); cout << move << endl;
	cout << "  б) Average = "; move = static_cast<int>(n * (log(n) + y)); cout << move << endl;
	cout << "  в) Maximum = "; move = static_cast<int>(n * n / 4) + 3 * (n - 1); cout << move << endl;
	/* КОНЕЦ СОРТИРОВКИ ВЫБОРОМ */

	draw_line(widthLine);
	cout << endl;

	/*СОРТИРОВКА ВСТАВКАМИ */
	compare = 0;
	move = 0;

	insertSort(b, n, compare, move);
	cout << "The insertion sort:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << b[i] << " ";
	}
	cout << endl << endl;

	cout << "Experimental results:" << endl;
	cout << "1. Number of comparisons = " << compare << endl;
	cout << "2. Number of moves = " << move << endl << endl;

	cout << "Theoretical estimates:" << endl;

	cout << "1. Number of comparisons:" << endl;
	cout << "  а) Minimum = "; compare = n - 1; cout << compare << endl;
	cout << "  б) Average = "; compare = (n * n - n) / 2; cout << compare << endl;
	cout << "  в) Maximum = "; compare = (n * n + n) / 2 - 1; cout << compare << endl;

	cout << "2. Number of moves:" << endl;
	cout << "  а) Minimum = "; move = 2 * (n - 1); cout << move << endl;
	cout << "  б) Average = "; move = (n * n + 3 * n - 4) / 3; cout << move << endl;
	cout << "  в) Maximum = "; move = (n * n + 9 * n - 10) / 4; cout << move << endl;
	/* КОНЕЦ СОРТИРОВКИ ВСТАВКАМИ */

	delete[] a, b;
	/* КОНЕЦ INT */

	draw_line(widthLine);
	cout << endl;

	/* CHAR */
	char* ch1 = new char[n];
	char* ch2 = new char[n];

	switch (option) {
	case one:
		inc_mas(ch1, n);
		break;
	case two:
		dec_mas(ch1, n);
		break;
	case three:
		rand_mas(ch1, n);
		break;
	case four:
		cout << "Enter the array elements of type CHAR:" << endl;
		input_mas(ch1, n);
		break;
	default:
		cout << "Invalid data entered" << endl;
		return 0;
		break;
	}

	cout << "Array of CHAR elements:" << endl;
	for (int i = 0; i < n; ++i) {
		ch2[i] = ch1[i];
		cout << ch1[i] << " ";
	}
	cout << endl << endl;

	selectSort(ch1, n);
	cout << "Sorting by choice:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << ch1[i] << " ";
	}
	cout << endl;

	insertSort(ch2, n);
	cout << "The insertion sort:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << ch2[i] << " ";
	}
	cout << endl;

	delete[] ch1, ch2;
	/* КОНЕЦ CHAR */

	draw_line(widthLine);
	cout << endl;

	/* DOUBLE */
	double* d1 = new double[n];
	double* d2 = new double[n];

	switch (option) {
	case one:
		inc_mas(d1, n);
		break;
	case two:
		dec_mas(d1, n);
		break;
	case three:
		rand_mas(d1, n);
		break;
	case four:
		cout << "Enter the array elements of type DOUBLE:" << endl;
		input_mas(d1, n);
		break;
	default:
		cout << "Invalid data entered" << endl;
		return 0;
		break;
	}

	cout << "Array of DOUBLE elements:" << endl;
	for (int i = 0; i < n; ++i) {
		d2[i] = d1[i];
		cout << d1[i] << " ";
	}
	cout << endl << endl;

	selectSort(d1, n);
	cout << "Sorting by choice:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << d1[i] << " ";
	}
	cout << endl;

	insertSort(d2, n);
	cout << "The insertion sort:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << d2[i] << " ";
	}
	cout << endl;

	delete[] d1, d2;
	/* КОНЕЦ DOUBLE */

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}
