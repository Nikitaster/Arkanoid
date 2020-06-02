#ifndef BrickPile_H
#define BrickPile_H

#include <vector>
#include "Brick.h"

class BrickPile{
public:
    std::vector<Brick> bricks;

	BrickPile();

	void generate_objects();
};

#endif // BrickPile_H