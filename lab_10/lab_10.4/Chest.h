#pragma once
#include "InAnimateObject.h"

class Chest : public InAnimateObject {
	unsigned int coinsNum;

public:
	Chest();
	Chest(int x, int y, unsigned int width, unsigned int height, unsigned int coinsNum);

	void input() override;
	void print() const override;

	void read(istream& in) override;
	void write(ostream& out) const override;

	const char* getType() const override;
	Chest* clone() const override;

	void setCoinsNum(unsigned int coinsNum);
	unsigned int getCoinsNum();
};

Chest::Chest() {
	x = y = 0;
	width = height = 0;
	coinsNum = 0;
}

inline Chest::Chest(int x, int y, unsigned int width, unsigned int height, unsigned int coinsNum) : coinsNum(coinsNum) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Chest::input() {
	InAnimateObject::input();
	cout << "Enter number of coins: "; cin >> coinsNum;
}

void Chest::print() const {
	cout << getType() << endl;
	InAnimateObject::print();
	cout << "Number of coins: " << coinsNum << endl;
}

void Chest::read(istream& in) {
	InAnimateObject::read(in);
	in >> coinsNum;
}

void Chest::write(ostream& out) const {
	out << CHEST << endl;
	InAnimateObject::write(out);
	out << coinsNum << endl << endl;
}

const char* Chest::getType() const {
	return CHEST;
}

Chest* Chest::clone() const {
	return new Chest(x, y, width, height, coinsNum);
}

void Chest::setCoinsNum(unsigned int coinsNum) {
	this->coinsNum = coinsNum;
}

unsigned int Chest::getCoinsNum() {
	return coinsNum;
}