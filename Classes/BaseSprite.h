#ifndef BaseSprite_H
#define BaseSprite_H

#include <SFML/Graphics.hpp>

class BaseSprite {
protected:
	sf::Sprite sprite;
public:
	bool isDead;
	BaseSprite();
	virtual sf::Sprite &get_sprite() = 0;
};

#endif

