#include "GameView.h"

int main()
{
	GameModel model;
	GameController controller(model);
	GameView view(model, controller);
	view.run();

	return 0;
}
