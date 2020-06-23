#ifndef GameScene_H
#define GameScene_H

#include "BaseScene.h"
#include "GameView.h"

class GameScene : public BaseScene {
	GameModel * game_model;
	GameController * game_controller;
	GameView * game_view;
public:
	GameScene();
	~GameScene()
	{
		delete game_view;
		delete game_controller;
		delete game_model;
	}

	inline bool & onPause() { return this->game_view->onPause; }
	inline bool & isGameOver() { return this->game_view->isGameOver; }
	inline bool & isGameWin() { return this->game_view->isGameWin; }

	void run(sf::RenderWindow &window);
};

#endif