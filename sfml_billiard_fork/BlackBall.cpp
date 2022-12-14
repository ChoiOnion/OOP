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
	ballText.setPosition(getPosition() - sf::Vector2f(5, 8));
	target.draw(ballText);

}

bool  BlackBall::isEightBall( Ball& other)
{
	if (typeid(other) == typeid( BlackBall)) {
		return true;
	}
}