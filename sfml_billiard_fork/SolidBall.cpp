#include "SolidBall.h"
#include "SampleGame.h"

bool SolidBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse의 XY가 radius 안에 들어오는지 검사 

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

bool SolidBall::isSolidBall(Ball& other)
{
	if (typeid(other) == typeid(SolidBall)) {
		return true;
	}
}