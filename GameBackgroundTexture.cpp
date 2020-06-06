#include "GameBackgroundTexture.h"

GameBackgroundTexture::GameBackgroundTexture()
{
	this->texture.loadFromFile(this->path, sf::IntRect(0, 0, 800, 600));
}