#include "Zombie.h"

Zombie::Zombie(Vector2f size, Vector2f position, Color color) {
	this->zRect = new RectangleShape();
	this->zRect->setSize(size);
	this->zRect->setPosition(position);
	this->zRect->setFillColor(color);
	this->isVisible = true;
}

Zombie::~Zombie() {
	delete[] this->zRect;
}

void Zombie::drawTo(RenderWindow& window) {
	if (isVisible) {
		window.draw(*this->zRect);
	}
}

void Zombie::rotateTo(float angle) {
	this->zRect->rotate(angle);
}

void Zombie::moveZombie(Vector2f direction) {
	this->zRect->move(direction);
}

void Zombie::lookAtPlayer(Player& player) {
	sf::Clock clock;
	float delta = clock.restart().asSeconds() * 60;
	Vector2f direction = normalize(player.getPosition() - this->zRect->getPosition());
	this->moveZombie(delta * 200000 * direction);
}

FloatRect Zombie::getGlobalBounds() {
	return this->zRect->getGlobalBounds();
}