#include "Player.h"


Player::Player(Vector2f size, Vector2f position, Color color) {
	this->pRect = new RectangleShape();
	this->pRect->setSize(size);
	this->pRect->setPosition(position);
	this->pRect->setFillColor(color);
}

Player::~Player() {
	delete[] this->pRect;
}

void Player::drawTo(RenderWindow& window) {
	window.draw(*this->pRect);
}

void Player::setHealth(float rhealth) {
	this->health = rhealth;
}

void Player::movePlayer(Vector2f direction) {
	this->pRect->move(direction);
}

void Player::setDirection(Direction direction) {
	this->pDirection = direction;
}

Vector2f Player::getPosition() {
	return this->pRect->getPosition();
}

Direction Player::getDirection() {
	return this->pDirection;
}

float Player::getHealth() {
	return this->health;
}