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

	inline bool & onPause() { return this->game_view->onPause; }
	inline bool & isGameOver() { return this->game_view->isGameOver; }

	/*void setNewGame() {
	game_model->end_code = -1;
	game_model = new GameModel();
	game_controller = new GameController(*game_model);
	game_view = new GameView(*game_model, *game_controller);
	}*/

	void run(sf::RenderWindow &window);
};

#endif