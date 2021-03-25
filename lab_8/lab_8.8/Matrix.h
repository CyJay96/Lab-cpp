#pragma once
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

class Matrix {
private:
	static int counter;
	string name;

	Vector<Vector<double>> matrix;

	int rowsSize;
	int colsSize;

public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& mtrx);

	~Matrix();

	Vector<double>& operator[](int index);
};