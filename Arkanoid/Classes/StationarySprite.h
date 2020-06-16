#ifndef StationarySprite_H
#define StationarySprite_H

#include "BaseSprite.h"

class StationarySprite : public BaseSprite {
public:
	inline sf::Sprite &get_sprite() { return this->sprite; }
};

#endif

