/*

Дата сдачи: 21.12.2020

Дата последнего редактирования: 26.12.2020

Вычислить следующие интегралы заданным методом (M = 1 – метод левых прямоугольников,
М = 2 – метод правых прямоугольников, М = 3 – метод средних прямоугольников, М = 4 –
метод трапеции, М = 5 – метод Симпсона.), воспользовавшись критерием двойного пересчета,
с точностью e = 10^–6.
Значения параметра s: si = [s1; s2], si = s1 + ids, i = 0, 1, ... .
Значения параметра t: ti = [t1; t2], ti = t1 + idt, i = 0, 1, ... .
Вычисление значения функции в точке оформить в виде функции, вычисление интеграла – в
виде функции с параметром функционального типа для задания функции. Процедуры оформить
в виде отдельного файла.
Результаты представить в виде таблицы (s, t – соответствующие значения параметров,
Int – вычисленное значение интеграла, k_iter – количество пересчетов значений интеграла
для получения заданной точности).

*/

#include "functions.h"

enum WidthValues {
	widthS = 15,
	widthT = 15,
	widthInt = 15,
	widthK = 15,

	widthLine = 48,
};

int main() {
	const double s1 = 1.5;
	const double s2 = 2.5;
	const double ds = 0.5;

	const double t1 = 0;
	const double t2 = 4;
	const double dt = 1;

	double a = 0.81;
	double b = 1.762;

	int k = 0;

	cout.width(widthS); cout << left << "S";
	cout.width(widthT); cout << left << "T";
	cout.width(widthInt); cout << left << "Int";
	cout.width(widthK); cout << left << "K" << endl;

	draw_line(widthLine);

	double s = s1;
	while (s < s2 + ds / 2) {
		double t = t1;
		while (t < t2 + dt / 2) {
			int k = 0;
			double Int = calcInt(a, b, s, t, k, &func);

			cout.width(widthS); cout << left << s;
			cout.width(widthT); cout << left << t;
			cout.width(widthInt); cout << left << setprecision(8) << Int;
			cout.width(widthK); cout << left << k << endl;

			t += ds;
		}
		s += ds;
		draw_line(widthLine);
	}

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}