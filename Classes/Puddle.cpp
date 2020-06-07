#include "Puddle.h"

Puddle::Puddle() {
	this->velocity = Velocity(0, 5);
	this->sprite.setTexture(texture.get_texture());
	this->sprite.move(800 / 2 - 150, 500);
}

TexturePuddle Puddle::texture = TexturePuddle();

void Puddle::move(int width)
{
    if (this->sprite.getPosition().x + this->velocity.get_speedX() + this->sprite.getTextureRect().width >= width
        || this->sprite.getPosition().x + this->velocity.get_speedX() <= 0)
    {
        this->velocity.get_speedX() = 0;
    }
    
    this->sprite.move(this->velocity.get_speedX(), this->velocity.get_speedY());
}
