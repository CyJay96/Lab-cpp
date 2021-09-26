#pragma once
#include "AnimateObject.h"

class Civilian : public AnimateObject {
public:
	Civilian();
	Civilian(int x, int y, string name);
	Civilian(const Civilian& civilian);

	~Civilian();

	void input() override;
	void print() const override;

	void read(istream& in) override;
	void write(ostream& out) const override;

	const char* getType() const override;
	Civilian* clone() const override;
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

Civilian::Civilian(const Civilian& civilian) {
	x = civilian.x;
	y = civilian.y;
	setName(civilian.name);
}

Civilian::~Civilian() {
	if (!name) {
		delete[] name;
		name = nullptr;
	}
}

void Civilian::input() {
	AnimateObject::input();
}

void Civilian::print() const {
	cout << getType() << endl;
	AnimateObject::print();
}

void Civilian::read(istream& in) {
	AnimateObject::read(in);
}

void Civilian::write(ostream& out) const {
	out << CIVILIAN << endl;
	AnimateObject::write(out);
	//cout << endl << endl << endl;
}

const char* Civilian::getType() const {
	return CIVILIAN;
}

Civilian* Civilian::clone() const {
	return new Civilian(x, y, name);
}