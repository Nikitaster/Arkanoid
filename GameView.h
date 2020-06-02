#pragma once

class MainView {
	MainModel *model;
	MainController *controller;
	sf::RenderWindow window;
public:
	MainView(MainModel &model, MainController &controller);
	void run();
	void process_draw();
	void process_logic();
	void process_events();
};