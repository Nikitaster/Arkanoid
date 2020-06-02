#pragma once

#include "GameModel.h"

class GameController {
	GameModel *model;
public:
	GameController(GameModel &model);
	void move_puddle_right();
	void move_puddle_left();
	void stop_puddle();
	void move_puddle();
};
