#pragma once

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