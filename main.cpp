#include "GameView.h"

class MenuScene {
	sf::Sprite menu;
	bool is_menu = 1;
	int button_num;
	sf::Texture menu_texture;
	sf::Font font1;
	sf::Font font2;
	sf::Text game;
	sf::Text button1;
	sf::Text button2;
	sf::Text button3;
public:
	MenuScene() {
		button1.setPosition(281, 123);
		button2.setPosition(242, 183);
		button3.setPosition(353, 243);
		game.setPosition(245, 53);
		this->is_menu = 1;
		this->button_num = 0;
		font1.loadFromFile("font2.ttf");
		font2.loadFromFile("font3.ttf");
		menu_texture.loadFromFile("2.png");
		menu.setTexture(menu_texture);
		button1.setFont(font2);
		button2.setFont(font2);
		button3.setFont(font2);
		game.setFont(font1);
		game.setCharacterSize(60);
		button1.setCharacterSize(50);
		button2.setCharacterSize(50);
		button3.setCharacterSize(50);
		button1.setString("start game");
		button2.setString("about project");
		button3.setString("exit");
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
		button1.setFillColor(sf::Color(61, 31, 115));
		button2.setFillColor(sf::Color(61, 31, 115));
		button3.setFillColor(sf::Color(61, 31, 115));
		game.setFillColor(sf::Color(61, 31, 115));
		this->menu_logic(window);
		window.draw(menu);
		window.draw(button1);
		window.draw(button2);
		window.draw(button3);
		window.draw(game);
		window.display();
	}

	void menu_logic(sf::RenderWindow &window) {
		this->check_button_selected(window);
		this->check_button_pressed(window);
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();*/
	}

