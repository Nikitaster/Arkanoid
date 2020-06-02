#pragma once

#include <vector>
#include "Brick.h"

class BrickPile{
public:
    std::vector<Brick> bricks;

	BrickPile();

	void generate_objects();
};

