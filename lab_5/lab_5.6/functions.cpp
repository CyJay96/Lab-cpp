#include "functions.h"

void draw_line(int n) {
	for (int i = 0; i < n; ++i) {
		cout << "-";
	}
	cout << endl;
}

double func(double x, double s, double t) {
	return pow(t + x * x * x, 1 / s);
}

double sum(double a, double b, int n, double s, double t, double (*func)(double, double, double)) {
	double x = a;
	double sum = 0;

	double h = (b - a) / n;

	for (int i = 0; i < n; ++i) {
		x = a + i * h;
		sum += (*func)(x, s, t);
	}

	sum *= h;

	return sum;
}

double calcInt(double a, double b, double s, double t, int& k, double (*func)(double, double, double)) {
	double eps = 1e-6;

	int n = 4;
	double Int1 = 0;
	double Int2 = 0;

	Int1 = sum(n, a, b, s, t, func);

	do {
		Int2 = Int1;
		n *= 2;
		Int1 = sum(a, b, n, s, t, func);
		k++;
	} while (abs(Int1 - Int2) > eps);

	return Int1;
}