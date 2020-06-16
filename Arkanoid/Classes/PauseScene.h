#ifndef PauseScene_H
#define PauseScene_H

#include "BaseScene.h"

class PauseScene : public BaseScene {
	sf::Sprite pause;
	bool is_pause = 1;
	int button_num;
	sf::Texture pause_texture;
	sf::Font font_for_game;
	sf::Font font_for_buttons;
	sf::Text game;
	sf::Text continue_button;
	sf::Text start_new_game_button;
	sf::Text exit_to_menu_button;
public:
	PauseScene() {
		continue_button.setPosition(303, 123);
		exit_to_menu_button.setPosition(262, 243);
		game.setPosition(245, 53);
		start_new_game_button.setPosition(236, 183);

		this->is_pause = 1;
		this->button_num = 0;

		font_for_game.loadFromFile("font2.ttf");
		font_for_buttons.loadFromFile("font3.ttf");
		pause_texture.loadFromFile("menu_background.png");

		pause.setTexture(pause_texture);

		continue_button.setFont(font_for_buttons);
		exit_to_menu_button.setFont(font_for_buttons);
		game.setFont(font_for_game);
		start_new_game_button.setFont(font_for_buttons);

		game.setCharacterSize(60);
		continue_button.setCharacterSize(50);
		exit_to_menu_button.setCharacterSize(50);
		start_new_game_button.setCharacterSize(50);

		continue_button.setString("continue");
		exit_to_menu_button.setString("exit to menu");
		start_new_game_button.setString("start new game");
		game.setString("Arkanoid");
	}

	inline bool & get_pause_statement() { return is_pause; };
	inline const int & get_button() { return this->button_num; };

	void run(sf::RenderWindow &window)
	{
		this->process_draw(window);
		this->process_events(window);
	}

	void process_events(sf::RenderWindow &window)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void process_draw(sf::RenderWindow &window)
	{
		window.clear();
		continue_button.setFillColor(sf::Color(61, 31, 115));
		exit_to_menu_button.setFillColor(sf::Color(61, 31, 115));
		start_new_game_button.setFillColor(sf::Color(61, 31, 115));
		game.setFillColor(sf::Color(61, 31, 115));
		this->menu_logic(window);
		window.draw(pause);
		window.draw(continue_button);
		window.draw(exit_to_menu_button);
		window.draw(start_new_game_button);
		window.draw(game);
		window.display();
	}

	void menu_logic(sf::RenderWindow &window) {
		this->check_button_selected(window);
		this->check_button_pressed(window);
	}

	void check_button_selected(sf::RenderWindow &window) {
		if (sf::IntRect(303, 147, 194, 28).contains(sf::Mouse::getPosition(window))) {
			this->continue_button.setFillColor(sf::Color::Blue);
			this->button_num = 1;
		}
		else if (sf::IntRect(236, 207, 329, 28).contains(sf::Mouse::getPosition(window))) {
			this->start_new_game_button.setFillColor(sf::Color::Blue);
			this->button_num = 2;
		}
		else if (sf::IntRect(262, 267, 276, 28).contains(sf::Mouse::getPosition(window))) {
			this->exit_to_menu_button.setFillColor(sf::Color::Blue);
			this->button_num = 3;
		}
		else
			this->button_num = 0;
	}

	int check_button_pressed(sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return this->button_num;
		}
		return 0;
	}
};

#endif