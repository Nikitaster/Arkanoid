#include "Brick.h"



Brick::Brick()
{
	sf::Texture texture;
	texture.create(100, 50);
	this->sprite.setTexture(this->texture.get_texture());
	this->sprite.move(x, y);
}

TextureBrick Brick::texture = TextureBrick();

//
//Brick::~Brick()
//{
//}
