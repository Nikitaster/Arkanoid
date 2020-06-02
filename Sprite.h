#include <SFML/Graphics.hpp>
class Sprite {
protected:
	sf::Sprite sprite;
public:
	bool isDead;
	Sprite();
	virtual sf::Sprite &get_sprite() = 0;
};

