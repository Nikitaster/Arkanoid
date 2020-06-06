#include "GameView.h"


class MenuScene {
	sf::Sprite menu;
	bool is_menu = 1;
	int button_num;
	sf::Texture menu_texture;
	sf::Font font_for_game;
	sf::Font font_for_buttons;
	sf::Text game;
	sf::Text start_button;
	sf::Text about_project_button;
	sf::Text exit_button;
	
public:
	MenuScene() {
		start_button.setPosition(281, 123);
		about_project_button.setPosition(242, 183);
		exit_button.setPosition(353, 243);
		game.setPosition(245, 53);

		this->is_menu = 1;
		this->button_num = 0;

		font_for_game.loadFromFile("font2.ttf");
		font_for_buttons.loadFromFile("font3.ttf");
		menu_texture.loadFromFile("���2.png");

		menu.setTexture(menu_texture);

		start_button.setFont(font_for_buttons);
		about_project_button.setFont(font_for_buttons);
		exit_button.setFont(font_for_buttons);
		game.setFont(font_for_game);

		game.setCharacterSize(60);
		start_button.setCharacterSize(50);
		about_project_button.setCharacterSize(50);
		exit_button.setCharacterSize(50);

		start_button.setString("start game");
		about_project_button.setString("about project");
		exit_button.setString("exit");
		game.setString("Arkanoid");
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
		start_button.setFillColor(sf::Color(61, 31, 115));
		about_project_button.setFillColor(sf::Color(61, 31, 115));
		exit_button.setFillColor(sf::Color(61, 31, 115));
		game.setFillColor(sf::Color(61, 31, 115));
		this->menu_logic(window);
		window.draw(menu);
		window.draw(start_button);
		window.draw(about_project_button);
		window.draw(exit_button);
		window.draw(game);
		window.display();
	}

	void menu_logic(sf::RenderWindow &window) {
		this->check_button_selected(window);
		this->check_button_pressed(window);
		/*���� ����� ����� ����� �� ���� �� escape
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
		else if (sf::IntRect(353, 267, 94, 28).contains(sf::Mouse::getPosition(window))) {
			this->exit_button.setFillColor(sf::Color::Blue);
			this->button_num = 3;
		}
		else
			this->button_num = 0;
	}

	void about_page(sf::RenderWindow &window) {
		window.draw(menu);
		window.draw(game);
		//�������� ��������� about_project
		window.display();
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	}

	void check_button_pressed(sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (button_num == 1)
				this->is_menu = false;
			if (button_num == 2){ 
				this->about_page(window);
			}
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
	MenuScene * menu_scene;
public:
	MainView()
	{
		this->window.create(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
		this->window.setFramerateLimit(60);
		game_scene = new GameScene();
		menu_scene = new MenuScene();
	}

	void run()
	{
		while (this->window.isOpen())
		{
			if (menu_scene->get_menu_statement()) {
				menu_scene->run(this->window);
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
