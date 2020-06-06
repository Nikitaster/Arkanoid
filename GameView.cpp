#include "GameView.h"


GameView::GameView(GameModel &model, GameController &controller)
{
	this->model = &model;
	this->controller = &controller;
	this->model->puddle.velocity.get_speedX() = 0;
}

void GameView::run(sf::RenderWindow &window)
{
	//       сделать меню
	this->process_events(window);
	this->process_logic();
	this->process_draw(window);
	
}

//int GameOver(sf::RenderWindow &window) {
//	sf::Text gameOver;
//	sf::Font font;
//	if (!font.loadFromFile("font2.ttf")) {
//		return -1;
//	}
//	gameOver.setFont(font);
//	gameOver.setString("Game over!");
//	gameOver.setCharacterSize(36);
//	gameOver.setFillColor(sf::Color::Red);
//	//gameOver.setStyle(sf::Text::Bold);
//	gameOver.setPosition(290, 150);
//	window.draw(gameOver);
//	std::cout << "GAME OVER!!!" << std::endl;
//	return 0;
//};

void GameView::process_logic()
{
	this->controller->move_puddle();
	if (this->model->pucks.have_alive_puck())
	{
		this->model->pucks.get_alive_puck().move();
		this->model->pucks.get_alive_puck().collideInto(this->model->puddle);
        for (auto it = this->model->bricks.bricks.begin(); it < this->model->bricks.bricks.end(); it++)
        {
            if (!it->isDead)
                this->model->pucks.get_alive_puck().collideInto(*it);
        }
	}
}

void GameView::process_events(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
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

void GameView::process_draw(sf::RenderWindow &window)
{
	window.clear();
	//        this->window.draw(shape);
	for (auto it = this->model->bricks.bricks.begin(); it < this->model->bricks.bricks.end(); it++)
		if (!it->isDead)
			window.draw(it->get_sprite());

	window.draw(this->model->puddle.get_sprite());

	//        убить мяч
	//        this->model->pucks.get_alive_puck().isDead = true;
	//        сделать проверку
	//        this->model->pucks.have_alive_puck()
	//        gameover

	if (this->model->pucks.have_alive_puck())
		window.draw(this->model->pucks.get_alive_puck().get_sprite());
	else {
		window.clear();
		model->end_code = 0;
		//GameOver(window);
	}

	//	сюда пропишите убийство кирпичей
	//	вставим сюда отрисовку окна победы

	window.display();
}
