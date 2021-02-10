/*

Дата сдачи: 14.12.2020

Дата последнего редактирования: 26.12.2020

Вычислить корень уравнения f(x) = 0 на отрезке [a; b] с точностью e = 10^–6,
используя заданный метод (М = 1 – метод половинного деления, М = 2 – метод
касательных, М = 3 – метод хорд) для заданных функций. Вычисление корня
уравнения оформить в виде функции с функциональным параметром, параметры
a, b, e, s – в виде аргументов по умолчанию.
Результат представить в виде таблицы (s – значение параметра, х – вычисленный
корень уравнения, f(x) – значение функции в найденной точке х, k_iter –
количество итераций цикла для получения корня с заданной точностью).

*/

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

enum WidthValues {
	widthS = 7,
	widthX = 12,
	widthY = 16,
	widthK = 5,

	widthLine = 37,
};

void draw_line() {
	for (int i = 0; i < widthLine; ++i) {
		cout << "-";
	}
	cout << endl;
}

double func1(double x) {
	double y = x * x * x - 3;

	return y;
}

void solve_equat1(double (*f)(double), double a = 1, double b = 4, double eps = 1e-6) {
	double y = 0;
	double ya = 0;
	double yb = 0;

	double c = 0;

	do {
		c = (a + b) / 2;

		y = f(c);
		ya = f(a);
		yb = f(b);

		if (y * ya <= 0) {
			b = c;
		}
		else {
			a = c;
		}
	} while (abs(a - b) > eps || abs(y) > eps);

	cout.width(15); cout << left << c;
	cout.width(15); cout << left << y << endl;
}

double func2(double x, double s) {
	const double pi = 3.141592653589793;

	return pow(x, 1.0 / s) - 2 * cos(pi * x / 2.0) * cos(pi * x / 2.0);
}

void solve_equat2(double s, double (*f)(double, double), double a = 0, double b = 4, double eps = 1e-6) {
	double y = 0;
	double ya = 0;
	double yb = 0;
	double c = 0;
	int k = 0;

	do {
		c = (a + b) / 2;
		k++;

		y = func2(c, s);
		ya = func2(a, s);
		yb = func2(b, s);

		if (y * ya <= 0) {
			b = c;
		}
		else {
			a = c;
		}
	} while (abs(a - b) > eps || abs(y) > eps);

	cout.width(widthS); cout << left << s;
	cout.width(widthX); cout << left << c;
	cout.width(widthY); cout << left << y;
	cout.width(widthK); cout << left << k << endl;
}

int main() {
	const double s0 = 0.5;
	const double sn = 2;
	const double ds = 0.5;

	cout << "a)" << endl;
	draw_line();
	cout.width(15); cout << left << "x";
	cout.width(15); cout << left << "y" << endl;
	draw_line();

	solve_equat1(func1); // вывов функции для пункта a)

	draw_line();
	cout << endl;
	cout << "b)" << endl;
	draw_line();
	cout.width(widthS); cout << left << "s";
	cout.width(widthX); cout << left << "x";
	cout.width(widthY); cout << left << "y";
	cout.width(widthK); cout << left << "k" << endl;
	draw_line();

	double s = s0;
	do {
		solve_equat2(s, func2); // вывов функции для пункта b)
		s += ds;
	} while (s < sn + ds / 2);

	draw_line();

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}