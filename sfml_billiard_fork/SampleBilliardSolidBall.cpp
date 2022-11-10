#include "SampleBilliardSolidBall.h"
#include "SampleGame.h"
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
bool SampleBilliardSolidBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse�� XY�� radius �ȿ� �������� �˻� 

	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f))
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

bool SampleBilliardSolidBall::isPlayable(void)
{
	return playable;
}

void SampleBilliardSolidBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void SampleBilliardSolidBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool SampleBilliardSolidBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string SampleBilliardSolidBall::getOwner(void)
{
	return owner;
}

void SampleBilliardSolidBall::setNumber(std::string number)
{
	this->number = number;
}

void SampleBilliardSolidBall::render(sf::RenderTarget& target)
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
	ballText.setCharacterSize(15);
	ballText.setPosition(getPosition() - sf::Vector2f(7, 10));
	target.draw(ballText);
}