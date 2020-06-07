#include "GameBackgroundSprite.h"

GameBackgroundSprite::GameBackgroundSprite()
{
	this->sprite.setTexture(this->texture.get_texture());
}

GameBackgroundTexture GameBackgroundSprite::texture = GameBackgroundTexture();