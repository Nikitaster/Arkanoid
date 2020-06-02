#include "Puck.h" 
#include <iostream>

Puck::Puck(){
	this->velocity = Velocity(45, 5);
	this->sprite.setTexture(texture.get_texture());
	this->sprite.setPosition(800 / 2 - 20, 500 - 40 - 100);

}

TextureBall Puck::texture = TextureBall();

void Puck::move(int width, int height)
{
	if (this->sprite.getPosition().x + this->velocity.get_speedX() + this->sprite.getTextureRect().width >= width
		|| this->sprite.getPosition().x + this->velocity.get_speedX() <= 0)
	{
		this->velocity.reverseX();
	}
	if (this->sprite.getPosition().y + this->velocity.get_speedY() <= 0)
	{
		this->velocity.reverseY();
	}
	if (this->sprite.getPosition().y + this->velocity.get_speedY() - this->sprite.getTextureRect().height/2 >= height)
	{
		this->isDead = true;
	}
	
	this->sprite.move(this->velocity.get_speedX(), this->velocity.get_speedY());
}

void Puck::collideInto(GameSprite &other)
{
	if (Collision::PixelPerfectTest(this->get_sprite(), other.get_sprite()))
	{
		/*std::cout << "Direction " << this->velocity.getDirection() << std::endl;
		std::cout << "COLLIDE" << std::endl;

		auto puddleX = other.get_sprite().getPosition().x;
		auto puckX = this->get_sprite().getPosition().x;

		std::cout << "puddleX " << puddleX << ' ' << "puckX " << puckX << std::endl;
		std::cout << "Direction " << this->velocity.getDirection() << std::endl;

		if (puckX + 25 <= 300/3 + puddleX)
		{
			std::cout << "COLLIDE LEFT" << std::endl;
			if (this->velocity.getDirection() > 90)
			{
				this->velocity.setDirection(this->velocity.getDirection() + 90 - 70);
			}
			else if (this->velocity.getDirection() < 90)
			{
				this->velocity.reverse();
			}
			this->sprite.move(0, -1);
		}
		else if (puckX + 25 <= 300 + puddleX && puckX + 25.0 >= 300/3*2 + puddleX)
		{
			std::cout << "COLLIDE RIGHT" << std::endl;
			if (this->velocity.getDirection() > 90)
			{
				this->velocity.reverse();
			}
			else if (this->velocity.getDirection() < 90)
			{
				this->velocity.setDirection(this->velocity.getDirection() - 70);
			}
			this->sprite.move(0, -1);
		}
		else
		{
			std::cout << "COLLIDE CENTER" << std::endl;
			if (this->velocity.getDirection() > 90)
			{
				this->velocity.setDirection(this->velocity.getDirection() + 70);
			}
			else if (this->velocity.getDirection() < 90)
			{
				this->velocity.setDirection(this->velocity.getDirection() - 90);
			}
			this->sprite.move(0, -1);
		}*/
		this->velocity.reverseY();
	}
};