#include "MainView.h"

MainView::MainView()
{
	this->window.create(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
	this->window.setFramerateLimit(60);
	game_scene = new GameScene();
	menu_scene = new MenuScene();
	over_scene = new GameOverScene();
	pause_scene = new PauseScene();
	//win_scene = new GameWinScene();

	runners = { { "menu", std::bind(&MainView::show_menu, this) },
	{ "game", std::bind(&MainView::show_game, this) },
	{ "pause", std::bind(&MainView::show_pause, this) },
	{ "gameOver", std::bind(&MainView::show_game_over, this) },
	};
	current_runner = "menu";
}

MainView::~MainView()
{
	delete game_scene;
	delete menu_scene;
	delete over_scene;
	delete pause_scene;
}

void MainView::show_menu()
{
	menu_scene->run(this->window);
}

void MainView::show_game()
{
	game_scene->run(this->window);
}

void MainView::show_pause()
{
	pause_scene->run(this->window);
}

void MainView::show_game_over()
{
	over_scene->run(this->window);
}

void MainView::reset_game_scene()
{
	delete this->game_scene;
	this->game_scene = new GameScene();
}

void MainView::run()
{
	while (this->window.isOpen())
	{
		if (current_runner == "menu")
		{
			if (!menu_scene->get_menu_statement())
				current_runner = "game";
		}
		if (current_runner == "game")
		{
			if (game_scene->onPause())
				current_runner = "pause";
			if (game_scene->isGameOver())
				current_runner = "gameOver";
		}
		if (current_runner == "pause")
		{
			if (pause_scene->check_button_pressed(this->window) == 1)
			{
				game_scene->onPause() = false;
				current_runner = "game";
			}
			else if (pause_scene->check_button_pressed(this->window) == 2)
			{
				reset_game_scene();
				current_runner = "game";
			}
			else if (pause_scene->check_button_pressed(this->window) == 3)
			{
				menu_scene->get_menu_statement() = true;
				reset_game_scene();
				current_runner = "menu";
				sf::sleep(sf::milliseconds(100));
			}
		}
		if (current_runner == "gameOver")
		{
			if (over_scene->getButton() == 1 && over_scene->getButtonStatus())
			{
				reset_game_scene();
				current_runner = "menu";
				menu_scene->get_menu_statement() = true;
				sf::sleep(sf::milliseconds(100));
			}
		}

		runners[current_runner]();
	}
	window.close();
}
