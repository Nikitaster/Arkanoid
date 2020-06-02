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

class Brick : public StationarySprite {
	static TextureBrick texture;
public:
	Brick(int x = 0, int y = 0, int width = 100, int height = 50) :StationarySprite() {
		sf::Texture texture;
		texture.create(100, 50);
		this->sprite.setTexture(this->texture.get_texture());
		this->sprite.move(x, y);
	}
};

TextureBrick Brick::texture = TextureBrick();

class BrickPile {
public:
	std::vector<Brick> bricks;
	BrickPile()
	{
		this->generate_objects();

	}
	void generate_objects()
	{
		for (int i = 0; i < 150; i += 50)
		{
			for (int j = 0; j < 800; j += 100)
			{
				this->bricks.push_back(Brick(j, i, 100, 50));
				//                this->texture.setRepeated(true);
				//                this->texture.setSmooth(true);
			}
		}
	}
};

class Puddle : public MovableSprite {
	static TexturePuddle texture;
public:
	Puddle() {
		this->velocity = Velocity(0, 5);
		this->sprite.setTexture(texture.get_texture());
		this->sprite.move(800 / 2 - 150, 500);
	}
};

TexturePuddle Puddle::texture = TexturePuddle();


class Puck : public MovableSprite {
	//    sf::Texture texture;
	static TextureBall texture;
public:
	Puck() {
		this->velocity = Velocity(90, 5);
		//        this->texture.loadFromFile(path_brick_sprite, sf::IntRect(0, 0, 50, 50));
		this->sprite.setTexture(texture.get_texture());
		this->sprite.setPosition(800 / 2 - 20, 500 - 40);
	}
};
TextureBall Puck::texture = TextureBall();


class PuckSupply : public Puck {
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
		for (auto it = this->pucks.begin(); it < this->pucks.end(); it++)
		{
			if (!it->isDead)
				return true;
		}
		return false;
	}
	Puck & get_alive_puck()
	{
		for (auto it = this->pucks.begin(); it < this->pucks.end(); it++)
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
