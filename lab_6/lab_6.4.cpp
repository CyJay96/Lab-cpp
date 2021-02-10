/*

Дата сдачи: ...

Дата последнего редактирования: 09.02.2021

Определить объединение с битовыми полями для представления заданной информации. Описать функцию
вывода полей на экран. Сгенерировать случайный массив таких структур. Отсортировать элементы массива
стандартной функцией std::sort. Найти повторяющиеся элементы и вывести их на экран.

Объединяющий тип double, битовые поля: знак, порядок, мантисса.

*/


#include <iostream>
#include <ctime>
#include <algorithm>
#include <conio.h>

using namespace std;

//union DoubleUnion {
//	double num;
//	struct InNumber {
//		unsigned mantissa : 52;
//		unsigned order : 11;
//		unsigned sign : 1;
//	} dataNum;
//};
//
//void generateData(DoubleUnion& st) {
//	st.numData.mantissa = rand() % 4503599627370496; // 2^52
//	st.numData.order = rand() % 2048; // 2^11
//	st.numData.sign = rand() % 2; // 2^1
//}

union DoubleUnion {
	float num;
	struct InNumber {
		unsigned mantissa : 23;
		unsigned order : 8;
		unsigned sign : 1;
	} numData;
};

void generateData(DoubleUnion& st) {
	st.numData.mantissa = rand() % 8388608; // 2^23
	st.numData.order = rand() % 256; // 2^8
	st.numData.sign = rand() % 2;
}

void print(DoubleUnion& st) {
	cout << "Number = " << st.num << "\t";
	cout << "Sign = " << st.numData.sign << "\t";
	cout << "Order = " << st.numData.order << "\t";
	cout << "Mantissa = "<< st.numData.mantissa << endl;
}

// компараторы для std::sort
bool compNum(DoubleUnion number1, DoubleUnion number2) {
	return number1.num < number2.num;
}

bool compMan(DoubleUnion mantissa1, DoubleUnion mantissa2) {
	return mantissa1.numData.mantissa < mantissa2.numData.mantissa;
}

bool compOrder(DoubleUnion order1, DoubleUnion order2) {
	return order1.numData.order < order2.numData.order;
}

bool compSign(DoubleUnion sign1, DoubleUnion sign2) {
	return sign1.numData.sign < sign2.numData.sign;
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));

	cout << "Enter the size of a random numbers:" << endl;
	int n = 0;
	cin >> n;

	DoubleUnion* numbers = new DoubleUnion[n];

	cout << endl << "Numbers:" << endl;
	for (int i = 0; i < n; ++i) {
		generateData(numbers[i]);
		print(numbers[i]);
	}

	sort(numbers, numbers + n, compNum);

	cout << endl << "Sort Numbers:" << endl;
	for (int i = 0; i < n; ++i) {
		print(numbers[i]);
	}

	cout << endl << "Repeating numbers:";
	bool no_repeat = true;
	for (int i = 0; i < n - 1; ++i) {
		double repeatNum = numbers[i].num;
		bool skip = false;
		for (int j = i + 1; j < n; ++j) {
			if (repeatNum == numbers[j].num) {
				cout << "Number = " << numbers[j].num << "\t";
				cout << "Sign = " << numbers[j].numData.sign << "\t";
				cout << "Order = " << numbers[j].numData.order << "\t";
				cout << "Mantissa = " << numbers[j].numData.mantissa << endl;

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

	cout << endl;

	if (no_repeat) {
		cout << "There are no repeating numbers" << endl;
	}

	delete[] numbers;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}