#include "GameController.h"

GameController::GameController(GameModel &model)
{
	this->model = &model;
}

void GameController::move_puddle_right()
{
	this->model->puddle.velocity.setDirection(0);
}

void GameController::move_puddle_left()
{
	this->model->puddle.velocity.setDirection(180);
}

void GameController::stop_puddle()
{
	this->model->puddle.velocity.get_speedX() = 0;
}

void GameController::move_puddle()
{
	this->model->puddle.move();
}