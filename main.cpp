#include <iostream>
#include <vector>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

#include <SFML/Graphics.hpp>

#include "Texture.cpp"	
#include "TextureBall.cpp"
#include "TextureBrick.cpp"
#include "TexturePuddle.cpp"
#include "Sprite.cpp"
#include "StationarySprite.cpp"
#include "MovableSprite.cpp"
#include "Velocity.cpp"

class Brick: public StationarySprite{
    static TextureBrick texture;
public:
    Brick(int x=0, int y=0, int width=100, int height=50):StationarySprite(){
        sf::Texture texture;
        texture.create(100, 50);
        this->sprite.setTexture(this->texture.get_texture());
        this->sprite.move(x, y);
    }
};

TextureBrick Brick::texture = TextureBrick();

class BrickPile{
public:
    std::vector<Brick> bricks;
    BrickPile()
    {
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
            }
        }
    }
};

class Puddle: public MovableSprite{
    static TexturePuddle texture;
public:
    Puddle(){
        this->velocity = Velocity(0, 5);
        this->sprite.setTexture(texture.get_texture());
        this->sprite.move(800/2 - 150, 500);
    }
};

TexturePuddle Puddle::texture = TexturePuddle();


class Puck: public MovableSprite{
//    sf::Texture texture;
    static TextureBall texture;
public:
    Puck(){
        this->velocity = Velocity(90, 5);
//        this->texture.loadFromFile(path_brick_sprite, sf::IntRect(0, 0, 50, 50));
        this->sprite.setTexture(texture.get_texture());
        this->sprite.setPosition(800/2 - 20, 500 - 40);
    }
};
TextureBall Puck::texture = TextureBall();


class PuckSupply: public Puck{
    std::vector<Puck> pucks;
public:
    PuckSupply()
    {
        this->pucks.push_back(Puck());
        this->pucks.push_back(Puck());
        this->pucks.push_back(Puck());
    }
    bool have_alive_puck()
    {
        for(auto it = this->pucks.begin(); it < this->pucks.end(); it++)
        {
            if (!it->isDead)
            return true;
        }
        return false;
    }
    Puck & get_alive_puck()
    {
        for(auto it = this->pucks.begin(); it < this->pucks.end(); it++)
        {
            if (!it->isDead)
                return *it;
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
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid!", sf::Style::Close);
//    window.setFramerateLimit(60);
//
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//    float speed_y = 10;
//    float speed_x = 10;
//
//    sf::CircleShape shape2(100.f);
//    shape2.setFillColor(sf::Color::Red);
//    float speed_y2 = 2;
//    float speed_x2 = 2;
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if (event.text.unicode < 128)
//                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
//        }
//
//        window.setActive();
//        window.clear();
//        window.draw(shape);
//        window.draw(shape2);
//        window.display();
//        sf::sleep(sf::milliseconds(10));
//
//        sf::Vector2f xy = shape.getPosition();
//        std::cout << xy.x << ' ' << xy.y << std::endl;
//
//        auto x = xy.x;
//        auto y = xy.y;
//
//        if (y + speed_y >= 600 - 200 || y + speed_y <= 0)
//        {
//            speed_y *= -1;
//        }
//
//        if (x + speed_x >= 800 - 200 || x + speed_x <= 0)
//        {
//            speed_x *= -1;
//        }
//
//        sf::Vector2f xy2 = shape2.getPosition();
//        std::cout << xy2.x << ' ' << xy2.y << std::endl;
//
//        auto x2 = xy2.x;
//        auto y2 = xy2.y;
//
//        if (y2 + speed_y2 >= 600 - 200 || y2 + speed_y2 <= 0)
//        {
//            speed_y2 *= -1;
//        }
//
//        if (x2 + speed_x2 >= 800 - 200 || x2 + speed_x2 <= 0)
//        {
//            speed_x2 *= -1;
//        }
//
//        shape.setPosition(sf::Vector2f(x + speed_x, y + speed_y));
//        shape2.setPosition(sf::Vector2f(x2 + speed_x2, y2 + speed_y2));
//    }
//
//    return 0;
//}