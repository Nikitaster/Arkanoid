#ifndef Puddle_H
#define Puddle_H

#include "MovableSprite.h"
#include "TexturePuddle.h"

class Puddle: public MovableSprite{
    static TexturePuddle texture;
public:
	Puddle();
    void move(int width = 800);
};

#endif

