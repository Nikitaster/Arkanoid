#include "Puck.h" 
#include <iostream>

Puck::Puck(){
	this->velocity = Velocity(90, 8);
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
	if (this->sprite.getPosition().y + this->velocity.get_speedY() <= 30)
	{
		this->velocity.reverseY();
	}
	if (this->sprite.getPosition().y + this->velocity.get_speedY() - this->sprite.getTextureRect().height/2 >= height)
	{
		this->isDead = true;
	}
	if (abs(this->velocity.getDirection()) == 180 || abs(this->velocity.getDirection()) == 360) 
	{
		this->velocity.setDirection(this->velocity.getDirection() + 10);
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

		std::cout << "puddleX " << puddleX << ' ' << "puckX " << puckX << std::endl;
		std::cout << "Direction " << this->velocity.getDirection() << std::endl;

		if (puckY + this->getHeight() / 2 < puddleY)
		{
			this->get_sprite().setPosition(puckX, puddleY - this->getHeight());

			if (puckX + this->getWidth() <= puddle.getWidth() / 3 + puddleX)
			{
				std::cout << "COLLIDE LEFT" << std::endl;

				if (this->velocity.getDirection() >= 90)
				{
					this->velocity.setDirection(-this->velocity.getDirection() - 20);
					//this->velocity.setDirection(-this->velocity.getDirection() - this->velocity.getDirection()/2);
				}
				else if (this->velocity.getDirection() < 90)
				{
					this->velocity.reverse();
				}
			}
			else if (puckX <= puddle.getWidth() + puddleX && puckX >= puddle.getWidth() / 3 * 2 + puddleX)
			{
				std::cout << "COLLIDE RIGHT" << std::endl;
				if (this->velocity.getDirection() > 90)
				{
					this->velocity.reverse();
				}
				else if (this->velocity.getDirection() <= 90)
				{
					this->velocity.setDirection(-this->velocity.getDirection() + 20);
					//this->velocity.setDirection(-this->velocity.getDirection() + this->velocity.getDirection() / 2);
				}
			}
			else
			{
				std::cout << "COLLIDE CENTER" << std::endl;
				if (this->velocity.getDirection() > 90)
				{
					this->velocity.setDirection(-this->velocity.getDirection() + 20);
					//this->velocity.setDirection(-this->velocity.getDirection() + this->velocity.getDirection() / 2);
				}
				else if (this->velocity.getDirection() < 90)
				{
					this->velocity.setDirection(-this->velocity.getDirection() - 20);
					//this->velocity.setDirection(-this->velocity.getDirection() - this->velocity.getDirection() / 2);
				}
				else {
					this->velocity.reverse();
				}
			}
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

bool Puck::collideInto(BaseBrick& brick)
{
	bool kill = false;
	if (Collision::PixelPerfectTest(this->get_sprite(), brick.get_sprite()))
	{

		auto brickX = brick.get_sprite().getPosition().x;
		auto puckX = this->get_sprite().getPosition().x;

		auto brickY = brick.get_sprite().getPosition().y;
		auto puckY = this->get_sprite().getPosition().y;


		std::cout << "Direction " << this->velocity.getDirection() << std::endl;
		std::cout << "BRICK COLLIDE" << std::endl;
		if (brick.hitBy())
			kill = true;

		if (puckY + this->getWidth() / 2 > brickY + brick.getHeight())
		{
			std::cout << "NO! NO! NO!" << std::endl;
			this->get_sprite().setPosition(puckX, brickY + brick.getHeight());
			this->velocity.reverseY();
		}
		else if (puckY + this->getWidth() / 2 < brickY)
		{
			std::cout << "NO! NO! NO!" << std::endl;
			this->get_sprite().setPosition(puckX, brickY - this->getHeight());
			this->velocity.reverseY();
		}
		else if (puckX < brickX)
		{
			std::cout << "SIDE SIDE SIDE" << std::endl;
			this->get_sprite().setPosition(brickX - this->getWidth(), puckY);
			this->velocity.reverseX();
		}
		else
		{
			std::cout << "SIDE SIDE SIDE" << std::endl;
			this->get_sprite().setPosition(brickX + brick.getWidth(), puckY);
			this->velocity.reverseX();
		}
		std::cout << "NEW DIRECTION " << this->velocity.getDirection() << std::endl;
		return kill;
	}
	return kill;
}
