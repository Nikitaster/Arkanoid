#include <iostream>
#include "Collision.h"
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

void  MovableSprite::collideInto(BaseSprite &other)
{
	if (Collision::PixelPerfectTest(this->get_sprite(), other.get_sprite()))
	{
		std::cout << "COLLIDE" << std::endl;
	}
};