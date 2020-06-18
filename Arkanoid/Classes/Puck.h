#ifndef Puck_H
#define Puck_H

#include "MovableSprite.h"
#include "TextureBall.h"
#include "Puddle.h"
#include "Brick.h"

class Puck: public MovableSprite{
//    sf::Texture texture;
    static TextureBall texture;
	int width = this->texture.get_texture().getSize().x;
	int height = this->texture.get_texture().getSize().y;
public:
	Puck();
	void move(int width = 800, int height = 600);
	void collideInto(Puddle &puddle);
    bool collideInto(BaseBrick &brick);
	int getWidth() { return this->width; }
	int getHeight() { return this->height; }
};

#endif
