#ifndef GameBackgroundTexture_H
#define GameBackgroundTexture_H

#include "Texture.h"
class GameBackgroundTexture : public Texture
{
	std::string path = "game.png";
public:
	GameBackgroundTexture();
	sf::Texture &get_texture() { return this->texture; }
};

#endif

