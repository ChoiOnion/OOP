#include "BlackBall.h"
#include "SampleGame.h"
 
bool  BlackBall::isPlayable(void)
{
	return playable;
}

void  BlackBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void  BlackBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool  BlackBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string  BlackBall::getOwner(void)
{
	return owner;
}

void  BlackBall::setNumber(std::string number)
{
	this->number = number;
}

void  BlackBall::render(sf::RenderTarget& target)
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

bool  BlackBall::isEightBall( Ball& other)
{
	if (typeid(other) == typeid( BlackBall)) {
		return true;
	}
}