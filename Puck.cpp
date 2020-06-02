#include "Puck.h" 

Puck::Puck(){
	this->velocity = Velocity(90, 5);
	this->sprite.setTexture(texture.get_texture());
	this->sprite.setPosition(800 / 2 - 20, 500 - 40);

}

TextureBall Puck::texture = TextureBall();