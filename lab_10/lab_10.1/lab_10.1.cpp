﻿/*

Дата сдачи: 19.04.2021

1. Определить и описать иерархию классов: набор схожих по какому-либо критерию объектов, объединённых в подгруппы (родительские объекты).
Для каждого класса описать поля, характеризующие объект, и методы, позволяющие заполнять и получать значения каждого из полей,
выводить значения полей на экран, а также необходимые конструкторы. Общие свойства хранить в родительских классах.
- Конструкторы и методы должны проверять параметры на допустимость.
- Вывод свойств родительских классов осуществить с использованием наследования и полиморфизма (виртуальный метод Print(),
который вызывается из operator<< базового класса). Каждый класс должен уметь выводить в виде текста свой тип и набор своих свойств.
2. Обсудить схему с преподавателем.
3. Реализовать иерархию в коде.
4. Создать программу для тестирования описанных объектов, создающую и заполняющую свойства нескольких отдельных объектов,
а затем выводящую свойства всех созданных объектов на экран. Первичную инициализацию свойств объектов осуществите с помощью конструкторов.
Примечание 1: чтобы позднее такую иерархию классов было удобнее расширять, начинайте её с абстрактного базового класса.
Примечание 2: во всех вариантах предполагается не менее 3 уровней в иерархии наследования. Где удобно - добавляйте в иерархию не указанные
в задании абстрактные или обычные классы.
Примечание 3: использование С-строк обязательно (чтобы ошибки в использовании «правила трёх» стали явными).

Вы проектируете многопользовательскую 2D RPG игру с видом от третьего лица. В одной локации может находиться множество неподвижных предметов и игроков.
Для реализации прототипа игры вам надо разработать иерархию наследования классов, позволяющую хранить все эти сущности и их свойства в программе.
А именно:
1. Камень:
• координаты X и Y (целые);
• размеры - ширина и высота (целые беззнаковые);
• идентификатор картинки, отображаемой на месте предмета (число от 1 до 10000).
2. Сундук:
• координаты X и Y (целые);
• размеры - ширина и высота (целые беззнаковые);
• количество золотых монет в сундуке.
3. Торговец:
• текущие координаты X и Y (целые);
• имя;
• код типа продаваемых товаров (число от 1 до 100).
4. Мирный житель:
• текущие координаты X и Y (целые);
• имя.
5. Игроки:
• текущие координаты X и Y (целые);
• имя;
• цвет одежды.

*/


#include <iostream>
#include <conio.h>
#include "GameObject.h"
#include "Stone.h"
#include "Chest.h"
#include "Merchant.h"
#include "Civilian.h"
#include "Player.h"

using namespace std;

int main() {
	const int n = 5;

	GameObject* gameObject[n];

	gameObject[0] = new Stone(21, 15, 1, 4, 0);
	gameObject[1] = new Chest(12, 24, 4, 6, 114);
	gameObject[3] = new Merchant(36, 28, "Toha", 5);
	gameObject[2] = new Civilian(36, 28, "Kirill");
	gameObject[4] = new Player(38, 30, "Danila", "Black");

	for (int i = 0; i < n; ++i) {
		cout << (*gameObject[i]) << endl;
	}

	for (int i = 0; i < n; ++i) {
		delete gameObject[i];
	}

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}