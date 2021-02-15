#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <conio.h>

using namespace std;

enum WidthValues {
	widthNum = 18,
	widthSign = 8,
	widthOrder = 10,
	widthMant = 12,

	widthLine = 44,
};

union DoubleUnion {
	double num;
	struct InNumber {
		unsigned long long mantissa : 52;
		unsigned long long order : 11;
		unsigned long long sign : 1;
	} numData;
};

void draw_line(int n);

void generateData(DoubleUnion& st);
void output(DoubleUnion& st);

bool compNum(DoubleUnion& number1, DoubleUnion& number2);