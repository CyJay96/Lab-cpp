#pragma once
#include "GameObject.h"

class InAnimateObject : public GameObject {
protected:
	unsigned int width, height;

public:
	InAnimateObject();
	InAnimateObject(int x, int y, unsigned int width, unsigned int height);

	void input() override;
	void print() const override;

	void read(istream& in) override;
	void write(ostream& out) const override;

	const char* getType() const override;
	InAnimateObject* clone() const override;

	void setWidth(int width);
	void setHeight(int height);
	unsigned int getWidth();
	unsigned int getHeight();
};

InAnimateObject::InAnimateObject() {
	x = y = 0;
	width = height = 0;
}

InAnimateObject::InAnimateObject(int x, int y, unsigned int width, unsigned int height) :
	width(width), height(height) {
	this->x = x;
	this->y = y;
}

void InAnimateObject::input() {
	cout << "Enter coordinates:" << endl;
	cout << "X = "; cin >> x;
	cout << "Y = "; cin >> y;
	cout << "Enter the width: "; cin >> width;
	cout << "Enter the height: "; cin >> height;
}

void InAnimateObject::print() const {
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
}

void InAnimateObject::read(istream& in) {
	in >> x;
	in >> y;
	in >> width;
	in >> height;
}

void InAnimateObject::write(ostream& out) const {
	out << x << endl;
	out << y << endl;
	out << width << endl;
	out << height << endl;
}

const char* InAnimateObject::getType() const {
	return IN_ANIMATE_OBJECT;
}

InAnimateObject* InAnimateObject::clone() const {
	return new InAnimateObject(x, y, width, height);
}

void InAnimateObject::setWidth(int width) {
	this->width = width;
}

void InAnimateObject::setHeight(int height) {
	this->height = height;
}

unsigned int InAnimateObject::getWidth() {
	return width;
}

unsigned int InAnimateObject::getHeight() {
	return height;
}