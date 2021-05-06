#pragma once
#include "AnimateObject.h"

class Player : public AnimateObject {
	char* colorClothes;

public:
	Player();
	Player(int x, int y, string name, string colorClothes);
	Player(const Player& player);

	~Player();

	void input() override;
	void print() const override;

	void read(istream& in) override;
	void write(ostream& out) const override;

	const char* getType() const override;
	Player* clone() const override;

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

void Player::input() {
	AnimateObject::input();
	cout << "Enter the color of clothes: "; cin >> colorClothes;
}

void Player::print() const {
	cout << getType() << endl;
	AnimateObject::print();
	cout << "Color of clothes: " << colorClothes << endl;
}

void Player::read(istream& in) {
	AnimateObject::read(in);
	in >> colorClothes;
}

void Player::write(ostream& out) const {
	out << PLAYER << endl;
	AnimateObject::write(out);
	out << colorClothes << endl << endl;
}

const char* Player::getType() const {
	return PLAYER;
}

Player* Player::clone() const {
	return new Player(x, y, name, colorClothes);
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