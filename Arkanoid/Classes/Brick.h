#ifndef BRICK_H
#define BRICK_H

#include "StationarySprite.h"
#include "TextureBrick.h"

class Brick: public StationarySprite{
protected:
    static TextureBrick texture;
	int width = this->texture.get_texture().getSize().x;
	int height = this->texture.get_texture().getSize().y;
public:
	Brick(int x = 0, int y = 0, int width = 100, int height = 50);
	virtual void hitBy() = 0;
	int getWidth() { return this->width; }
	int getHeight() { return this->height; }
};


class Abrick : public Brick {
public:
	Abrick() { this->sprite.setPosition(sf::Vector2f(50, 200)); }
	void hitBy() {};
};

class Bbrick : public Brick {
public:
	Bbrick(int x = 0, int y = 0, int width = 100, int height = 50);
	void hitBy() {
		this->isDead = true;
	}
};

#endif // BRICK_H