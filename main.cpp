#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>

static std::string path_brick_sprite = "briques.png";

class Sprite{
protected:
    sf::Sprite sprite;
public:
    bool isDead;
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


class Velocity{
    float speed_x;
    float speed_y;
    int speed;
public:
    Velocity(int direction = 90, int speed = 5)
    {
        this->speed = speed;
        this->setDirection(direction);
    }
    void reverse(){
        this->speed_x *= -1;
        this->speed_y *= -1;
    }
    void reverseX(){
        this->speed_x *= -1;
    }
    void reverseY(){
        this->speed_y *= -1;
    }
    void setDirection(int d) {
        this->speed_x = cos(d * M_PI/180) * (double)this->speed;
        this->speed_y = sin(d * M_PI/180) * (double)this->speed;
    }
    
    int getDirection() {
        return ((int)(atan2(this->speed_y, this->speed_x) * 180/M_PI));
    }
    float & get_speedX() {return this->speed_x;}
    float & get_speedY() {return this->speed_y;}
    
};

class MovableSprite: public Sprite{
public:
    Velocity velocity;
    MovableSprite() {velocity = Velocity();}
    inline sf::Sprite &get_sprite() {return this->sprite;}
    void move()
    {
        this->sprite.move(this->velocity.get_speedX(), this->velocity.get_speedY());
    }
    bool isMoving()
    {
        if (this->velocity.get_speedX() || this->velocity.get_speedY())
            return true;
        return false;
    }
    void collideInto(Sprite &other);
};

class Puddle: public MovableSprite{
    sf::Texture texture;
public:
    Puddle(){
        this->velocity = Velocity(0, 5);
        this->texture.loadFromFile(path_brick_sprite, sf::IntRect(0, 0, 300, 50));
        this->sprite.setTexture(texture);
        this->sprite.move(800/2 - 150, 500);
    }
};


class Puck: public MovableSprite{
    sf::CircleShape shape;
public:
    Puck(){
        this->shape = sf::CircleShape(20.f);
        this->shape.setFillColor(sf::Color::Red);
        this->shape.setPosition(800/2 - 20, 500 - 40);
    }
    inline sf::CircleShape get_shape() {return this->shape;}
};


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


class MainModel {
public:
    BrickPile bricks;
    Puddle puddle;
    PuckSupply pucks;
	MainModel() {}
};

class MainController {
	MainModel *model;
public:
	MainController(MainModel &model)
	{
		this->model = &model;
	}
    void move_puddle_right()
    {
        this->model->puddle.velocity.setDirection(0);
    }
    void move_puddle_left()
    {
        this->model->puddle.velocity.setDirection(180);
    }
    void stop_puddle()
    {
        this->model->puddle.velocity.get_speedX() = 0;
    }
    void move_puddle()
    {
        this->model->puddle.move();
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
        this->model->puddle.velocity.get_speedX() = 0;
	}
    
    void run()
    {
//       сделать меню
        while (this->window.isOpen())
        {
            this->process_events();
            this->process_logic();
//            controller logics
            this->process_draw();
//            sf::sleep(sf::milliseconds(10));
        }
    }
    
    void process_draw()
    {
        this->window.clear();
        //        this->window.draw(shape);
        for (auto it = this->model->bricks.bricks.begin(); it < this->model->bricks.bricks.end(); it++)
            this->window.draw(it->get_sprite());
        
        this->window.draw(this->model->puddle.get_sprite());
        
//        убить мяч
//        this->model->pucks.get_alive_puck().isDead = true;
//        сделать проверку
//        this->model->pucks.have_alive_puck()
//        gameover
        
        this->window.draw(this->model->pucks.get_alive_puck().get_shape());
        
        this->window.display();
    }
    
    void process_logic()
    {
        this->controller->move_puddle();
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
            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right ||
                    event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
                    this->controller->stop_puddle();
            }
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
//
