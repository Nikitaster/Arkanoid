#include "Brick.h"


BaseBrick::BaseBrick(int x, int y, int width, int height) :StationarySprite()
{
	sf::Texture texture;
	texture.create(100, 50);
	this->sprite.setTexture(this->texture.get_texture());
	this->sprite.setPosition(sf::Vector2f(x, y));
}
TextureBrick BaseBrick::texture = TextureBrick();

Brick::Brick(int x, int y, int width, int height)
{
	sf::Texture texture;
	texture.create(100, 50);
	this->sprite.setTexture(this->texture.get_texture());
	this->sprite.setPosition(sf::Vector2f(x, y));
}


//void Brick::hitBy() {
//	this->isDead = true;
//}

//
//Brick::~Brick()
//{
//}
