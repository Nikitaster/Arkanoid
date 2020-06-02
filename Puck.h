#ifndef Puck_H
#define Puck_H

#include "MovableSprite.h"
#include "TextureBall.h"

class Puck: public MovableSprite{
//    sf::Texture texture;
    static TextureBall texture;
public:
	Puck();
};

#endif