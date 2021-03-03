/*

Дата сдачи: ...

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

	cout << "Elements of the tree:" << endl;
	output(top);
	cout << endl;

	int k = findLeaves(top);
	cout << endl << "The number of leaves of the tree: " << k << endl;

	/*int k = 0;

	if (!top->left && !top->right) {
		k++;
	}

	Tree* top1 = top->left;
	Tree* top2 = top->right;

	if (!top1->left && !top1->right) {
		k++;
	}

	if (!top2->left && !top2->right) {
		k++;
	}

	cout << endl << "k = " << k << endl;*/

	delTree(top);

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}