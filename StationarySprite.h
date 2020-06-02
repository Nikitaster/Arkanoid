#pragma once
#include "Sprite.h"
class StationarySprite : public Sprite {
public:
	inline sf::Sprite &get_sprite() { return this->sprite; }
};

