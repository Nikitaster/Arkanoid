#include "Velocity.h"

Velocity::Velocity(int direction, float speed)
{
	this->speed = speed;
	this->setDirection(direction);
}

void Velocity::reverse() {
	this->speed_x *= -1;
	this->speed_y *= -1;
}

void Velocity::reverseX() {
	this->speed_x *= -1;
}

void Velocity::reverseY() {
	this->speed_y *= -1;
}

void Velocity::setDirection(int d) {
	this->speed_x = (double)cos(d * M_PI / 180.0) * (double)this->speed;
	this->speed_y = (double)sin(d * M_PI / 180.0) * (double)this->speed;
}

int Velocity::getDirection() {
	return (round((atan2(this->speed_y, this->speed_x)) * 180.0 / M_PI));
}