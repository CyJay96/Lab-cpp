#pragma once
#include "InAnimateObject.h"

class Chest : public InAnimateObject {
	unsigned int coinsNum;

public:
	Chest();
	Chest(int x, int y, unsigned int width, unsigned int height, unsigned int coinsNum);

	void print() override;

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

void Chest::print() {
	cout << "CHEST" << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Number of coins: " << coinsNum << endl;
}

void Chest::setCoinsNum(unsigned int coinsNum) {
	this->coinsNum = coinsNum;
}

unsigned int Chest::getCoinsNum() {
	return coinsNum;
}