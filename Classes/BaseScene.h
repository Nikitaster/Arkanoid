#ifndef BaseScene_H
#define BaseScene_H

#include <SFML/Graphics.hpp>

class BaseScene
{
public:
	BaseScene();
	~BaseScene();
	virtual void run(sf::RenderWindow &window) = 0;
};

#endif

