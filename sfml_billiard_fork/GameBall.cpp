#include "GameBall.h"
#include "SampleGame.h"

bool  GameBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse의 XY가 radius 안에 들어오는지 검사 
	
	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f)) 
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

bool  GameBall::isPlayable(void)
{
	return playable;
}

void  GameBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void  GameBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool  GameBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string  GameBall::getOwner(void)
{
	return owner;
}

void  GameBall::setNumber(std::string number)
{
	this->number = number;
}

void  GameBall::render(sf::RenderTarget& target)
{
	// 공 형태 그림 
	target.draw(getVertices());

	// SampleGame에서는 각 공에 플레이어 문자 표시 
	sf::Text ballText;
	ballText.setFont(SampleGame::getFont());
	ballText.setFillColor(sf::Color::Red);
	ballText.setOutlineColor(sf::Color::White);
	ballText.setOutlineThickness(2);
	ballText.setString(number);
	ballText.setCharacterSize(15);
	ballText.setPosition(getPosition() - sf::Vector2f(3, 6));
	target.draw(ballText);
}

void GameBall::moveBall(int ballType) {
	int a = 0;
	if (this->turn == 1) {
		std::cout << "1p" << std::endl;
		if (ballType == 1) {

		}
		else if (ballType == 2) {

		}
		else if (ballType == 3) {

		}
		else if (ballType == 4) {

		}
		else if (ballType == 0) {
			this->turn = 2;
		}
	}
	else if (this->turn = 2) {
		std::cout << "2p" << std::endl;
		if (ballType == 1) {

		}
		else if (ballType == 2) {

		}
		else if (ballType == 3) {

		}
		else if (ballType == 4) {

		}
		else if (ballType == 0) {
			this->turn = 1;
		}
	}
}

bool  GameBall::isPlayerBall( Ball &other)
{
	if (typeid(other) == typeid( GameBall)) {
		return true;
	}
}