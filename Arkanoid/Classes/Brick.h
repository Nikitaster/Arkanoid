#ifndef BRICK_H
#define BRICK_H

#include "StationarySprite.h"
#include "TextureBrick.h"

class BaseBrick: public StationarySprite{
protected:
    static TextureBrick texture;
	int width = this->texture.get_texture().getSize().x;
	int height = this->texture.get_texture().getSize().y;
public:
	BaseBrick(int x = 0, int y = 0, int width = 100, int height = 50);
	virtual bool hitBy() = 0;
	int getWidth() { return this->width; }
	int getHeight() { return this->height; }
};

class Brick : public BaseBrick {
public:
	Brick(int x = 0, int y = 0, int width = 100, int height = 50);
	bool hitBy() {
		this->isDead = true;
		return this->isDead;
	}
};

class Abrick : public BaseBrick {
public:
	Abrick() { this->sprite.setPosition(sf::Vector2f(50, 200)); }
	bool hitBy() { return this->isDead; };
};



#endif // BRICK_H