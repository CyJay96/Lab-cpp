/*

Дата сдачи: 25.03.2021

Объявить шаблон класса «Граф». Определить структуру класса и его методы.
В классе должен быть конструктор по умолчанию, конструктор с формальными параметрами, конструктор копирования и деструктор.
Определить методы:
1) инициализация первого элемента структуры;
2) запись в структуру нового элемента;
3) удаление элемента;
4) вывод элементов графа на экран;
5) удаления всех элементов графа.

Используя объекты класса «Граф», реализовать алгоритм своего варианта задания 7.8.

7.8:
Создать подходящий тип данных для представления графа. Написать и протестировать процедуры,
обеспечивающие добавление вершины в граф, вывода элементов графа на экран, выполнить следующие задания.
Количество вершин графа <= 65000, среднее число связей на вершину 6, ограничение по памяти 64 МiB.
Оценить асимптотическую сложность алгоритма.

Определить, что для любой пары вершин заданного орграфа одна из этих вершин достижима от другой.

*/


#include "Graf.h"

const int MAX_SIZE = 65000;

int main() {
	cout << "Enter the number of graph's elements:" << endl;
	cout << "N = ";
	int n = 0;
	enter(cin, n);
	if (n > MAX_SIZE) {
		cout << "Too many graphs!" << endl;
		return 0;
	}
	cout << endl;

	Graf<int> graf;

	cout << "Enter elements of the graf:" << endl;
	graf.input(n);
	cout << endl;

	cout << "Elements of the graf:" << endl;
	graf.output();
	cout << endl;

	cout << "Enter the number of the first vertex: ";
	int ver1 = 0;
	enter(cin, ver1);

	cout << "Enter the number of the second vertex: ";
	int ver2 = 0;
	enter(cin, ver2);
	cout << endl;

	if (graf.checkGraf(ver1, ver2)) {
		graf.oneToOther(ver1, ver2);
	}

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}