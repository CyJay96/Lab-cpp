#pragma once
#include "AnimateObject.h"

class Player : public AnimateObject {
	char* colorClothes;

public:
	Player();
	Player(int x, int y, string name, string colorClothes);
	Player(const Player& player);

	~Player();

	void print() override;

	void setColorClothes(string colorClothes);
	char* getColorClothes();
};

Player::Player() {
	x = y = 0;
	name = new char[1];
	name[0] = '\0';
	colorClothes = new char[1];
	colorClothes[0] = '\0';
}

Player::Player(int x, int y, string name, string colorClothes) {
	this->x = x;
	this->y = y;
	setName(name);
	setColorClothes(colorClothes);
}

Player::Player(const Player& player) {
	x = player.x;
	y = player.y;
	setName(player.name);
	setColorClothes(player.colorClothes);
}

Player::~Player() {
	if (!name) {
		delete[] name;
		name = nullptr;
	}
	if (!this->colorClothes) {
		delete[] this->colorClothes;
		this->colorClothes = nullptr;
	}
}

void Player::print() {
	cout << "PLAYER" << endl;
	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Name: " << name << endl;
	cout << "Color of clothes: " << colorClothes << endl;
}

void Player::setColorClothes(string colorClothes) {
	if (!this->colorClothes) {
		delete[] this->colorClothes;
		this->colorClothes = nullptr;
	}

	this->colorClothes = new char[colorClothes.size() + 1];
	for (int i = 0; i < colorClothes.size(); ++i) {
		this->colorClothes[i] = colorClothes[i];
	}
	this->colorClothes[colorClothes.size()] = '\0';
}

char* Player::getColorClothes() {
	return colorClothes;
}