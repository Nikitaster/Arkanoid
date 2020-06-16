#ifndef GameView_H
#define GameView_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameModel.h"
#include "GameController.h"
#include "GameBackgroundSprite.h"

class GameView {
	GameModel *model;
	GameController *controller;
	sf::Sprite background_sprite;
	GameBackgroundSprite background;
public:
	bool onPause = false;
	bool isGameOver = false;
	GameView(GameModel &model, GameController &controller);
	void run(sf::RenderWindow &window);
	void process_draw(sf::RenderWindow &window);
	void process_logic();
	void process_events(sf::RenderWindow &window);
};

#endif
