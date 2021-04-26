#pragma once
#include "GameObject.h"

class AnimateObject : public GameObject {
protected:
	char* name;

public:
	AnimateObject();
	AnimateObject(int x, int y, string name);
	AnimateObject(const AnimateObject& obj);

	~AnimateObject();

	void print() override;

	void setName(string name);
	char* getName();
};

AnimateObject::AnimateObject() {
	x = y = 0;
	name = nullptr;
}

AnimateObject::AnimateObject(int x, int y, string name) {
	this->x = x;
	this->y = y;
	setName(name);
}

AnimateObject::AnimateObject(const AnimateObject& obj) {
	x = obj.x;
	y = obj.y;
	setName(obj.name);
}

AnimateObject::~AnimateObject() {
	if (!name) {
		delete[] name;
		name = nullptr;
	}
}

void AnimateObject::print() {
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Name: " << name << endl;
}

void AnimateObject::setName(string name) {
	if (!this->name) {
		delete[] this->name;
		this->name = nullptr;
	}

	this->name = new char[name.size() + 1];
	for (int i = 0; i < name.size(); ++i) {
		this->name[i] = name[i];
	}
	this->name[name.size()] = '\0';
}

char* AnimateObject::getName() {
	return name;
}
