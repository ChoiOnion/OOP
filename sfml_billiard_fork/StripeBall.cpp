#include "StripeBall.h"
#include "SampleGame.h"

bool StripeBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse�� XY�� radius �ȿ� �������� �˻� 

	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f))
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

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
	// �� ���� �׸� 
	target.draw(getVertices());
	// SampleGame������ �� ���� �÷��̾� ���� ǥ�� 
	sf::Text ballText;
	ballText.setFont(SampleGame::getFont());
	ballText.setFillColor(sf::Color::Black);
	ballText.setOutlineColor(sf::Color::White);
	ballText.setOutlineThickness(2);
	ballText.setString(number);
	ballText.setCharacterSize(13);
	ballText.setPosition(getPosition() - sf::Vector2f(8, 8));
	target.draw(ballText);
	
	//sf::Shape::setOutlineColor(sf::Color::Red);
}

bool StripeBall::isStripeBall(Ball& other)
{
	if (typeid(other) == typeid(StripeBall)) {
		return true;
	}
}