#pragma once

#include "GameSprite.h"

class StationarySprite : public GameSprite {
public:
	inline sf::Sprite &get_sprite() { return this->sprite; }
};

