#ifndef BrickPile_H
#define BrickPile_H

#include <vector>
#include "Brick.h"

class BrickPile{
	std::vector<Brick> bricks;
public:

	BrickPile();

	void generate_objects();
	std::vector<Brick> & get_bricks() { return this->bricks; }
};

#endif // BrickPile_H