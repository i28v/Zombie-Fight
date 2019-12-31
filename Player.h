#ifndef PLAYER_H
#define PLAYER_H
#include "data.h"
class Player
{
public:
	Player(Vector2f size, Vector2f position, Color color);
	virtual ~Player();
	void drawTo(RenderWindow& window);
	void setHealth(float rhealth);
	void movePlayer(Vector2f direction);
	void setDirection(Direction direction);
	float getHealth();
	Vector2f getPosition();
	Direction getDirection();
private:
	RectangleShape* pRect;
	Direction pDirection;
	float health;
};
#endif