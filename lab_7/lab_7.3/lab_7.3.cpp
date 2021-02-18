/*﻿

Дата сдачи: ...

Создать связанную структуру данных – список. Разработать функции для выполнения базовых
операций над линейными связанными структурами, содержащими записи со сведениями о студентах:
ФИО, дата рождения, курс, успеваемость. При добавлении элемента данных в список обеспечить
упорядоченность по алфавиту фамилий. Оценить асимптотическую сложность алгоритма.

По исходному списку определить ФИО самого старшего студента на каждом курсе.
Сформировать список из этих студентов, удалив их из исходного списка.

*/


#include "functions.h"

int main() {
	setlocale(LC_ALL, "rus");

	Node* top = NULL;

	Node::Students* info = new Node::Students[N];

	ifstream read_file("students.txt");
	if (!read_file) {
		cout << "File error" << endl;
		return 1;
	}
	fillList(read_file, info);
	read_file.close();
	
	for (int i = 0; i < N; ++i) {
		add(top, info[i]);
	}

	output(top);

	delete[] info;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}