#ifndef BRICK_H
#define BRICK_H

#include "StationarySprite.h"
#include "TextureBrick.h"

class Brick: public StationarySprite{
    static TextureBrick texture;
	int width = this->texture.get_texture().getSize().x;
	int height = this->texture.get_texture().getSize().y;
public:
	Brick(int x = 0, int y = 0, int width = 100, int height = 50);
	void hitBy();
	int getWidth() { return this->width; }
	int getHeight() { return this->height; }
};

#endif // BRICK_H