﻿/*

Дата сдачи: 22.03.2021

Объявить шаблон класса «Бинарное дерево». Определить структуру класса и его методы.
В классе должен быть конструктор по умолчанию, конструктор с формальными параметрами, конструктор копирования и деструктор.
Определить методы:
1) инициализация первого элемента структуры;
2) запись в структуру нового элемента;
3) удаление элемента (листа);
4) поиск элемента по заданному ключу поиска (значению информационного поля);
5) вывод элементов дерева на экран;
6) удаления всех элементов дерева.
Используя объекты класса «Бинарное дерево», реализовать алгоритм своего варианта задания 7.7.

7.7:
По заданной последовательности различных целых чисел построить соответствующее бинарное дерево поиска T как динамическую структуру данных.
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


#include "Tree.h"

int main() {
	cout << "Enter the number of tree elements:" << endl;
	cout << "N = ";
	int n = 0;
	enter(cin, n);
	cout << endl;

	Tree<int> tree;

	cout << "Enter elements of the tree:" << endl;
	tree.input(n);
	cout << endl;

	cout << "Elements of the tree displayed on the left:" << endl;
	tree.output_left();
	cout << endl;

	cout << "Elements of the tree displayed on the right:" << endl;
	tree.output_right();
	cout << endl;

	int k = tree.findLeaves();
	cout << "The number of leaves of the tree: " << k << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}