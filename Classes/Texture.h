#ifndef Texture_H
#define Texture_H

#include <SFML/Graphics.hpp>
class Texture
{
protected:
	sf::Texture texture;
public:
	Texture() {}
	virtual sf::Texture &get_texture() = 0;
};

#endif