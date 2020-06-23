#include "BrickPile.h"
BrickPile::BrickPile(unsigned level, unsigned num_blocks) {
    this->num_hard_blocks = 0;
	this->generate_objects(level, num_blocks);
}

void BrickPile::generate_objects(unsigned level, unsigned num_blocks){
    this->size = num_blocks;
    int count = 0;
    int max_col = 714;
    int row = 35;
    int col = 43;
    int drow = 27;
    int dcol = 102;
    while (count < this->size)
    {
        if (count % 7 == 0 && count)
            row = row + drow;
        this->bricks[count] = new Brick(col, row, 100, 25);
        col = (col + dcol) % max_col;
        ++count;
    }
    if (level == 2)
    {
        this->bricks[num_blocks] = new Abrick();
        this->size++;
        this->num_hard_blocks = 1;
    }
	if (level == 3) {
		this->num_hard_blocks = 0;
	}
}

BrickPile::~BrickPile()
{
    for (unsigned i = 0; i < this->size; i++)
    {
        delete this->bricks[i];
    }
}