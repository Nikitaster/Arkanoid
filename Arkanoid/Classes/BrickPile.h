#ifndef BrickPile_H
#define BrickPile_H

#include <vector>
#include "Brick.h"

class BrickPile{
	//std::vector<Brick> bricks;
	Brick* bricks[29] = {};
public:

	BrickPile();

	void generate_objects();
	Brick ** get_bricks() { return this->bricks; }
};

#endif // BrickPile_H