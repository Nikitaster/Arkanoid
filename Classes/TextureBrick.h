#ifndef TextureBrick_H
#define TextureBrick_H

#include "Texture.h"
class TextureBrick : public Texture
{
	std::string path = "blockYe.png";
public:
	TextureBrick();
	sf::Texture &get_texture() { return this->texture; }
};

#endif
