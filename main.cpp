#include "GameView.h"

class GameScene{
	GameModel * game_model;
	GameController * game_controller;
	GameView * game_view;
public:
	GameScene(){
		game_model = new GameModel();
		game_controller = new GameController(*game_model);
		game_view = new GameView(*game_model, *game_controller);
	}

	void run(sf::RenderWindow &window)
	{
		game_view->run(window);
	}
};


class MainView {
	sf::RenderWindow window;
	GameScene * game_scene;
public:
	MainView()
	{
		this->window.create(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
		this->window.setFramerateLimit(60);
		game_scene = new GameScene();
	}

	void run()
	{
		while (this->window.isOpen())
		{
			game_scene->run(this->window);
		}
	}
};



int main()
{
	MainView().run();

	return 0;
}
