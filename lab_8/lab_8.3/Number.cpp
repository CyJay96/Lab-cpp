#include "Number.h"

Number::Number() {
	sign = true;
	clear();
}

Number::Number(int decData) {
	clear();
	sign = decData >= 0 ? true : false;
	decToBin(decData);
}

Number::Number(const Number& number) {
	clear();
	sign = number.sign;
	size = number.size;
	for (int i = 0; i < size; ++i) {
		num[i] = number.num[i];
	}
}

Number::~Number() {
	clear();
}

istream& operator>>(istream& in, Number& number) {
	int decData = 0;
	enter(in, decData);

	number.clear();
	number.sign = decData >= 0 ? true : false;
	number.decToBin(decData);

	return in;
}

ostream& operator<<(ostream& out, const Number& number) {
	out << number.binToDec();
	return out;
}

int& Number::operator[](int index) {
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

int Number::operator[](int index) const {
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

	clear();
	sign = number.sign;
	size = number.size;
	for (int i = 0; i < size; ++i) {
		num[i] = number[i];
	}

	return *this;
}

Number& Number::operator=(int decData) {
	clear();
	sign = decData >= 0 ? true : false;
	decToBin(decData);
	return *this;
}

Number Number::operator+(const Number& number) {
	Number result;

	if (size == 0 && number.size == 0) {
		return result;
	}

	result.size = size > number.size ? size : number.size;
	int memory = 0;

	for (int i = 0; i < result.size; ++i) {
		int res = num[i] + number.num[i] + memory;
		if (res <= 1) {
			result[i] = res;
			memory = 0;
		}
		else {
			result[i] = res % 2;
			memory = 1;
		}

		if (memory == 1 && i == result.size - 1) {
			result += 1;
		}
	}

	if (result[result.size - 1]) {
		result.sign = false;
	}

	return result;
}

Number Number::operator*(const Number& number) {
	Number result;

	if (size == 0 || number.size == 0) {
		return result;
	}

	Number this_num(*this);
	Number number_num(number);
	if (!this_num.sign) {
		this_num.sign = true;
		this_num.reverse();
	}
	if (!number_num.sign) {
		number_num.sign = true;
		number_num.reverse();
	}

	for (int i = 0; i < number_num.size; ++i) {
		if (number_num[i] == 1) {
			Number temp(this_num);
			temp = temp.shift(i);
			result += temp;
		}
	}
	
	while (!result[result.size - 1] && result.size > 0) {
		result.size--;
	}

	result.optimizeSize();

	result.sign = sign && number.sign || !sign && !number.sign;
	if (!result.sign) {
		result.reverse();
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

bool Number::operator==(const Number& number) {
	for (int i = 0; i < Number::bits; ++i) {
		if (num[i] != number.num[i]) {
			return false;
		}
	}

	return true;
}

bool Number::operator==(int number) {
	int decData = binToDec();
	return decData == number;
}

bool Number::operator!=(const Number& number) {
	return !(*this == number);
}

bool Number::operator!=(int number) {
	return !(*this == number);
}

void Number::decToBin(int data) {
	int absData = abs(data);

	int i = 0;
	while (absData) {
		if ((absData % 2) == 0) {
			num[i] = 0;
		}
		else {
			num[i] = 1;
		}
		absData /= 2;
		size++;
		i++;
	}

	optimizeSize();

	if (!sign) {
		reverse();
	}
}

int Number::binToDec() const {
	Number copy_num(*this);

	int decData = 0;

	if (!copy_num.sign) {
		copy_num.reverse();
	}

	for (int i = 0; i < size; ++i) {
		decData += copy_num[i] * pow(2, i);
	}

	return copy_num.sign ? decData : -decData;
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
}

Number Number::shift(int k) {
	Number result;
	result.size = size + k;

	for (int i = 0; i < size; ++i) {
		result[i + k] = num[i];
	}

	return result;
}

void Number::optimizeSize() {
	int byte = 8;
	int diffBits = byte - size % byte;
	size += diffBits;
}

void Number::clear() {
	size = 0;
	for (int i = 0; i < Number::bits; ++i) {
		num[i] = 0;
	}
}

void Number::setSize(int binSize) {
	try {
		if (binSize < 0) {
			throw binSize;
		}
	}
	catch (int) {
		cerr << "SIZE " << binSize << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	if (this->size > binSize) {
		for (int i = binSize; i < Number::bits; ++i) {
			num[i] = 0;
		}
	}
	this->size = binSize;
}

int Number::getSize(int data) {
	int size = 0;
	while (data) {
		size++;
		data /= 10;
	}

	try {
		if (size < 0 || size > Number::bits) {
			throw size;
		}
	}
	catch (int) {
		cerr << "SIZE " << size << " IS NOT ALLOWED" << endl;
		exit(0);
	}

	return size;
}

int Number::getSizeDec() {
	return getSize(binToDec());
}

int Number::getSizeBin() const {
	return size;
}

bool Number::getSign() const {
	return sign;
}
