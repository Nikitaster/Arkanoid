#include "BrickPile.h"

BrickPile::BrickPile() {
	this->generate_objects();
}

void BrickPile::generate_objects(){
    for (int i = 0; i < 150; i+=50)
	{
        for (int j = 0; j < 800; j+=100)
        {
             this->bricks.push_back(Brick(j, i, 100, 50));
        }
    }
}