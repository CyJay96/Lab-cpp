#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

enum WidthValues {
	widthS = 15,
	widthT = 15,
	widthInt = 15,
	widthK = 15,

	widthLine = 48,
};

void draw_line(int n);
double func(double x, double s, double t);
double sum(double a, double b, int n, double s, double t, double (*func)(double, double, double));
double calcInt(double a, double b, double s, double t, int& k, double (*func)(double, double, double));