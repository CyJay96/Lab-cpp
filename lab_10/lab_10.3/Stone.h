#pragma once
#include "InAnimateObject.h"

class Stone : public InAnimateObject {
	unsigned int id;

public:
	Stone();
	Stone(int x, int y, unsigned int width, unsigned int height, unsigned int id);

	void input() override;
	void print() const override;

	void read(istream& in) override;
	void write(ostream& out) const override;

	const char* getType() const override;
	Stone* clone() const override;

	void setID(int id);
	int getID();
};

Stone::Stone() {
	x = y = 0;
	width = height = 0;
	id = 0;
}

Stone::Stone(int x, int y, unsigned int width, unsigned int height, unsigned int id) : id(id) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Stone::input() {
	InAnimateObject::input();
	cout << "Enter the ID: "; cin >> id;
}

void Stone::print() const {
	cout << getType() << endl;
	InAnimateObject::print();
	cout << "ID: " << id << endl;
}

void Stone::read(istream& in) {
	InAnimateObject::read(in);
	in >> id;
}

void Stone::write(ostream& out) const {
	out << STONE << endl;
	InAnimateObject::write(out);
	out << id << endl << endl;
}

const char* Stone::getType() const {
	return STONE;
}

Stone* Stone::clone() const {
	return new Stone(x, y, width, height, id);
}

void Stone::setID(int id) {
	this->id = id;
}

int Stone::getID() {
	return id;
}