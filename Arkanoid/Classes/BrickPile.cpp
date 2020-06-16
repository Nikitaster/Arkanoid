#include "BrickPile.h"

BrickPile::BrickPile() {
	this->generate_objects();
}

void BrickPile::generate_objects(){
    for (int i = 35; i < 143; i+=27)
	{
        for (int j = 43; j < 714; j+=102)
        {
             this->bricks.push_back(Brick(j, i, 100, 25));
        }
    }
}