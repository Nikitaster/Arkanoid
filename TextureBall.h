#pragma once

#include "Texture.cpp"
class TextureBall : public Texture
{
	std::string path = "50px-Floorball_ball.svg.png";
public:
	TextureBall();
	sf::Texture &get_texture() { return this->texture; }
};
