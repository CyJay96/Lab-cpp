﻿/*

Дата сдачи: 22.03.2021

Объявить шаблон класса «Линейный список». Определить структуру класса и его методы.
В классе должен быть конструктор по умолчанию, конструктор с формальными параметрами, конструктор копирования и деструктор.
Определить методы:
1) инициализация первого элемента структуры;
2) добавления в структуру нового элемента;
3) удаление элемента;
4) поиск элемента по заданному ключу поиска (значению информационного поля);
5) вывод элементов списка на экран;
6) удаления списка.
Используя объекты класса «Линейный список», реализовать алгоритмы своих вариантов заданий 7.4.

7.4:
Выполнить задания, используя связанные динамические структуры данных в виде связных компонент.
Оценить асимптотическую сложность алгоритма.

Описать функцию, которая формирует список символов L2, включив в него те символы из L1, которые входят в него более одного раза.

L1:
q w e w r t r y u u w r q

L2:
q w r u

*/


#include "List.h"

int main() {
	cout << "Enter the number of L1 list's symbols:" << endl;
	cout << "N = ";
	int n = 0;
	enter(cin, n);
	cout << endl;

	List<char> l1;
	List<char> l2;

	cout << "Enter symbols of L1 list:" << endl;
	l1.input(n);
	cout << endl;

	l2.createList(l1);

	cout << "L2 list:" << endl;
	l2.output();

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}