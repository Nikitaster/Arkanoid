#ifndef TextureBall_H
#define TextureBall_H

#include "Texture.cpp"
class TextureBall : public Texture
{
	std::string path = "pokaball.png";
public:
	TextureBall();
	sf::Texture &get_texture() { return this->texture; }
};

#endif
