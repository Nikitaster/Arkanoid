#ifndef GameBackgroundSprite_H
#define GameBackgroundSprite_H

#include "StationarySprite.h"
#include "GameBackgroundTexture.h"

class GameBackgroundSprite: public StationarySprite
{
	static GameBackgroundTexture texture;
public:
	GameBackgroundSprite();
};

#endif
