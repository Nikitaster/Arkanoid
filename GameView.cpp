#include "GameView.h"

GameView::GameView(GameModel &model, GameController &controller)
{
	this->model = &model;
	this->controller = &controller;
	this->window.create(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
	this->window.setFramerateLimit(60);
	this->model->puddle.velocity.get_speedX() = 0;
}

void GameView::run()
{
	//       ������� ����
	while (this->window.isOpen())
	{
		this->process_events();
		this->process_logic();
		//            controller logics
		this->process_draw();
		//            sf::sleep(sf::milliseconds(10));
	}
}

void GameView::process_logic()
{
	this->controller->move_puddle();
	this->model->pucks.get_alive_puck().move();
}

void GameView::process_events()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window.close();
		if (event.text.unicode < 128)
			std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				std::cout << "Move LEFT" << event.key.code << std::endl;
				this->controller->move_puddle_left();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				std::cout << "Move RIGHT" << std::endl;
				this->controller->move_puddle_right();
			}
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right ||
				event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
				this->controller->stop_puddle();
		}
	}
}

void GameView::process_draw()
{
	this->window.clear();
	//        this->window.draw(shape);
	for (auto it = this->model->bricks.bricks.begin(); it < this->model->bricks.bricks.end(); it++)
		this->window.draw(it->get_sprite());

	this->window.draw(this->model->puddle.get_sprite());

	//        ����� ���
	//        this->model->pucks.get_alive_puck().isDead = true;
	//        ������� ��������
	//        this->model->pucks.have_alive_puck()
	//        gameover

	this->window.draw(this->model->pucks.get_alive_puck().get_sprite());

	this->window.display();
}