#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

static std::string path_brick_sprite = "briques.png";

class Sprite{
protected:
    bool isDead;
    sf::Sprite sprite;
public:
    Sprite(){
        this->isDead = false;
    }
    virtual sf::Sprite &get_sprite() = 0;
};


class StationarySprite: public Sprite{
public:
    inline sf::Sprite &get_sprite() {return this->sprite;}
};


class Brick: public StationarySprite{
public:
    Brick(int x=0, int y=0, int width=100, int height=50):StationarySprite(){
        sf::Texture texture;
        texture.create(100, 50);
        this->sprite.setTexture(texture);
        this->sprite.move(x, y);
    }
};


class BrickPile{
public:
    std::vector<Brick> bricks;
    sf::Texture texture;
    BrickPile()
    {
        this->texture.loadFromFile(path_brick_sprite);
        this->generate_objects();
        
    }
    void generate_objects()
    {
        for (int i = 0; i < 150; i+=50)
        {
            for (int j = 0; j < 800; j+=100)
            {
                this->bricks.push_back(Brick(j, i, 100, 50));
                //                this->texture.setRepeated(true);
                //                this->texture.setSmooth(true);
                this->bricks.back().get_sprite().setTexture(this->texture);
            }
        }
    }
};


class MainModel {
public:
    BrickPile bricks;
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
    sf::RenderWindow window;
public:
	MainView(MainModel &model, MainController &controller)
	{
		this->model = &model;
		this->controller = &controller;
        this->window.create(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
        this->window.setFramerateLimit(60);
	}
    
    void run()
    {
//       сделать меню
        while (this->window.isOpen())
        {
            this->process_events();
//            controller logics
            this->process_draw();
            sf::sleep(sf::milliseconds(10));
        }
    }
    
    void process_draw()
    {
        this->window.clear();
        //        this->window.draw(shape);
        for (auto it = this->model->bricks.bricks.begin(); it < this->model->bricks.bricks.end(); it++)
            this->window.draw(it->get_sprite());
        this->window.display();
    }
    
    void process_events()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
            if (event.text.unicode < 128)
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                std::cout << "Move LEFT" << std::endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                std::cout << "Move RIGHT" << std::endl;
        }
    }
};


int main()
{
	MainModel model;
	MainController controller(model);
	MainView view(model, controller);
    view.run();
    
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

