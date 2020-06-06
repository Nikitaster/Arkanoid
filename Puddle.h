#ifndef Puddle_H
#define Puddle_H

#include "MovableSprite.h"
#include "TexturePuddle.h"

class Puddle: public MovableSprite{
    static TexturePuddle texture;
	int width = this->texture.get_texture().getSize().x;
	int height = this->texture.get_texture().getSize().y;
public:
	Puddle();
    void move(int width = 800);
	int getWidth() { return this->width; }
	int getHeight() { return this->height; }
};

#endif

