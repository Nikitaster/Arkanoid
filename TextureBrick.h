#pragma once

#include "Texture.h"
class TextureBrick : public Texture
{
	std::string path = "briques.png";
public:
	TextureBrick();
	sf::Texture &get_texture() { return this->texture; }
};
