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
		exit(0);
	}

	name = "Matrix " + to_string(++counter);

	if (rows == 0 || cols == 0) {
		rowsSize = 0;
		colsSize = 0;
	}
	else {
		rowsSize = rows;
		colsSize = cols;

		Vector<double> temp;
		temp.setSize(rowsSize, 0);

		matrix.setSize(rowsSize, temp);
		for (int i = 0; i < rowsSize; ++i) {
			matrix[i].setSize(colsSize, 0);
		}
	}
}

Matrix::Matrix(const Matrix& mtrx) {
	name = "Matrix " + to_string(++counter);
	rowsSize = mtrx.rowsSize;
	colsSize = mtrx.colsSize;
	matrix = mtrx.matrix;
}

Matrix::~Matrix() {
	clear();
}

istream& operator>>(istream& in, Matrix& mtrx) {
	try {
		while (mtrx.rowsSize == 0) {
			cout << "Enter a non-sero number of rows: ";
			enter(in, mtrx.rowsSize);
		}
		while (mtrx.colsSize == 0) {
			cout << "Enter a non-zero number of cols: ";
			enter(in, mtrx.colsSize);
		}

		if (mtrx.rowsSize < 0) {
			throw mtrx.rowsSize;
		}
		if (mtrx.colsSize < 0) {
			throw mtrx.colsSize;
		}
	}
	catch (int invalidValue) {
		cerr << "WRONG SIZE " << invalidValue << endl;
		exit(0);
	}

	Vector<double> temp;
	temp.setSize(mtrx.rowsSize, 0);

	mtrx.matrix.setSize(mtrx.rowsSize, temp);
	for (int i = 0; i < mtrx.rowsSize; ++i) {
		mtrx.matrix[i].setSize(mtrx.colsSize, 0);
	}

	const short randomWay = 1;
	const short keyboardWay = 2;

	cout << "Choose how to fill the matrix (" << randomWay << "/" << keyboardWay << "):" << endl;
	cout << randomWay << ". Filling with random numbers." << endl;
	cout << keyboardWay << ". Keyboard input." << endl;

	int option = 0;
	enter(in, option);

	switch (option) {
	case randomWay:
		mtrx.fillRandom();
		cout << mtrx << endl;
		break;
	case keyboardWay:
		mtrx.fillKeyboard(in);
		break;
	default:
		cerr << "WRONG OPTION " << option << endl;
		exit(0);
	}
	cout << endl;

	return in;
}

ostream& operator<<(ostream& out, Matrix& mtrx) {
	out << mtrx.name << " (" << mtrx.rowsSize << "x" << mtrx.colsSize << "):" << endl;
	for (int i = 0; i < mtrx.rowsSize; ++i) {
		out << "||";
		for (int j = 0; j < mtrx.colsSize; ++j) {
			out << "\t" << mtrx.matrix[i][j] << "\t";
		}
		out << "||" << endl;
	}

	return out;
}

Vector<double>& Matrix::operator[](int index) {
	try {
		if (index < 0 || index >= rowsSize) {
			throw index;
		}

		return matrix[index];
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}
}

Vector<double>& Matrix::operator[](int index) const {
	try {
		if (index < 0 || index >= rowsSize) {
			throw index;
		}

		return matrix[index];
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}
}

Matrix Matrix::operator+(const Matrix& mtrx) {
	if (!isSameSizeWith(mtrx)) {
		cerr << "CAN'T ADD (WRONG SIZE)" << endl;
		exit(0);
	}

	Matrix result(rowsSize, colsSize);
	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < colsSize; ++j) {
			result[i][j] = matrix[i][j] + mtrx.matrix[i][j];
		}
	}

	return result;
}

Matrix Matrix::operator-(const Matrix& mtrx) {
	if (!isSameSizeWith(mtrx)) {
		cerr << "CAN'T SUBTRACT (WRONG SIZE)" << endl;
		exit(0);
	}

	Matrix result(rowsSize, colsSize);
	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < colsSize; ++j) {
			result[i][j] = matrix[i][j] - mtrx.matrix[i][j];
		}
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& mtrx) {
	if (!isCompatible(mtrx)) {
		cerr << "CAN'T MULTIPLY (WRONG SIZE)" << endl;
		exit(0);
	}

	Matrix result(rowsSize, mtrx.colsSize);
	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < mtrx.colsSize; ++j) {
			for (int k = 0; k < colsSize; ++k) {
				result.matrix[i][j] += matrix[i][k] * mtrx.matrix[k][j];
			}
		}
	}

	return result;
}

