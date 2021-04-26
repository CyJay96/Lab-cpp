#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class GameObject {
protected:
	int x, y;

	friend ostream& operator<<(ostream& out, GameObject& obj);

public:
	GameObject();
	GameObject(int x, int y);

	virtual ~GameObject() = default;

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	virtual void print() = 0;
};

ostream& operator<<(ostream& out, GameObject& obj) {
	obj.print();
	return out;
}

GameObject::GameObject() {
	x = y = 0;
}

GameObject::GameObject(int x, int y) : x(x), y(y) {}

void GameObject::setX(int x) {
	this->x = x;
}

void GameObject::setY(int y) {
	this->y = y;
}

int GameObject::getX() {
	return x;
}

int GameObject::getY() {
	return y;
}
