#ifndef GameView_H
#define GameView_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameModel.h"
#include "GameController.h"

class GameView {
	GameModel *model;
	GameController *controller;
	sf::RenderWindow window;
public:
	GameView(GameModel &model, GameController &controller);
	void run();
	void process_draw();
	void process_logic();
	void process_events();
};

#endif