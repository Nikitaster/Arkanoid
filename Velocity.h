#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

class Velocity {
	float speed_x;
	float speed_y;
	int speed;
public:
	Velocity(int direction = 90, int speed = 5);

	void reverse();
	void reverseX();
	void reverseY();

	void setDirection(int d);
	int getDirection();

	float & get_speedX() { return this->speed_x; }
	float & get_speedY() { return this->speed_y; }

};

