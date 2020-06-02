#ifndef BRICK_H
#define BRICK_H

#include "StationarySprite.h"
#include "TextureBrick.h"

class Brick: public StationarySprite{
    static TextureBrick texture;
public:
	Brick(int x = 0, int y = 0, int width = 100, int height = 50);
};

#endif // BRICK_H