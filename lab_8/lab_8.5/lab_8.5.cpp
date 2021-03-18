/*

Дата сдачи: ...

Объявить шаблон класса «Двусвязный линейный список». Определить структуру класса и его методы.
В классе должен быть конструктор по умолча-нию, конструктор с формальными параметрами, конструктор копирования и де-структор.
Определить методы:
1) инициализация первого элемента структуры;
2) запись в структуру нового элемента;
3) удаление элемента;
4) поиск элемента по заданному ключу поиска (значению информационного поля);
5) вывод элементов списка на экран;
6) удаления всех элементов списка.
Используя объекты класса «Двусвязный линейный список», реализовать алгоритм своего варианта задания 7.6.

7.6:
Выполнить задания, используя двусвязные динамические структуры данных в виде связных компонент.
Оценить асимптотическую сложность алгоритма.

Даны натуральное число n, действительные числа x1, x2, ..., xn.
Разработать программу вычисления значения выражения следующего вида:
(x[1] + x[n]) * (x[2] + x[n-1]) * ... * (x[n] + x[1]).

*/


#include "List.h"

int main() {
	cout << "Enter the number of real numbers:" << endl;
	cout << "N = ";
	int n = 0;
	enter(cin, n);
	cout << endl;

	List<int> list;

	cout << "Enter real numbers:" << endl;
	list.input(n);

	cout << "Real numbers in ascending order:" << endl;
	list.output_start();
	cout << "Real numbers in descending order:" << endl;
	list.output_end();

	double res = list.solve();

	cout << endl << "Result of the expression:" << endl;
	cout << "(x[1] + x[n]) * (x[2] + x[n-1]) * ... * (x[n] + x[1]) = " << res << endl;

	/**/

	cout << endl << endl;

	int size = 5;
	List<int> list1(size, 8);
	cout << "list1 = ";
	list1.output_start();
	cout << endl;

	list1.push_back(1);
	list1.push_front(2);

	int pos = 4;
	list1.insert(3, pos);

	List<int> list2(list1);
	cout << "list2 (start) = ";
	list2.output_start();
	cout << endl;

	cout << "list2 (end) = ";
	list2.output_end();
	cout << endl;

	list2.pop_back();
	list2.pop_front();
	list2.removeAt(0);

	cout << "list2 = ";
	list2.output_start();
	cout << endl;

	cout << "size = " << list2.getSize() << endl;

	cout << "search = " << list2.search_data(3)->data << endl;

	/**/

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}