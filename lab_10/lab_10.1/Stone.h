#pragma once
#include "InAnimateObject.h"

class Stone : public InAnimateObject {
	unsigned int id;

public:
	Stone();
	Stone(int x, int y, unsigned int width, unsigned int height, unsigned int id);

	void print() override;

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

void Stone::print() {
	cout << "STONE" << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "ID: " << id << endl;
}

void Stone::setID(int id) {
	this->id = id;
}

int Stone::getID() {
	return id;
}