#include <SFML/Graphics.hpp>
class Texture
{
protected:
	sf::Texture texture;
public:
	Texture() {}
	virtual sf::Texture &get_texture() = 0;
};
