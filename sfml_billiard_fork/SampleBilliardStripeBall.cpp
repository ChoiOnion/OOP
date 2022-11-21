#include "SampleBilliardStripeBall.h"
#include "SampleGame.h"
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
bool SampleBilliardStripeBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse의 XY가 radius 안에 들어오는지 검사 

	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f))
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

bool SampleBilliardStripeBall::isPlayable(void)
{
	return playable;
}

void SampleBilliardStripeBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void SampleBilliardStripeBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool SampleBilliardStripeBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string SampleBilliardStripeBall::getOwner(void)
{
	return owner;
}

void SampleBilliardStripeBall::setNumber(std::string number)
{
	this->number = number;
}

void SampleBilliardStripeBall::render(sf::RenderTarget& target)
{
	// 공 형태 그림 
	target.draw(getVertices());
	// SampleGame에서는 각 공에 플레이어 문자 표시 
	sf::Text ballText;
	ballText.setFont(SampleGame::getFont());
	ballText.setFillColor(sf::Color::Black);
	ballText.setOutlineColor(sf::Color::White);
	ballText.setOutlineThickness(2);
	ballText.setString(number);
	ballText.setCharacterSize(13);
	ballText.setPosition(getPosition() - sf::Vector2f(8, 10));
	target.draw(ballText);
	
	//sf::Shape::setOutlineColor(sf::Color::Red);
	
}

bool SampleBilliardStripeBall::isStripeBall(SampleBilliardBall& other)
{
	if (typeid(other) == typeid(SampleBilliardStripeBall)) {
		return true;
	}
}