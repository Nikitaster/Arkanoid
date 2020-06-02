#pragma once

#include <SFML/Graphics.hpp>

class GameSprite {
protected:
	sf::Sprite sprite;
public:
	bool isDead;
	GameSprite();
	virtual sf::Sprite &get_sprite() = 0;
};

