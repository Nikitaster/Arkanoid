#ifndef TexturePuddle_H
#define TexturePuddle_H

#include "Texture.h"
class TexturePuddle : public Texture
{
	std::string path = "Arkanoid\\puddle.png";
public:
	TexturePuddle();
	sf::Texture &get_texture() { return this->texture; }
};

#endif

