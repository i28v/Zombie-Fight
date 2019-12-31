#include "Game.h"

Game::Game() {

}

Game::~Game() {
	delete[] this->window;
	delete[] this->event;
	delete[] this->player;
	for (int i = 0; i < 50; i++) {
		delete[] this->zombies[i];
	}
}

void Game::init() {
	srand(time(NULL));
	rand();
	this->window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, WINDOW_TYPE);
	this->event = new Event;
	this->player = new Player({ 40, 40 }, { 800 / 2, 600 / 2 }, Color::Green);
	this->numberOfZombies = 10;
	for (int i = 0; i < 50; i++) {
		this->zombies[i] = new Zombie({ 40, 40 }, { static_cast<float>(rand() % WINDOW_WIDTH), static_cast<float>(rand() % WINDOW_HEIGHT) }, Color::Red);
	}
	
}

void Game::events(RenderWindow& twindow, Event& tevent) {
	while (twindow.pollEvent(tevent)) {
		if (tevent.type == Event::Closed) twindow.close();
	}
}

void Game::input() {
	if (Keyboard::isKeyPressed(Keyboard::W)) this->player->setDirection(Direction::Up);
	if (Keyboard::isKeyPressed(Keyboard::S)) this->player->setDirection(Direction::Down);
	if (Keyboard::isKeyPressed(Keyboard::A)) this->player->setDirection(Direction::Left);
	if (Keyboard::isKeyPressed(Keyboard::D)) this->player->setDirection(Direction::Right);
	if (Keyboard::isKeyPressed(Keyboard::P)) this->paused = true;
	if (Keyboard::isKeyPressed(Keyboard::R)) this->paused = false;
	else if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S) &&
		!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
		this->player->setDirection(Direction::Still);
	}

}

void Game::update() {
	for (int i = 0; i < 50; i++) {
		this->zombies[i]->lookAtPlayer(*this->player);
	}
	switch (this->player->getDirection()) {
	case Direction::Up:
		this->player->movePlayer({ 0, -5 });
		break;
	case Direction::Down:
		this->player->movePlayer({ 0, 5 });
		break;
	case Direction::Left:
		this->player->movePlayer({-5, 0});
		break;
	case Direction::Right:
		this->player->movePlayer({ 5, 0 });
		break;
	default:
		break; 
	}
}

void Game::draw(RenderWindow& twindow) { 
	twindow.clear();
	this->player->drawTo(twindow);
	for (int i = 0; i < 50; i++) {
		this->zombies[i]->drawTo(twindow);
	}
	twindow.display();
}

void Game::start() { 
	
	 init(); 
	 while (this->window->isOpen()) 
	 {
		 this->events(*this->window, *this->event); 
		 this->input(); 
		 if (!this->paused) {
			 this->update();
			 this->draw(*this->window);
			 Sleep(FRAME_RATE);
		 }
	 }
}