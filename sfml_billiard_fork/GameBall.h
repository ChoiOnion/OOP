#pragma once
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Ball.h"
class GameBall : public Ball
{
public: 
	using Ball::Ball;
	bool isIntersecting(sf::Vector2f point);
	bool isPlayable(void);
	void setPlayable(bool playable);
	void setOwner(std::string owner);
	bool isOwner(std::string owner);
	std::string getOwner(void);
	
	// 게임 공에 숫자를 그리기 위해 virtual 함수 재정의 
	// 게임 공에 숫자를 그리기 위해 virtual 함수 재정의 
	void render(sf::RenderTarget& window);

	void setNumber(std::string number);

	bool isPlayerBall(Ball& other);

private:
	bool playable{};
	std::string owner{};
	std::string number{};
	int turn = 1;
};
