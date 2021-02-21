/*﻿

Дата сдачи: ...

Создать связанную структуру данных – список. Разработать функции для выполнения базовых
операций над линейными связанными структурами, содержащими записи со сведениями о студентах:
ФИО, дата рождения, курс, успеваемость. При добавлении элемента данных в список обеспечить
упорядоченность по алфавиту фамилий. Оценить асимптотическую сложность алгоритма.

По исходному списку определить ФИО самого старшего студента на каждом курсе.
Сформировать список из этих студентов, удалив их из исходного списка.

Базовые операции над списком:
• начальное формирование списка (создание первого элемента списка);
• добавление элемента в список;
• нахождение заданного элемента;
• вставка элемента в список;
• удаление элемента из списка;
• упорядочивание элементов списка;
• объединение двух списков;
• разделение списка на 2 списка;
• копирование списка;
• определение количества узлов списка;
• чтение и вывод всех элементов списка.

*/


#include "functions.h"

int main() {
	cout << "Enter the number of students:" << endl;
	cout << "N = ";
	int n = 0;
	cin >> n;
	cout << "Enter the students' details:" << endl;

	Node* top = nullptr;

	Node::Students* students = new Node::Students[n];
	Node::Students* studentsSort = new Node::Students[n];
	Node::Students* studentsOldest = new Node::Students[n];

	ofstream write_file("students.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 1;
	}
	fillList(write_file, students, n);
	write_file.close();
	
	for (int i = 0; i < n; ++i) {
		add(top, students[i]);
	}

	masToList(top, studentsSort);

	cout << endl << "List of students:" << endl;
	output(top);

	int k_oldest = searchOldest(students, studentsOldest, n);

	Node* oldestTop = nullptr;

	for (int i = 0; i < k_oldest; ++i) {
		add(oldestTop, studentsOldest[i]);
		del(top, studentsOldest[i]);
	}

	cout << endl << "List of students after deletion:" << endl;
	output(top);

	cout << endl << "List of oldest students:" << endl;
	output(oldestTop);

	delete[] students, studentsSort, studentsOldest;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}
