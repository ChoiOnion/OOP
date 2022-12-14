#include "StripeBall.h"
#include "SampleGame.h"

bool StripeBall::isPlayable(void)
{
	return playable;
}

void StripeBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void StripeBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool StripeBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string StripeBall::getOwner(void)
{
	return owner;
}

void StripeBall::setNumber(std::string number)
{
	this->number = number;
}

void StripeBall::render(sf::RenderTarget& target)
{
	// 공 형태 그림 
	target.draw(getVertices());
	sf::Text ballText;
	ballText.setFont(SampleGame::getFont());
	ballText.setFillColor(sf::Color::Black);
	ballText.setOutlineColor(sf::Color::White);
	ballText.setOutlineThickness(2);
	ballText.setString(number);
	ballText.setCharacterSize(13);
	ballText.setPosition(getPosition() - sf::Vector2f(8, 8));
	target.draw(ballText);
}

bool StripeBall::isStripeBall(Ball& other)
{
	if (typeid(other) == typeid(StripeBall)) {
		return true;
	}
}