#include "GameView.h"

class GameMenu {
	sf::Sprite menu;
	bool is_menu = 1;
	int button_num;
	sf::Font font;
	sf::Text button1;
	sf::Text button2;
	sf::Text button3;
public:
	GameMenu() {
		button1.setPosition(312, 123);
		button2.setPosition(290, 183);
		button3.setPosition(363, 243);
		this->is_menu = 1;
		this->button_num = 0;
		font.loadFromFile("segoescb.ttf");
		button1.setFont(font);
		button2.setFont(font);
		button3.setFont(font);
		button1.setString("Start game");
		button2.setString("About project");
		button3.setString("Exit");
	}

	inline bool get_menu_statement() { return is_menu; };

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
		button1.setFillColor(sf::Color::Green);
		button2.setFillColor(sf::Color::Green);
		button3.setFillColor(sf::Color::Green);
		this->menu_logic(window);
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.display();
	}

	void menu_logic(sf::RenderWindow &window) {
		this->check_button_selected(window);
		this->check_button_pressed(window);
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();*/
	}

	void check_button_selected(sf::RenderWindow &window) {
		if (sf::IntRect(312, 123, 175, 35).contains(sf::Mouse::getPosition(window))) {
			this->button1.setFillColor(sf::Color::Blue);
			this->button_num = 1;
		}
		else if (sf::IntRect(290, 183, 220, 35).contains(sf::Mouse::getPosition(window))) {
			this->button2.setFillColor(sf::Color::Blue);
			this->button_num = 2;
		}
		else if (sf::IntRect(363, 243, 75, 35).contains(sf::Mouse::getPosition(window))) {
			this->button3.setFillColor(sf::Color::Blue);
			this->button_num = 3;
		}
		else
			this->button_num = 0;
	}

	void check_button_pressed(sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (button_num == 1)
				this->is_menu = false;
			//if (button_num == 2);
			if (button_num == 3) {
				window.close();
				this->is_menu = false;
			}
		}
	}
};

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
	GameMenu * game_menu;
public:
	MainView()
	{
		this->window.create(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
		this->window.setFramerateLimit(60);
		game_scene = new GameScene();
		game_menu = new GameMenu();
	}

	void run()
	{
		while (this->window.isOpen())
		{
			if (game_menu->get_menu_statement()) {
				game_menu->run(this->window);
			}
			else {
				game_scene->run(this->window);
			}
		}
	}
};



int main()
{
	MainView().run();

	return 0;
}
