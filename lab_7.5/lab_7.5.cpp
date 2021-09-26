/*

Дата сдачи: 01.03.2021

Выполнить задания 7.4, используя связанные динамические структуры данных в виде массивов.

7.4:
Выполнить задания, используя связанные динамические структуры данных в виде связных компонент.
Оценить асимптотическую сложность алгоритма.

Описать функцию, которая формирует список символов L2, включив в него те символы из L1, которые входят в него более одного раза.

L1:
q w e w r t r y u u w q

L2:
q w r u

*/


#include "functions.h"

int main() {
	cout << "Enter the number of L1 list's symbols:" << endl;
	cout << "N = ";
	int n = 0;
	enter(n);
	cout << endl;

	char* list1 = new char[n];
	int* p1 = new int[n];
	p1[0] = 0;

	char* list2 = new char[n];
	int* p2 = new int[n];
	p2[0] = 0;

	cout << "Enter symbols of L1 list:" << endl;
	input(list1, p1, n);
	cout << endl;

	createList(list1, list2, p1, p2);

	cout << "L2 list:" << endl;
	output(list2, p2);
	cout << endl;

	delete[] list1, p1;
	delete[] list2, p2;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}