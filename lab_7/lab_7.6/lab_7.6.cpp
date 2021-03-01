/*

Дата сдачи: 01.03.2021

Выполнить задания, используя двусвязные динамические структуры данных в виде связных компонент.
Оценить асимптотическую сложность алгоритма.

Даны натуральное число n, действительные числа x1, x2, ..., xn.
Разработать программу вычисления значения выражения следующего вида:
(x[1] + x[n]) * (x[2] + x[n-1]) * ... * (x[n] + x[1]).

*/


#include "functions.h"

int main() {
	cout << "Enter the number of real numbers:" << endl;
	cout << "N = ";
	int n = 0;
	enter(n);
	cout << endl;

	Node* top = nullptr;
	Node* end = nullptr;

	cout << "Enter real numbers:" << endl;
	input(top, end, n);

	cout << "Real numbers in ascending order:" << endl;
	outputStart(top);
	cout << "Real numbers in descending order:" << endl;
	outputEnd(end);

	double res = solve(top, end);

	cout << endl << "Result of the expression:" << endl;
	cout << "(x[1] + x[n]) * (x[2] + x[n-1]) * ... * (x[n] + x[1]) = " << res << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}
