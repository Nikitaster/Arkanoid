#include "BaseScene.h"

#ifndef GameWinScene_H
#define GameWinScene_H


class GameWinScene : public BaseScene {
	sf::Sprite gameWin;
	bool isActive = 1;
	int button_num = 0;
	bool button_pressed = false;
	sf::Texture gameWin_texture;
	sf::Font font1;
	sf::Font font2;
	sf::Text win;
	sf::Text button1;
	sf::Text button2;
public:
	GameWinScene();

	inline bool getStatement() { return isActive; };
	inline int & getButton() { return button_num; };
	inline bool & getButtonStatus() { return button_pressed; };

	void run(sf::RenderWindow &window);

	void process_events(sf::RenderWindow &window);

	void process_draw(sf::RenderWindow &window);

	void win_logic(sf::RenderWindow &window);

	void check_button_selected(sf::RenderWindow &window);

	void check_button_pressed(sf::RenderWindow &window);
};

//typedef int(*IntFunctionWithOneParameter) (int a);
//
//int function(int a) { return a; }
//int functionTimesTwo(int a) { return a * 2; }
//int functionDivideByTwo(int a) { return a / 2; }
//
//void main()
//{
//	//map<string, int(*)(int a)> dict;
//	map<string, IntFunctionWithOneParameter> dict;
//
//	dict["first"] = function;
//	dict["second"] = functionTimesTwo;
//
//	cout << dict["second"](10) << endl;

#endif