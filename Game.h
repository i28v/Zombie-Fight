#ifndef GAME_H
#define GAME_H
#include "data.h"
#include "settings.h"
#include "Player.h"
#include "Zombie.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void start();
private:
	RenderWindow* window;
	Event* event;
	Player* player;
	Zombie* zombies[50];
	unsigned int numberOfZombies;
	bool gameOver;
	bool paused;
	void init();
	void events(RenderWindow& twindow, Event& tevent);
	void input();
	void update();
	void draw(RenderWindow& twindow);
};
#endif
