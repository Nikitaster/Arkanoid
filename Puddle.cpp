#include "Puddle.h"

Puddle::Puddle() {
	this->velocity = Velocity(0, 5);
	this->sprite.setTexture(texture.get_texture());
	this->sprite.move(800 / 2 - 150, 500);
}

TexturePuddle Puddle::texture = TexturePuddle();
