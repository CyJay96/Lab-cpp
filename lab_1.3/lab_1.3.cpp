/*
Выполнить задание двумя способами: с использованием оператора if и с
использованием условного оператора ?. Выполнить задания, минимизируя
количество выполняемых операций сравнения и присваивания.
Даны действительные числа x, y, z. Поменять значения переменных так,
чтобы x < y < z.
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	double x, y, z;
	double x1, y1, z1;
	double k;

	cout << "Введите x, y, z: " << endl;
	cin >> x; x1 = x;
	cin >> y; y1 = y;
	cin >> z; z1 = z;

	if (x > y) {
		k = x;
		x = y;
		y = k;
	}

	if (y > z) {
		k = y;
		y = z;
		z = k;
	}

	if (x > y) {
		k = x;
		x = y;
		y = k;
	}

	cout << "Использование условного оператора if: " << endl;
	cout << x << " < " << y << " < " << z << endl << endl;

	x1 > y1 ? k = x1, x1 = y1, y1 = k : true;
	y1 > z1 ? k = y1, y1 = z1, z1 = k : true;
	x1 > y1 ? k = x1, x1 = y1, y1 = k : true;

	cout << "Использование условного оператора ?: " << endl;
	cout << x1 << " < " << y1 << " < " << z1 << endl;

	return 0;
}