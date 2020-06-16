#ifndef GameWinScene_H
#define GameWinScene_H


/*class GameWinScene {
sf::Sprite gameWin;
bool isActive = 1;
int button_num = 0;
bool button_pressed = false;
sf::Texture gameOver_texture;
sf::Font font1;
sf::Font font2;
sf::Text win;
sf::Text button1;
sf::Text button2;
public:
GameOverScene() {
button1.setPosition(260, 225);
button2.setPosition(353, 275);
win.setPosition(200, 150);
this->isActive = 1;
this->button_pressed = false;
this->button_num = 0;
font1.loadFromFile("font2.ttf");
font2.loadFromFile("font3.ttf");
gameWin_texture.loadFromFile("winner.png");
gameWin.setTexture(gameWin_texture);
button1.setFont(font2);
button2.setFont(font2);
win.setFont(font1);
win.setCharacterSize(60);
button1.setCharacterSize(50);
button2.setCharacterSize(50);
button1.setString("try again");
button2.setString("exit");
win.setString("Congrats, you win!");
}

inline bool getStatement() { return isActive; };
inline int getButton() { return button_num; };
inline bool getButtonStatus() { return button_pressed; };

void run(sf::RenderWindow& window)
{
this->process_draw(window);
this->process_events(window);
}

void process_events(sf::RenderWindow& window)
{
sf::Event event;
while (window.pollEvent(event))
{
if (event.type == sf::Event::Closed)
window.close();
}
}

void process_draw(sf::RenderWindow& window)
{
window.clear();
button1.setFillColor(sf::Color(61, 31, 115));
button2.setFillColor(sf::Color(61, 31, 115));
win.setFillColor(sf::Color::Orange);
this->over_logic(window);
window.draw(gameWin);
window.draw(button1);
window.draw(button2);
window.draw(win);
window.display();
}

void over_logic(sf::RenderWindow& window) {
this->check_button_selected(window);
this->check_button_pressed(window);
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
window.close();
}

void check_button_selected(sf::RenderWindow& window) {
this->button_pressed = false;
if (sf::IntRect(260, 250, 235, 28).contains(sf::Mouse::getPosition(window))) {
this->button1.setFillColor(sf::Color::Blue);
this->button_num = 1;
}
else if (sf::IntRect(353, 300, 94, 28).contains(sf::Mouse::getPosition(window))) {
this->button2.setFillColor(sf::Color::Blue);
this->button_num = 2;
}
else
this->button_num = 0;
}

void check_button_pressed(sf::RenderWindow& window) {
if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
{
this->button_pressed = true;
if (button_num == 1) {
this->isActive = false;
}
if (button_num == 2) {
window.close();
this->isActive = false;
}
}
}
};*/

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