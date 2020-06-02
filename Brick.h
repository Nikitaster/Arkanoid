#pragma once

#include "StationarySprite.h"
#include "TextureBrick.h"

class Brick: public StationarySprite{
    static TextureBrick texture;
public:
	Brick(int x = 0, int y = 0, int width = 100, int height = 50);
};

