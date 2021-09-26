/*

Дата сдачи: 15.03.2021

Создать подходящий тип данных для представления графа. Написать и протестировать процедуры,
обеспечивающие добавление вершины в граф, вывода элементов графа на экран, выполнить следующие задания.
Количество вершин графа <= 65000, среднее число связей на вершину 6, ограничение по памяти 64 МiB.
Оценить асимптотическую сложность алгоритма.

Определить, что для любой пары вершин заданного орграфа одна из этих вершин достижима от другой.

*/


#include "Graf.h"

int main() {
	cout << "Enter the number of tree elements:" << endl;
	cout << "N = ";
	int n = 0;
	enter(cin, n);
	if (n > MAX_SIZE) {
		cout << "Too many graphs!" << endl;
		return 0;
	}
	cout << endl;

	Graf* top = nullptr;

	cout << "Enter elements of the graf:" << endl;
	input(top, n);
	cout << endl;

	cout << "Elements of the graf:" << endl;
	output(top);
	cout << endl;

	cout << "Enter the number of the first vertex: ";
	int ver1 = 0;
	enter(cin, ver1);

	cout << "Enter the number of the second vertex: ";
	int ver2 = 0;
	enter(cin, ver2);
	cout << endl;

	if (checkGraf(top, ver1, ver2)) {
		oneToOther(top, ver1, ver2);
		cout << endl;
	}

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}