#pragma once
#include "AnimateObject.h"

class Civilian : public AnimateObject {
public:
	Civilian();
	Civilian(int x, int y, string name);
	Civilian(const Civilian& merchant);

	~Civilian();

	void print() override;
};

Civilian::Civilian() {
	x = y = 0;
	name = new char[1];
	name[0] = '\0';
}

Civilian::Civilian(int x, int y, string name) {
	this->x = x;
	this->y = y;
	setName(name);
}

Civilian::Civilian(const Civilian& merchant) {
	x = merchant.x;
	y = merchant.y;
	setName(merchant.name);
}

Civilian::~Civilian() {
	if (!name) {
		delete[] name;
		name = nullptr;
	}
}

void Civilian::print() {
	cout << "CIVILIAN" << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Name: " << name << endl;
}