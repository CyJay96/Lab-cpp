/*

Дата сдачи: 25.03.2021

Реализовать решение задачи с использованием параметризированных классов vector и list
(указать лучший и объяснить почему).

Реализовать вариант заданий 7.4, используя объявление и методы соответствующего
параметризированного класса из стандартной библиотеки шаблонов STL.

7.4:
Выполнить задания, используя связанные динамические структуры данных в виде связных компонент.
Оценить асимптотическую сложность алгоритма.

Описать функцию, которая формирует список символов L2, включив в него те символы из L1, которые входят в него более одного раза.

L1:
q w e w r t r y u u w r q

L2:
q w r u

*/


#include "functions.h"

using namespace std;

int main() {
	cout << "Enter the number of L1 list's symbols:" << endl;
	cout << "N = ";
	int n = 0;
	enter(n);
	cout << endl;

	/* VECTOR */

	cout << "Vector:" << endl;

	vector<char> v1;
	vector<char> v2;

	cout << "Enter symbols of L1 list:" << endl;
	input(v1, n);
	cout << endl;

	createList(v1, v2);

	cout << "Symbols of L2 list:" << endl;
	output(v2);
	cout << endl << endl;

	/* LIST */

	cout << "List:" << endl;

	list<char> l1;
	list<char> l2;

	vectorToList(v1, l1);

	cout << "Symbols of L1 list:" << endl;
	output(l1);
	cout << endl << endl;

	createList(l1, l2);

	cout << "Symbols of L2 list:" << endl;
	output(l2);
	cout << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}