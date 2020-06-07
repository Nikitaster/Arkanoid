#ifndef MovableSprite_H
#define MovableSprite_H

#include "BaseSprite.h"
#include "Velocity.h"
#include "Collision.h"

class MovableSprite : public BaseSprite {
public:
	Velocity velocity;

	MovableSprite();

	inline sf::Sprite &get_sprite() { return this->sprite; }

	void move();
	bool isMoving();
	void collideInto(BaseSprite &other);
};

#endif
