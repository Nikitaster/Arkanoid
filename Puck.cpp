#include "Puck.h" 
#include <iostream>

Puck::Puck(){
	this->velocity = Velocity(80, 8);
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

void Puck::collideInto(Puddle &puddle)
{
	if (Collision::PixelPerfectTest(this->get_sprite(), puddle.get_sprite()))
	{
		std::cout << "COLLIDE" << std::endl;

		auto puddleX = puddle.get_sprite().getPosition().x;
		auto puckX = this->get_sprite().getPosition().x;

		auto puddleY = puddle.get_sprite().getPosition().y;
		auto puckY = this->get_sprite().getPosition().y;

		//auto puddleWidth = puddle.getWidth();
		//auto puddleHeight = puddle.getHeight();

		//auto puckWidth = this->getWidth();
		//auto puckHeight = this->getHeight();

		std::cout << "puddleX " << puddleX << ' ' << "puckX " << puckX << std::endl;
		std::cout << "Direction " << this->velocity.getDirection() << std::endl;

		//if (puckX + this->getWidth()/2 > puddleX || puckX < puddleX + puddle.getWidth()) 
		if (puckY + this->getHeight() / 2 < puddleY)
		{
			this->get_sprite().setPosition(puckX, puddleY - 50);
			//if (puckX + 50 <= 300/3 + puddleX)
			if (puckX + this->getWidth() <= puddle.getWidth() / 3 + puddleX)
			{
				std::cout << "COLLIDE LEFT" << std::endl;

				if (this->velocity.getDirection() >= 90)
				{
					//this->velocity.setDirection(this->velocity.getDirection() + 90 - 70);
					this->velocity.setDirection(-this->velocity.getDirection() - 20);
					//this->velocity.setDirection(-this->velocity.getDirection() - this->velocity.getDirection()/2);
				}
				else if (this->velocity.getDirection() < 90)
				{
					this->velocity.reverse();
				}
			}
			//else if (puckX <= 300 + puddleX && puckX >= 300/3*2 + puddleX)
			else if (puckX <= puddle.getWidth() + puddleX && puckX >= puddle.getWidth() / 3 * 2 + puddleX)
			{
				std::cout << "COLLIDE RIGHT" << std::endl;
				if (this->velocity.getDirection() > 90)
				{
					this->velocity.reverse();
				}
				else if (this->velocity.getDirection() <= 90)
				{
					//this->velocity.setDirection(this->velocity.getDirection() - 70);
					this->velocity.setDirection(-this->velocity.getDirection() + 20);
					//this->velocity.setDirection(-this->velocity.getDirection() + this->velocity.getDirection() / 2);
				}
			}
			else
			{
				std::cout << "COLLIDE CENTER" << std::endl;
				if (this->velocity.getDirection() > 90)
				{
					//this->velocity.setDirection(this->velocity.getDirection() + 70);
					this->velocity.setDirection(-this->velocity.getDirection() + 20);
					//this->velocity.setDirection(-this->velocity.getDirection() + this->velocity.getDirection() / 2);
				}
				else if (this->velocity.getDirection() < 90)
				{
					//this->velocity.setDirection(this->velocity.getDirection() - 90);
					this->velocity.setDirection(-this->velocity.getDirection() - 20);
					//this->velocity.setDirection(-this->velocity.getDirection() - this->velocity.getDirection() / 2);
				}
				else {
					this->velocity.reverse();
				}
				//this->sprite.move(0, -1);
			}

			//this->velocity.reverseY();
		}
		else {
			std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
			if (puckX < puddleX) {
				this->get_sprite().setPosition(puddleX - this->getWidth(), puckY);
			}
			else 
			{
				this->get_sprite().setPosition(puddleX + puddle.getWidth(), puckY);
			}

			this->velocity.reverseX();
		}
		

		std::cout << "NEW DIRECTION " << this->velocity.getDirection() << std::endl;
	}
};

void Puck::collideInto(Brick &brick)
{
	if (Collision::PixelPerfectTest(this->get_sprite(), brick.get_sprite()))
	{
		std::cout << "Direction " << this->velocity.getDirection() << std::endl;
		std::cout << "BRICK COLLIDE" << std::endl;
		brick.hitBy();

		if (this->sprite.getPosition().y + this->getWidth() / 2 < brick.get_sprite().getPosition().y ||
			this->sprite.getPosition().y + this->getWidth() / 2 > brick.get_sprite().getPosition().y + brick.getHeight())
		{
			std::cout << "NO! NO! NO!" << std::endl;
			this->velocity.reverseY();
		}
		else
		{
			std::cout << "SIDE SIDE SIDE" << std::endl;
			this->velocity.reverseX();
		}
		std::cout << "NEW DIRECTION " << this->velocity.getDirection() << std::endl;
	}
}
