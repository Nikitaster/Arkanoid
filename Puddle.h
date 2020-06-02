#pragma once

#include "MovableSprite.h"
#include "TexturePuddle.h"

class Puddle: public MovableSprite{
    static TexturePuddle texture;
public:
	Puddle();
};

