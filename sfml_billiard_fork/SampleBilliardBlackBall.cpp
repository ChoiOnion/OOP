#include "SampleBilliardBlackBall.h"
#include "SampleGame.h"

bool SampleBilliardBlackBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse의 XY가 radius 안에 들어오는지 검사 

	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f))
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

bool SampleBilliardBlackBall::isPlayable(void)
{
	return playable;
}

void SampleBilliardBlackBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void SampleBilliardBlackBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool SampleBilliardBlackBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string SampleBilliardBlackBall::getOwner(void)
{
	return owner;
}

void SampleBilliardBlackBall::setNumber(std::string number)
{
	this->number = number;
}

void SampleBilliardBlackBall::render(sf::RenderTarget& target)
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
	ballText.setPosition(getPosition() - sf::Vector2f(5, 8));
	target.draw(ballText);

}

bool SampleBilliardBlackBall::isEightBall(SampleBilliardBall& other)
{
	if (typeid(other) == typeid(SampleBilliardBlackBall)) {
		return true;
	}
}