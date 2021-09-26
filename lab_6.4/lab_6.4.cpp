/*

Дата сдачи: 15.02.2021

Определить объединение с битовыми полями для представления заданной информации. Описать функцию
вывода полей на экран. Сгенерировать случайный массив таких структур. Отсортировать элементы массива
стандартной функцией std::sort. Найти повторяющиеся элементы и вывести их на экран.

Объединяющий тип double, битовые поля: знак, порядок, мантисса.

*/


#include "functions.h"

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	cout << "Enter the number of random numbers:" << endl;
	int n = 0;
	cin >> n;
	cout << endl;

	DoubleUnion* numbers = new DoubleUnion[n];

	cout.width(widthNum); cout << left << "Number";
	cout.width(widthSign); cout << left << "Sign";
	cout.width(widthOrder); cout << left << "Order";
	cout.width(widthMant); cout << left << "Mantissa" << endl;

	draw_line(widthLine);

	for (int i = 0; i < n; ++i) {
		generateData(numbers[i]);
		output(numbers[i]);
	}

	sort(numbers, numbers + n, compNum);

	draw_line(widthLine);
	cout << "Sort Numbers:" << endl;
	draw_line(widthLine);

	for (int i = 0; i < n; ++i) {
		output(numbers[i]);
	}

	cout << endl << "Repeating numbers:" << endl;
	bool no_repeat = true;
	for (int i = 0; i < n - 1; ++i) {
		double repeatNum = numbers[i].num;
		bool skip = false;
		for (int j = i + 1; j < n; ++j) {
			if (repeatNum == numbers[j].num) {
				output(numbers[j]);
				no_repeat = false;
				skip = true;
				break;
			}
		}
		if (skip) {
			while (numbers[i].num == numbers[i + 1].num) {
				i++;
			}
		}
	}

	if (no_repeat) {
		cout << "There are no repeating numbers" << endl;
	}

	delete[] numbers;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}