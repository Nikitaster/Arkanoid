#ifndef GameSprite_H
#define GameSprite_H

#include <SFML/Graphics.hpp>

class GameSprite {
protected:
	sf::Sprite sprite;
public:
	bool isDead;
	GameSprite();
	virtual sf::Sprite &get_sprite() = 0;
};

#endif

