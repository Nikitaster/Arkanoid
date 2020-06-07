#ifndef GameModel_H
#define GameModel_H

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

#endif