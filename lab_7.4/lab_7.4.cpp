/*

Дата сдачи: 25.02.2021

Выполнить задания, используя связанные динамические структуры данных в виде связных компонент.
Оценить асимптотическую сложность алгоритма.

Описать функцию, которая формирует список символов L2, включив в него те символы из L1, которые входят в него более одного раза.

L1:
q w e w r t r y u u w r

L2:
w r u

*/


#include "functions.h"

int main() {
	cout << "Enter the number of L1 list's symbols:" << endl;
	cout << "N = ";
	int n = 0;
	enter(n);
	cout << endl;

	Node* top1 = nullptr;
	Node* top2 = nullptr;

	cout << "Enter symbols of L1 list:" << endl;
	input(top1, n);
	cout << endl;

	createList(top1, top2);

	cout << "L2 list:" << endl;
	output(top2);
	cout << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}