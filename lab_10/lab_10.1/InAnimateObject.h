#pragma once
#include "GameObject.h"

class InAnimateObject : public GameObject {
protected:
	unsigned int width, height;

public:
	InAnimateObject();
	InAnimateObject(int x, int y, unsigned int width, unsigned int height);

	void print() override;

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

void InAnimateObject::print() {
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
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