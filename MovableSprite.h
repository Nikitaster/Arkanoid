#include "Sprite.h"
#include "Velocity.cpp"

class MovableSprite : public Sprite {
public:
	Velocity velocity;

	MovableSprite();

	inline sf::Sprite &get_sprite() { return this->sprite; }

	void move();
	bool isMoving();
	void collideInto(Sprite &other);
};
