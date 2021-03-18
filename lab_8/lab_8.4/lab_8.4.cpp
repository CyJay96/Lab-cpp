/*

Дата сдачи: ...

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
	cout << l2 << endl;

	/**/

	int size = 5;
	List<int> list1(size, 8);
	cout << "list1 = " << list1 << endl;

	list1.push_back(1);
	list1.push_front(2);

	int pos = 4;
	list1.insert(3, pos);

	List<int> list2(list1);
	cout << "list2 = " << list2 << endl;

	list2.pop_back();
	list2.pop_front();
	list2.removeAt(0);

	cout << "list2 = " << list2 << endl;
	cout << "size = " << list2.getSize() << endl;

	/**/

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}