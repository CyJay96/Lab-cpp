/*

Дата сдачи: 04.03.2021

По заданной последовательности различных целых чисел построить соответствующее
бинарное дерево поиска T как динамическую структуру данных.
Выполнить следующие задания и вывести элементы дерева на экран.
Оценить асимптотическую сложность алгоритма.

Определить число листьев дерева.

8
20 10 8 12 30 25 34 22
k = 4

11
20 10 8 12 11 30 25 22 34 32 35
k = 5

*/


#include "functions.h"

int main() {
	cout << "Enter the number of tree elements:" << endl;
	cout << "N = ";
	int n = 0;
	enter(n);
	cout << endl;

	Tree* top = nullptr;

	cout << "Enter elements of the tree:" << endl;
	input(top, n);
	cout << endl;

	cout << "Elements of the tree displayed on the left:" << endl;
	outputLeft(top);
	cout << endl << endl;

	cout << "Elements of the tree displayed on the right:" << endl;
	outputRight(top);
	cout << endl << endl;

	int k = findLeaves(top);
	cout << endl << "The number of leaves of the tree: " << k << endl;

	delTree(top);

	cout << "Press any key to continue..." << endl;
	_getch();

	return 0;
}
