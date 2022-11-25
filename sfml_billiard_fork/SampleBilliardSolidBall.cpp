#include "SampleBilliardSolidBall.h"
#include "SampleGame.h"
#define RGB(r,g,b)          
bool SampleBilliardSolidBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse의 XY가 radius 안에 들어오는지 검사 

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
	// 공 형태 그림 
	target.draw(getVertices());
	// SampleGame에서는 각 공에 플레이어 문자 표시 
	sf::Text ballText;
	ballText.setFont(SampleGame::getFont());
	ballText.setFillColor(sf::Color::Black);
	ballText.setString(number);
	ballText.setCharacterSize(13);
	ballText.setPosition(getPosition() - sf::Vector2f(5, 8));
	target.draw(ballText);
}

bool SampleBilliardSolidBall::isSolidBall(SampleBilliardBall& other)
{
	if (typeid(other) == typeid(SampleBilliardSolidBall)) {
		return true;
	}
}