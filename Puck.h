#ifndef Puck_H
#define Puck_H

#include "MovableSprite.h"
#include "TextureBall.h"

class Puck: public MovableSprite{
//    sf::Texture texture;
    static TextureBall texture;
public:
	Puck();
	void move(int width = 800, int height = 600);
	void collideInto(GameSprite &other);
};

#endif