	void check_button_selected(sf::RenderWindow &window) {
		if (sf::IntRect(281, 147, 238, 28).contains(sf::Mouse::getPosition(window))) {
			this->button1.setFillColor(sf::Color::Blue);
			this->button_num = 1;
		}
		else if (sf::IntRect(242, 207, 316, 28).contains(sf::Mouse::getPosition(window))) {
			this->button2.setFillColor(sf::Color::Blue);
			this->button_num = 2;
		}
		else if (sf::IntRect(353, 267, 94, 28).contains(sf::Mouse::getPosition(window))) {
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

class GameScene {
	GameModel * game_model;
	GameController * game_controller;
	GameView * game_view;
public:
	GameScene() {
		game_model = new GameModel();
		game_controller = new GameController(*game_model);
		game_view = new GameView(*game_model, *game_controller);
	}

	int get_end_code() { return game_model->end_code; };
	/*void setNewGame() { 
		game_model->end_code = -1; 
		game_model = new GameModel();
		game_controller = new GameController(*game_model);
		game_view = new GameView(*game_model, *game_controller);
	}*/

	void run(sf::RenderWindow &window)
	{
		game_view->run(window);
	}
};

/*class GameWinScene {
	sf::Sprite gameWin;
	bool isActive = 1;
	int button_num = 0;
	bool button_pressed = false;
	sf::Texture gameOver_texture;
	sf::Font font1;
	sf::Font font2;
	sf::Text win;
	sf::Text button1;
	sf::Text button2;
public:
	GameOverScene() {
		button1.setPosition(260, 225);
		button2.setPosition(353, 275);
		win.setPosition(200, 150);
		this->isActive = 1;
		this->button_pressed = false;
		this->button_num = 0;
		font1.loadFromFile("font2.ttf");
		font2.loadFromFile("font3.ttf");
		gameWin_texture.loadFromFile("winner.png");
		gameWin.setTexture(gameWin_texture);
		button1.setFont(font2);
		button2.setFont(font2);
		win.setFont(font1);
		win.setCharacterSize(60);
		button1.setCharacterSize(50);
		button2.setCharacterSize(50);
		button1.setString("try again");
		button2.setString("exit");
		win.setString("Congrats, you win!");
	}

	inline bool getStatement() { return isActive; };
	inline int getButton() { return button_num; };
	inline bool getButtonStatus() { return button_pressed; };

	void run(sf::RenderWindow& window)
	{
		this->process_draw(window);
		this->process_events(window);
	}

	void process_events(sf::RenderWindow& window)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	void process_draw(sf::RenderWindow& window)
	{
		window.clear();
		button1.setFillColor(sf::Color(61, 31, 115));
		button2.setFillColor(sf::Color(61, 31, 115));
		win.setFillColor(sf::Color::Orange);
		this->over_logic(window);
		window.draw(gameWin);
		window.draw(button1);
		window.draw(button2);
		window.draw(win);
		window.display();
	}

	void over_logic(sf::RenderWindow& window) {
		this->check_button_selected(window);
		this->check_button_pressed(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
	}

	void check_button_selected(sf::RenderWindow& window) {
		this->button_pressed = false;
		if (sf::IntRect(260, 250, 235, 28).contains(sf::Mouse::getPosition(window))) {
			this->button1.setFillColor(sf::Color::Blue);
			this->button_num = 1;
		}
		else if (sf::IntRect(353, 300, 94, 28).contains(sf::Mouse::getPosition(window))) {
			this->button2.setFillColor(sf::Color::Blue);
			this->button_num = 2;
		}
		else
			this->button_num = 0;
	}

	void check_button_pressed(sf::RenderWindow& window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->button_pressed = true;
			if (button_num == 1) {
				this->isActive = false;
			}
			if (button_num == 2) {
				window.close();
				this->isActive = false;
			}
		}
	}
};*/

class GameOverScene {
	sf::Sprite gameOver;
	bool isActive = 1;
	int button_num = 0;
	bool button_pressed = false;
	sf::Texture gameOver_texture;
	sf::Font font1;
	sf::Font font2;
	sf::Text lose;
	sf::Text button1;
	sf::Text button2;
public:
	GameOverScene() {
		button1.setPosition(260, 225);
		button2.setPosition(353, 275);
		lose.setPosition(200, 150);
		this->isActive = 1;
		this->button_pressed = false;
		this->button_num = 0;
		font1.loadFromFile("font2.ttf");
		font2.loadFromFile("font3.ttf");
		gameOver_texture.loadFromFile("loser.png");
		gameOver.setTexture(gameOver_texture);
		button1.setFont(font2);
		button2.setFont(font2);
		lose.setFont(font1);
		lose.setCharacterSize(60);
		button1.setCharacterSize(50);
		button2.setCharacterSize(50);
		button1.setString("back to menu");
		button2.setString("exit");
		lose.setString("Game over!");
	}

	inline bool getStatement() { return isActive; };
	inline int getButton() { return button_num; };
	inline bool getButtonStatus() { return button_pressed; };

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
		button1.setFillColor(sf::Color(61, 31, 115));
		button2.setFillColor(sf::Color(61, 31, 115));
		lose.setFillColor(sf::Color::White);
		this->over_logic(window);
		window.draw(gameOver);
		window.draw(button1);
		window.draw(button2);
		window.draw(lose);
		window.display();
	}

	void over_logic(sf::RenderWindow &window) {
		this->check_button_selected(window);
		this->check_button_pressed(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
	}

	void check_button_selected(sf::RenderWindow &window) {
		this->button_pressed = false;
		if (sf::IntRect(260, 250, 235, 28).contains(sf::Mouse::getPosition(window))) {
			this->button1.setFillColor(sf::Color::Blue);
			this->button_num = 1;
		}
		else if (sf::IntRect(353, 300, 94, 28).contains(sf::Mouse::getPosition(window))) {
			this->button2.setFillColor(sf::Color::Blue);
			this->button_num = 2;
		}
		else
			this->button_num = 0;
	}

	void check_button_pressed(sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->button_pressed = true;
			if (button_num == 1) {
				this->isActive = false;
			}
			if (button_num == 2) {
				window.close();
				this->isActive = false;
			}
		}
	}
};

class MainView {
	sf::RenderWindow window;
	GameScene * game_scene;
	MenuScene * menu_scene;
	GameOverScene * over_scene;
	//GameWinScene * win_scene;
public:
	MainView()
	{
		this->window.create(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
		this->window.setFramerateLimit(60);
		game_scene = new GameScene();
		menu_scene = new MenuScene();
		over_scene = new GameOverScene();
		//win_scene = new GameWinScene();
	}

	void run()
	{
		while (this->window.isOpen())
		{
			if (menu_scene->get_menu_statement()) {
				menu_scene->run(this->window);
				if (game_scene->get_end_code() != -1 && menu_scene->get_menu_statement()) {
					game_scene = new GameScene();
				}
			}
			else if (game_scene->get_end_code() == -1) {
				game_scene->run(this->window);
			}
			else if (game_scene->get_end_code() == 0) {
				over_scene->run(this->window);
				if (over_scene->getButton() == 1 && over_scene->getButtonStatus()) {
					menu_scene = new MenuScene();
				}
				
			}
		}
	}
};


int main()
{
	MainView().run();

	return 0;
}
