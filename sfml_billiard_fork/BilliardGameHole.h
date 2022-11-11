#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "BilliardHole.h"

class BilliardGameHole : public BilliardHole
{
public:
	using BilliardHole::BilliardHole;

	bool isIntersecting(sf::Vector2f ball);

};
