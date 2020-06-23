#ifndef MainView_H
#define MainView_H


#include "GameScene.h"
#include "GameOverScene.h"
#include "GameWinScene.h"
#include "MenuScene.h"
#include "PauseScene.h"

#include <string>
#include <map>
#include <functional>


class MainView {
	sf::RenderWindow window;
	GameScene * game_scene;
	MenuScene * menu_scene;
	GameOverScene * over_scene;
	GameWinScene * win_scene;
	PauseScene * pause_scene;
	std::map<std::string, std::function<void()> > runners;
	std::string current_runner;
	
public:
	MainView();
	~MainView();
	void show_menu();
	void show_game();
	void show_pause();
	void show_game_over();
	void show_game_win();
	void reset_game_scene();
	void run();
};

#endif