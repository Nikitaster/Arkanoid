#include "Brick.h"


Brick::Brick(int x, int y, int width, int height):StationarySprite()
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
