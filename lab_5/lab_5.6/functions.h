#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

void draw_line(int n);
double func(double x, double s, double t);
double sum(double a, double b, int n, double s, double t, double (*func)(double, double, double));
double calcInt(double a, double b, double s, double t, int& k, double (*func)(double, double, double));