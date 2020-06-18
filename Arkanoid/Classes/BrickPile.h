#ifndef BrickPile_H
#define BrickPile_H

#include <vector>
#include "Brick.h"

class BrickPile{
	//std::vector<Brick> bricks;
	unsigned size;
	BaseBrick* bricks[255] = {};
	unsigned num_hard_blocks;
public:

	BrickPile(unsigned level = 1, unsigned num_blocks = 7);
	~BrickPile();

	void generate_objects(unsigned level = 1, unsigned num_blocks = 7);
	BaseBrick** get_bricks() { return this->bricks; }
	inline unsigned get_size() { return this->size; }
	void clear()
	{
		for (unsigned i = 0; i < this->size; i++)
		{
			delete this->bricks[i];
		}
	}
	int bricks_left()
	{
		int size = this->size;
		for (unsigned i = 0; i < this->size; i++)
		{
			if (this->bricks[i]->isDead)
				--size;
		}
		return size - this->num_hard_blocks;
	}
};

#endif // BrickPile_H