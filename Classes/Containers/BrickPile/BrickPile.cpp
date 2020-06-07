#include "BrickPile.h"

BrickPile::BrickPile() {
	this->generate_objects();
}

void BrickPile::generate_objects(){
    for (int i = 0; i < 150; i+=55)
	{
        for (int j = 0; j < 800; j+=105)
        {
             this->bricks.push_back(Brick(j, i, 100, 50));
        }
    }
}