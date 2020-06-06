#include "GameOverScene.h"

GameOverScene::GameOverScene() {
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

void GameOverScene::run(sf::RenderWindow & window)
{
	this->process_draw(window);
	this->process_events(window);
}

void GameOverScene::process_events(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void GameOverScene::process_draw(sf::RenderWindow & window)
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

void GameOverScene::over_logic(sf::RenderWindow & window) {
	this->check_button_selected(window);
	this->check_button_pressed(window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void GameOverScene::check_button_selected(sf::RenderWindow & window) {
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

void GameOverScene::check_button_pressed(sf::RenderWindow & window) {
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

