#ifndef GameOverScene_H
#define GameOverScene_H

#include "BaseScene.h"
class GameOverScene : public BaseScene {
	sf::Sprite gameOver;
	bool isActive = 1;
	int button_num = 0;
	bool button_pressed = false;
	sf::Texture gameOver_texture;
	sf::Font font1;
	sf::Font font2;
	sf::Text lose;
	sf::Text button1;
	sf::Text button2;
public:
	GameOverScene();

	inline bool getStatement() { return isActive; };
	inline int getButton() { return button_num; };
	inline bool getButtonStatus() { return button_pressed; };

	void run(sf::RenderWindow &window);

	void process_events(sf::RenderWindow &window);

	void process_draw(sf::RenderWindow &window);

	void over_logic(sf::RenderWindow &window);

	void check_button_selected(sf::RenderWindow &window);

	void check_button_pressed(sf::RenderWindow &window);
};

#endif