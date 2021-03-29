#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Vector.h"

using namespace std;

class Matrix {
private:
	static int counter;
	string name;

	Vector<Vector<double>> matrix;

	int rowsSize;
	int colsSize;

	friend istream& operator>>(istream& in, Matrix& mtrx);
	friend ostream& operator<<(ostream& out, Matrix& mtrx);

public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& mtrx);

	~Matrix();

	Vector<double>& operator[](int index);
	Vector<double>& operator[](int index) const;

	Matrix operator+(const Matrix& mtrx);
	Matrix operator-(const Matrix& mtrx);
	Matrix operator*(const Matrix& mtrx);

	Matrix& operator=(const Matrix& mtrx);

	Matrix& operator+=(const Matrix& mtrx);
	Matrix& operator-=(const Matrix& mtrx);
	Matrix& operator*=(const Matrix& mtrx);

	bool operator==(const Matrix& mtrx);
	bool operator!=(const Matrix& mtrx);

	bool isSameSizeWith(const Matrix& mtrx);
	bool isCompatible(const Matrix& mtrx);
	bool isSquared();

	Matrix getTransposed();
	Matrix getRaisedIn(int power);
	Matrix getSingle();
	Matrix getZero();

	void fillRandom();
	void fillKeyboard(istream& in);
	void clear();

	void setRows(int newRows);
	void setCols(int newCols);

	string getName();
	int getRows();
	int getCols();
};
