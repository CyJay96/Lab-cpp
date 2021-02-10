/*﻿

Дата сдачи: ...

Дата последнего редактирования: 10.02.2021

Создать связанную структуру данных – список. Разработать функции для выполнения базовых
операций над линейными связанными структурами, содер-жащими записи со сведениями о студентах:
ФИО, дата рождения, курс, успеваемость. При добавлении элемента данных в список обеспечить
упорядоченность по алфавиту фамилий. Оценить асимптотическую сложность алгоритма.

По исходному списку определить ФИО самого старшего студента на каж-дом курсе.
Сформировать список из этих студентов, удалив их из исходного списка.

*/


#include <iostream>
#include <string>

using namespace std;

struct link {
	string Name;
	string Birthday;
	int Course;
	double Mark; // некоторые данные
	link* next; // указатель на следующую структуру
};

void find_gt(link* top, string key, link*& ppv) { //поиск места для вставки нового элемента
	link* pv = top;
	ppv = top;
	//поиск элемента c ключом > key
	while (pv && pv->Name <= key) {
		ppv = pv;   // запоминаем адрес предыдущего элемента
		pv = pv->next;
	}
}

void add(link*& top, string Name, string Birthday, int Course, double Mark) { //Добавление нового элемента с сортировкой по алфавиту
	link* nv, * ppv = NULL;
	nv = new link; // образуем новый элемент списка
	nv->Name = Name;
	nv->Birthday = Birthday;
	nv->Course = Course;
	nv->Mark = Mark;
	nv->next = NULL;
	if (!top) {// если список пуст  
		top = nv; // первый элемент списка
	}
	else {
		if (top->Name >= Name) { // вставляем в начало списка                
			nv->next = top;
			top = nv;
		}
		else {
			find_gt(top, Name, ppv);
			// поиск по ключу места для нового элемента
			nv->next = ppv->next;
			// вставляем между элементами с адресами ppv и pv 
			ppv->next = nv;
		}
	}
}

void vyvod(link* top) { //Вывод списка
	while (top) {
		cout << top->Name << "  " << top->Birthday << " " << top->Course << "   " << top->Mark << endl;
		top = top->next;
	}
}

void find_eq(link* top, double key, link*& ppv) {
	link* pv = top;
	ppv = pv;
	do {
		if (pv->Mark < key) {
			return; // останавливаем проход массива
		}
		ppv = pv; // запоминаем предыдущий элемент
		pv = pv->next;
	} while (pv);
	ppv = NULL; // нету больше студентов с оценкой больше порога
}

void del(link*& top, double key, link*& bad_top) {
	link* pv, * ppv;
	// поиск элемента с ключом < key
	do {
		find_eq(top, key, ppv);
		if (ppv) {
			if (ppv == top) { // ели нужно убрать первый элемент
				add(bad_top, top->Name, top->Birthday, top->Course, top->Mark);
				top = top->next;
			}
			else { // нужно убрать следующий элемент
				pv = ppv->next;
				add(bad_top, pv->Name, pv->Birthday, pv->Course, pv->Mark);
				ppv->next = pv->next;
			}
		}
	} while (ppv && top);
}

int main() {
	link* top = NULL;

	cout << "Enter quantity of students: ";
	int quantity;
	cin >> quantity;

	string Name = "";
	string Birthday = "";
	int Course;
	double Mark;

	for (int i = 0; i < quantity; i++) {
		cout << "Enter name: ";
		//getline(cin, Name);
		cin >> Name;
		cout << "Enter birthday: ";
		//getline(cin, Birthday);
		cin >> Birthday;
		cout << "Enter course: ";
		cin >> Course;
		cout << "Enter mark: ";
		cin >> Mark;

		add(top, Name, Birthday, Course, Mark);
	}

	vyvod(top);
	cout << "Enter the lowest posible mark: ";
	double Low_Mark;
	cin >> Low_Mark;

	link* bad_top = NULL;

	del(top, Low_Mark, bad_top);
	cout << "Good students:" << endl;
	vyvod(top);
	cout << "Bad students:" << endl;
	vyvod(bad_top);
	return 0;
}