#include "SampleBilliardPlayerBall.h"
#include "SampleGame.h"
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
bool SampleBilliardPlayerBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse�� XY�� radius �ȿ� �������� �˻� 

	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f))
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

bool SampleBilliardPlayerBall::isPlayable(void)
{
	return playable;
}

void SampleBilliardPlayerBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void SampleBilliardPlayerBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool SampleBilliardPlayerBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string SampleBilliardPlayerBall::getOwner(void)
{
	return owner;
}

void SampleBilliardPlayerBall::setNumber(std::string number)
{
	this->number = number;
}

void SampleBilliardPlayerBall::render(sf::RenderTarget& target)
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