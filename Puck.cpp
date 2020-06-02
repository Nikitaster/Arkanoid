#include "Puck.h" 

Puck::Puck(){
	this->velocity = Velocity(90, 5);
	this->texture.loadfromfile(path_brick_sprite, sf::intrect(0, 0, 50, 50));
	this->sprite.settexture(texture.get_texture());
	this->sprite.setposition(800/2 - 20, 500 - 40);
}

TextureBall Puck::texture = TextureBall();