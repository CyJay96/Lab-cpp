/*

Дата сдачи: 19.04.2021

Выполнить задания с использованием подходящих связанных динамических структур данных. Оценить асимптотическую сложность алгоритма.
Написать программу, которая по заданному алгебраическому выражению (операнды – вещественные числа; операции: ( ) – + * / ) вычисляет результат.

6+(4-1)*2-3/(7+5)=
6 4 1 – 2 * + 3 7 5 + / - =

6+(5.45*3-2.45)*2-3/(7.3+4.7-2)=
6 5.45 3 * 2.45 - 2 * + 3 7.3 4.7 + 2 - / - =

*/


#include <iostream>
#include <string>
#include <conio.h>
#include "RPN.h"

using namespace std;

int main() {
	cout << "Enter an algebraic expression:" << endl;
	string expression;
	expression.clear();
	getline(cin, expression);

	string polExpression = convertToRPN(expression);
	double result = calculateRPN(polExpression);

	cout << "This expression in reverse Polish notation:" << endl;
	cout << polExpression << " " << result << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}