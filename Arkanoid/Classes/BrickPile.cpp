#include "BrickPile.h"
BrickPile::BrickPile() {
	this->generate_objects();
}

void BrickPile::generate_objects(){
    int count = 0;
    for (int i = 35; i < 143 && count < 28; i+=27)
	{
        for (int j = 43; j < 714 && count < 28; j += 102)
        {
            //this->bricks.push_back(Brick(j, i, 100, 25));
            this->bricks[count] = new Bbrick(j, i, 100, 25);
            ++count;
        }
    }
    this->bricks[28] = new Abrick();
}