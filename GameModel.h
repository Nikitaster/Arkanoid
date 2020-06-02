#pragma once

#include "BrickPile.h"
#include "Puddle.h"
#include "PuckSupply.h"

class GameModel {
public:
	BrickPile bricks;
	Puddle puddle;
	PuckSupply pucks;
	GameModel() {}
};