#pragma once
#include "AnimateObject.h"

class Merchant : public AnimateObject {
	unsigned int codeType;

public:
	Merchant();
	Merchant(int x, int y, string name, unsigned int codeType);
	Merchant(const Merchant& merchant);

	~Merchant();

	void print() override;

	void setCodeType(unsigned int codeType);
	unsigned int getCodeType();
};

Merchant::Merchant() {
	x = y = 0;
	name = new char[1];
	name[0] = '\0';
	codeType = 1;
}

Merchant::Merchant(int x, int y, string name, unsigned int codeType){
	this->x = x;
	this->y = y;
	setName(name);

	try {
		if (codeType < 1 || codeType > 100) {
			throw codeType;
		}
		this->codeType = codeType;
	}
	catch (unsigned int) {
		cerr << "CODE OF THE TYPE OF PRODUCT BEING SOLD " << codeType << " IS OUT OF RANGE" << endl;
		exit(0);
	}
}

Merchant::Merchant(const Merchant& merchant) {
	x = merchant.x;
	y = merchant.y;
	setName(merchant.name);
	codeType = merchant.codeType;
}

Merchant::~Merchant() {
	if (!name) {
		delete[] name;
		name = nullptr;
	}
}

void Merchant::print() {
	cout << "MERCHANT" << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Name: " << name << endl;
	cout << "Type of code: " << codeType << endl;
}

void Merchant::setCodeType(unsigned int codeType) {
	this->codeType = codeType;
}

unsigned int Merchant::getCodeType() {
	return codeType;
}