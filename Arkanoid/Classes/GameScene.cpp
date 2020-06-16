#include "GameScene.h"

GameScene::GameScene() {
	game_model = new GameModel();
	game_controller = new GameController(*game_model);
	game_view = new GameView(*game_model, *game_controller);
}

void GameScene::run(sf::RenderWindow & window)
{
	game_view->run(window);
}
