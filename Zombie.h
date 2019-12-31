#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "data.h"
#include "normalize.h"
#include "Player.h"
class Zombie
{
public:
	Zombie(Vector2f size, Vector2f position, Color color);
	virtual ~Zombie();
	void drawTo(RenderWindow& window);
	void rotateTo(float angle);
	void moveZombie(Vector2f direction);
	void lookAtPlayer(Player& player);
	FloatRect getGlobalBounds();
	bool isVisible;
private:
	RectangleShape* zRect;
};
#endif
