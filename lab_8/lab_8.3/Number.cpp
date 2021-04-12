#include "Number.h"

Number::Number() {
	clear();
}

Number::Number(long long decData) {
	clear();
	decToBin(decData);
}

Number::Number(string binData) {
	clear();
	for (int i = 0; i < binData.size(); ++i) {
		num[i] = binData[binData.size() - i - 1] - 48;
	}
}

Number::Number(const Number& number) {
	for (int i = 0; i < size; ++i) {
		num[i] = number.num[i];
	}
}

Number::~Number() {
	clear();
}

istream& operator>>(istream& in, Number& number) {
	long long decData = 0;
	enter(in, decData);

	number.clear();
	number.decToBin(decData);

	return in;
}

ostream& operator<<(ostream& out, const Number& number) {
	out << number.binToDec();
	return out;
}

bool& Number::operator[](int index) {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	return num[index];
}

bool Number::operator[](int index) const {
	try {
		if (index < 0 || index >= size) {
			throw index;
		}
	}
	catch (int) {
		cerr << "INDEX " << index << " IS OUT OF RANGE" << endl;
		exit(0);
	}

	return num[index];
}

Number& Number::operator=(const Number& number) {
	if (this == &number) {
		return *this;
	}

	for (int i = 0; i < size; ++i) {
		num[i] = number[i];
	}

	return *this;
}

Number& Number::operator=(long long decData) {
	clear();
	decToBin(decData);
	return *this;
}

Number& Number::operator=(string binData) {
	clear();
	for (int i = 0; i < binData.size(); ++i) {
		num[i] = binData[binData.size() - i - 1] - 48;
	}
	return *this;
}

Number Number::operator+(const Number& number) {
	Number result;

	int memory = 0;

	for (int i = 0; i < size; ++i) {
		int res = num[i] + number.num[i] + memory;
		if (res <= 1) {
			result[i] = res;
			memory = 0;
		}
		else {
			result[i] = res % 2;
			memory = 1;
		}
	}

	return result;
}

Number Number::operator*(const Number& number) {
	Number result;

	for (int i = 0; i < size; ++i) {
		if (number[i] == 1) {
			Number temp(*this);
			temp = temp.shift(i);
			result += temp;
		}
	}

	return result;
}

Number Number::operator^(const Number& power) {
	Number result(*this);

	int powDec = power.binToDec();
	if (powDec <= 0) {
		return 0;
	}
	else {
		for (int i = 0; i < powDec - 1; ++i) {
			result *= *this;
		}
	}

	return result;
}

Number Number::operator^(int power) {
	Number result(*this);

	if (power <= 0) {
		return 0;
	}
	else {
		for (int i = 0; i < power - 1; ++i) {
			result *= *this;
		}
	}

	return result;
}

Number& Number::operator+=(const Number& number) {
	*this = *this + number;
	return *this;
}

Number& Number::operator*=(const Number& number) {
	*this = *this * number;
	return *this;
}

Number& Number::operator^=(const Number& power) {
	*this = *this ^ power;
	return *this;
}

Number& Number::operator^=(int power) {
	*this = *this ^ power;
	return *this;
}

void Number::decToBin(long long data) {
	long long absData = abs(data);

	int i = 0;
	while (absData) {
		if ((absData % 2) == 0) {
			num[i] = 0;
		}
		else {
			num[i] = 1;
		}
		absData /= 2;
		i++;
	}

	if (data < 0) {
		reverse();
	}
}

long long Number::binToDec() const {
	long long decData = 0;

	long long power = 1;
	for (int i = 0; i < size - 1; ++i) {
		decData += (*this)[i] * power;
		power *= 2;
	}
	decData -= (*this)[size - 1] * power;

	return decData;
}

void Number::printBinary() {
	int fourBits = 4;

	if (size == 0) {
		for (int i = 0; i < 2 * fourBits; ++i) {
			if (i > 0 && i % fourBits == 0) {
				cout << " ";
			}
			cout << "0";
		}
	}

	for (int i = size - 1; i >= 0; --i) {
		if (i < size - 1 && (i + 1) % fourBits == 0) {
			cout << " ";
		}
		cout << num[i];
	}
}

void Number::reverse() {
	for (int i = 0; i < size; ++i) {
		num[i] = !num[i];
	}
	*this += 1;
}

Number Number::shift(int k) {
	Number result;

	for (int i = 0; i + k < size; ++i) {
		result[i + k] = num[i];
	}

	return result;
}

void Number::clear() {
	for (int i = 0; i < size; ++i) {
		num[i] = 0;
	}
}
