#include "SolidBall.h"
#include "SampleGame.h"

bool SolidBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse�� XY�� radius �ȿ� �������� �˻� 

	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f))
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

bool SolidBall::isPlayable(void)
{
	return playable;
}

void SolidBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void SolidBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool SolidBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string SolidBall::getOwner(void)
{
	return owner;
}

void SolidBall::setNumber(std::string number)
{
	this->number = number;
}

void SolidBall::render(sf::RenderTarget& target)
{
	// �� ���� �׸� 
	target.draw(getVertices());
	// SampleGame������ �� ���� �÷��̾� ���� ǥ�� 
	sf::Text ballText;
	ballText.setFont(SampleGame::getFont());
	ballText.setFillColor(sf::Color::Black);
	ballText.setString(number);
	ballText.setCharacterSize(13);
	ballText.setPosition(getPosition() - sf::Vector2f(5, 8));
	target.draw(ballText);
}

bool SolidBall::isSolidBall(Ball& other)
{
	if (typeid(other) == typeid(SolidBall)) {
		return true;
	}
}