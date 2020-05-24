#include <iostream>
#include <SFML/Graphics.hpp>


class MainModel {
	
public:
	MainModel() {}
};

class MainController {
	MainModel *model;
public:
	MainController(MainModel &model)
	{
		this->model = &model;
	}
};

class MainView {
	MainModel *model;
	MainController *controller;
public:
	MainView(MainModel &model, MainController &controller)
	{
		this->model = &model;
		this->controller = &controller;
	}
};


int main()
{
	MainModel model;
	MainController controller(model);
	MainView view(model, controller);

	system("pause");
	return 0;
}



//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
//	window.setFramerateLimit(60);
//
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//	float speed_y = 5;
//	float speed_x = 5;
//
//	sf::CircleShape shape2(100.f);
//	shape2.setFillColor(sf::Color::Red);
//	float speed_y2 = 2;
//	float speed_x2 = 2;
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (event.text.unicode < 128)
//				std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
//		}
//
//		window.setActive();
//		window.clear();
//		window.draw(shape);
//		window.draw(shape2);
//		window.display();
//		sf::sleep(sf::milliseconds(10));
//	
//		sf::Vector2f xy = shape.getPosition();
//		std::cout << xy.x << ' ' << xy.y << std::endl;
//
//		auto x = xy.x;
//		auto y = xy.y;
//
//		if (y + speed_y >= 600 - 200 || y + speed_y <= 0)
//		{
//			speed_y *= -1;
//		}
//
//		if (x + speed_x >= 800 - 200 || x + speed_x <= 0)
//		{
//			speed_x *= -1;
//		}
//
//		sf::Vector2f xy2 = shape2.getPosition();
//		std::cout << xy2.x << ' ' << xy2.y << std::endl;
//
//		auto x2 = xy2.x;
//		auto y2 = xy2.y;
//
//		if (y2 + speed_y2 >= 600 - 200 || y2 + speed_y2 <= 0)
//		{
//			speed_y2 *= -1;
//		}
//
//		if (x2 + speed_x2 >= 800 - 200 || x2 + speed_x2 <= 0)
//		{
//			speed_x2 *= -1;
//		}
//
//		shape.setPosition(sf::Vector2f(x + speed_x, y + speed_y));
//		shape2.setPosition(sf::Vector2f(x2 + speed_x2, y2 + speed_y2));
//	}
//	
//	return 0;
//}

