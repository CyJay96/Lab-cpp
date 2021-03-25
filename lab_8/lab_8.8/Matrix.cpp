#include "Matrix.h"

int Matrix::counter = 0;

Matrix::Matrix() {
	name = "Matrix " + to_string(++counter);
	rowsSize = 0;
	colsSize = 0;
}

Matrix::Matrix(int rows, int cols) {
	try {
		if (rows < 0) {
			throw rows;
		}
		if (cols < 0) {
			throw cols;
		}
	}
	catch (int invalidValue) {
		cout << "WRONG SIZE " << invalidValue << endl;
		exit(810);
	}

	name = "Matrix " + to_string(++counter);

	if (rows == 0 || cols == 0) {
		rowsSize = 0;
		colsSize = 0;
	}
	else {
		rowsSize = rows;
		colsSize = cols;
		//
	}
}

Matrix::Matrix(const Matrix& mtrx) {
	name = mtrx.name;
	rowsSize = mtrx.rowsSize;
	colsSize = mtrx.colsSize;
	matrix = mtrx.matrix;
}

Matrix::~Matrix() {
	for (int i = 0; i < rowsSize; ++i) {
		//matrix[i].
	}
}

Vector<double>& Matrix::operator[](int index) {
	try {
		if (index < 0 || index >= rowsSize) {
			throw index;
		}

		return matrix[i];
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(900);
	}
}