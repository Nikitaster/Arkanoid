#pragma once

#include "Texture.h"
class TexturePuddle : public Texture
{
	std::string path = "briques.png";
public:
	TexturePuddle();
	sf::Texture &get_texture() { return this->texture; }
};

