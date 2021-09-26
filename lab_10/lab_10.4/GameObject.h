#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define ANIMATE_OBJECT "AnimateObject"
#define IN_ANIMATE_OBJECT "InAnimateObject"
#define STONE "Stone"
#define CHEST "Chest"
#define MERCHANT "Merchant"
#define CIVILIAN "Civilian"
#define PLAYER "Player"

enum Identifiers {
	STONE_ID = 1,
	CHEST_ID,
	MERCHANT_ID,
	CIVILIAN_ID,
	PLAYER_ID,
};

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
	int getX() const;
	int getY() const;

	virtual void input() = 0;
	virtual void print() const = 0;

	virtual void read(istream& in) = 0;
	virtual void write(ostream& out) const = 0;

	virtual const char* getType() const = 0;
	virtual GameObject* clone() const = 0;
};

ostream& operator<<(ostream& out, GameObject& obj) {
	if (&out == &cout) {
		obj.print();
	}
	else {
		obj.write(out);
	}

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

int GameObject::getX() const {
	return x;
}

int GameObject::getY() const {
	return y;
}