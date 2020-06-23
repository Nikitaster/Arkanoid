#ifndef MenuScene_H
#define MenuScene_H

#include "BaseScene.h"

class MenuScene : public BaseScene {
	sf::Sprite menu;
	sf::Sprite about_page;
	sf::Sprite controllers_wasd;
	sf::Sprite controllers_arrows;
	sf::Sprite controllers_explanation;
	sf::Sprite pause_explanation;
	bool is_menu = 1;
	int button_num;
	sf::Texture menu_texture;
	sf::Texture about_texture;
	sf::Texture controllers_wasd_texture;
	sf::Texture controllers_arrows_texture;
	sf::Texture controllers_explanation_texture;
	sf::Texture controllers_pause_explanation;
	sf::Font font_for_game;
	sf::Font font_for_buttons;
	sf::Text game;
	sf::Text start_button;
	sf::Text about_project_button;
	sf::Text exit_button;
	sf::Text controllers_button;
	sf::Text back_to_menu;

public:
	MenuScene() {
		start_button.setPosition(281, 123);
		about_project_button.setPosition(242, 183);
		exit_button.setPosition(353, 303);
		game.setPosition(245, 53);
		about_page.setPosition(60, 138);
		controllers_button.setPosition(264, 243);
		back_to_menu.setPosition(248, 512);
		controllers_wasd.setPosition(210, 259);
		controllers_arrows.setPosition(462, 259);
		controllers_explanation.setPosition(153, 180);
		pause_explanation.setPosition(150, 450);

		this->is_menu = 1;
		this->button_num = 0;

		font_for_game.loadFromFile("font2.ttf");
		font_for_buttons.loadFromFile("font3.ttf");
		menu_texture.loadFromFile("menu_background.png");
		about_texture.loadFromFile("about_page.png");
		controllers_arrows_texture.loadFromFile("move_puddle2.png");
		controllers_explanation_texture.loadFromFile("controllers_explanation.png");
		controllers_wasd_texture.loadFromFile("move_puddle1.png");
		controllers_pause_explanation.loadFromFile("pause_explanation.png");

		menu.setTexture(menu_texture);
		about_page.setTexture(about_texture);
		controllers_arrows.setTexture(controllers_arrows_texture);
		controllers_wasd.setTexture(controllers_wasd_texture);
		controllers_explanation.setTexture(controllers_explanation_texture);
		pause_explanation.setTexture(controllers_pause_explanation);

		start_button.setFont(font_for_buttons);
		about_project_button.setFont(font_for_buttons);
		exit_button.setFont(font_for_buttons);
		game.setFont(font_for_game);
		controllers_button.setFont(font_for_buttons);
		back_to_menu.setFont(font_for_buttons);

		game.setCharacterSize(60);
		start_button.setCharacterSize(50);
		about_project_button.setCharacterSize(50);
		exit_button.setCharacterSize(50);
		controllers_button.setCharacterSize(50);
		back_to_menu.setCharacterSize(30);

		start_button.setString("start game");
		about_project_button.setString("about project");
		exit_button.setString("exit");
		game.setString("Arkanoid");
		controllers_button.setString("controllers");
		back_to_menu.setString("PRESS esc TO EXIT TO MENU");
	}

	inline bool & get_menu_statement() { return is_menu; };

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
		start_button.setFillColor(sf::Color(61, 31, 115));
		about_project_button.setFillColor(sf::Color(61, 31, 115));
		exit_button.setFillColor(sf::Color(61, 31, 115));
		controllers_button.setFillColor(sf::Color(61, 31, 115));
		game.setFillColor(sf::Color(61, 31, 115));
		this->menu_logic(window);
		window.draw(menu);
		window.draw(start_button);
		window.draw(about_project_button);
		window.draw(exit_button);
		window.draw(controllers_button);
		window.draw(game);
		window.display();
	}

	void menu_logic(sf::RenderWindow &window) {
		this->check_button_selected(window);
		this->check_button_pressed(window);
		/*       escape
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();*/
	}

	void check_button_selected(sf::RenderWindow &window) {
		if (sf::IntRect(281, 147, 238, 28).contains(sf::Mouse::getPosition(window))) {
			this->start_button.setFillColor(sf::Color::Blue);
			this->button_num = 1;
		}
		else if (sf::IntRect(242, 207, 316, 28).contains(sf::Mouse::getPosition(window))) {
			this->about_project_button.setFillColor(sf::Color::Blue);
			this->button_num = 2;
		}
		else if (sf::IntRect(264, 267, 272, 28).contains(sf::Mouse::getPosition(window))) {
			this->controllers_button.setFillColor(sf::Color::Blue);
			this->button_num = 3;
		}
		else if (sf::IntRect(353, 327, 94, 28).contains(sf::Mouse::getPosition(window))) {
			this->exit_button.setFillColor(sf::Color::Blue);
			this->button_num = 4;
		}
		else
			this->button_num = 0;
	}

	void about_page_scene(sf::RenderWindow &window) {
		window.draw(menu);
		window.draw(game);
		window.draw(about_page);
		window.draw(back_to_menu);
		window.display();
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	}

	void controllers_page_scene(sf::RenderWindow &window) {
		window.draw(menu);
		window.draw(game);
		window.draw(controllers_explanation);
		window.draw(controllers_wasd);
		window.draw(controllers_arrows);
		window.draw(pause_explanation);
		window.draw(back_to_menu);
		window.display();
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	}

	void check_button_pressed(sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (button_num == 1)
				this->is_menu = false;
			if (button_num == 2) {
				this->about_page_scene(window);
			}
			if (button_num == 3) {
				this->controllers_page_scene(window);
			}
			if (button_num == 4) {
				this->is_menu = false;
				window.close();
			}
		}
		button_num = 0;
	}

};

#endif