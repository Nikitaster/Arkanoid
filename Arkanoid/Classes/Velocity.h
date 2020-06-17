#ifndef Velocity_H
#define Velocity_H

#define _USE_MATH_DEFINES
#include <cmath>

class Velocity {
	float speed_x;
	float speed_y;
	float speed;
public:
	Velocity(int direction = 90, float speed = 5);

	void reverse();
	void reverseX();
	void reverseY();

	void setDirection(int d);
	int getDirection();

	float& get_speedX() { return this->speed_x; }
	float& get_speedY() { return this->speed_y; }

};

#endif