Matrix& Matrix::operator=(const Matrix& mtrx) {
	if (this == &mtrx) {
		return *this;
	}

	name = mtrx.name;
	rowsSize = mtrx.rowsSize;
	colsSize = mtrx.colsSize;
	matrix = mtrx.matrix;

	return *this;
}

Matrix& Matrix::operator+=(const Matrix& mtrx) {
	*this = *this + mtrx;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& mtrx) {
	*this = *this - mtrx;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& mtrx) {
	*this = *this * mtrx;
	return *this;
}

bool Matrix::operator==(const Matrix& mtrx) {
	if (!isSameSizeWith(mtrx)) {
		cerr << "CAN'T COMPARE (WRONG SIZE)" << endl;
		exit(0);
	}

	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < colsSize; ++j) {
			if (matrix[i][j] != mtrx.matrix[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix::operator!=(const Matrix& mtrx) {
	return !(*this == mtrx);
}

bool Matrix::isSameSizeWith(const Matrix& mtrx) {
	return rowsSize == mtrx.rowsSize && colsSize == mtrx.colsSize;
}

bool Matrix::isCompatible(const Matrix& mtrx) {
	return colsSize == mtrx.rowsSize;
}

bool Matrix::isSquared() {
	if (rowsSize == 0 || colsSize == 0) {
		return false;
	}
	return rowsSize == colsSize;
}

Matrix Matrix::getTransposed() {
	Matrix result(colsSize, rowsSize);
	for (int i = 0; i < colsSize; ++i) {
		for (int j = 0; j < rowsSize; ++j) {
			result[i][j] = matrix[j][i];
		}
	}

	return result;
}

Matrix Matrix::getRaisedIn(int power) {
	if (!isSquared()) {
		cerr << "CAN'T RAISE (WRONG SIZE)" << endl;
		exit(0);
	}

	Matrix result(*this);
	if (rowsSize != 0 && colsSize != 0) {
		if (power == 0) {
			result = getSingle();
		}
		else {
			for (int i = 0; i < power - 1; ++i) {
				result *= *this;
			}
		}
	}

	return result;
}

Matrix Matrix::getSingle() {
	Matrix result(*this);

	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < colsSize; ++j) {
			if (i == j) {
				result[i][j] = 1;
			}
			else {
				result[i][j] = 0;
			}
		}
	}

	return result;
}

Matrix Matrix::getZero() {
	Matrix result(*this);

	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < colsSize; ++j) {
			result[i][j] = 0;
		}
	}

	return result;
}

void Matrix::fillRandom() {
	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < colsSize; ++j) {
			matrix[i][j] = 10.0 + static_cast<double>(rand() % 90);
		}
	}
}

void Matrix::fillKeyboard(istream& in) {
	cout << "Enter the matrix elements:" << endl;
	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < colsSize; ++j) {
			enter(in, matrix[i][j]);
		}
	}
}

void Matrix::clear() {
	for (int i = 0; i < rowsSize; ++i) {
		matrix[i].clear();
	}
	matrix.clear();
}

void Matrix::setRows(int newRows) {
	try {
		if (newRows < 0) {
			throw newRows;
		}
	}
	catch (int) {
		cerr << "SIZE " << newRows << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	Matrix newMatrix(newRows, colsSize);
	for (int i = 0; i < newRows && i < rowsSize; ++i) {
		newMatrix[i] = matrix[i];
	}

	*this = newMatrix;
}

void Matrix::setCols(int newCols) {
	try {
		if (newCols < 0) {
			throw newCols;
		}
	}
	catch (int) {
		cerr << "SIZE " << newCols << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	Matrix newMatrix(rowsSize, newCols);
	for (int i = 0; i < rowsSize; ++i) {
		for (int j = 0; j < newCols && j < colsSize; ++j) {
			newMatrix[i][j] = matrix[i][j];
		}
	}

	*this = newMatrix;
}

string Matrix::getName() {
	return this->name;
}

int Matrix::getRows() {
	return this->rowsSize;
}

int Matrix::getCols() {
	return this->colsSize;
}
