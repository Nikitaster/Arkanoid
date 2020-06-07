#ifndef StationarySprite_H
#define StationarySprite_H

#include "GameSprite.h"

class StationarySprite : public GameSprite {
public:
	inline sf::Sprite &get_sprite() { return this->sprite; }
};

#endif

