/*
Даны вещественные числа x, y. Определить, принадлежит ли точка с
координатами x, y заштрихованной части плоскости, включая границы.
Числа R, x, y вводятся с клавиатуры.
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	double r, x, y;

	cout << "Введите R, x, y: " << endl;

	cin >> r;
	cin >> x;
	cin >> y;

	if ((x >= 0) && (x <= r) && (y <= 0) && (abs(y) <= r)) {
		if (sqrt(pow((r - x), 2.0) + pow((r - abs(y)), 2.0)) > r) {

			cout << "Точка принадлежит" << endl;
		}
	}
	else if ((x <= 0) && (abs(x) <= r) && (y >= 0) && (y <= r)) {
		if (sqrt(pow((r - abs(x)), 2.0) + pow((r - y), 2.0)) > r) {

			cout << "Точка принадлежит" << endl;
		}
	}
	else {
		cout << "Точка не принадлежит" << endl;
	}

	return 0;
}