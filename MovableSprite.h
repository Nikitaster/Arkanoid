#pragma once

#include "GameSprite.h"
#include "Velocity.h"

class MovableSprite : public GameSprite {
public:
	Velocity velocity;

	MovableSprite();

	inline sf::Sprite &get_sprite() { return this->sprite; }

	void move();
	bool isMoving();
	void collideInto(GameSprite &other);
};
