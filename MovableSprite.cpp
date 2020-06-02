#include "MovableSprite.h"

MovableSprite::MovableSprite()
{
	velocity = Velocity();
}

void MovableSprite::move() 
{
	this->sprite.move(this->velocity.get_speedX(), this->velocity.get_speedY());
}
bool  MovableSprite::isMoving()
{
	if (this->velocity.get_speedX() || this->velocity.get_speedY())
		return true;
	return false;
}

void  MovableSprite::collideInto(GameSprite &other) {};