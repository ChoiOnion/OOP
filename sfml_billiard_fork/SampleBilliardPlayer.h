#pragma once

#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "SampleBilliardBall.h"

class SampleBilliardPlayer : public SampleBilliardBall
{
public:
	using SampleBilliardBall::SampleBilliardBall;
	SampleBilliardPlayer();
	SampleBilliardPlayer(sf::Vector2f center);

	void setOwner(std::string owner);
	bool isOwner(std::string owner);
	std::string getOwner(void);

	// 게임 공에 숫자를 그리기 위해 virtual 함수 재정의 
	void render(sf::RenderTarget& window);

	//플레이어 공격권 표시
	int ismyball(std::string ball); // 다른 객체를 어떻게 판별할 것인지 

private:
	std::string owner;

	//각각의 플레이어 턴을 판별하기 위한 변수
	bool turn1p = true;
	bool turn2p = false;
	//서로 어떤 공을 넣어야하는지 판별하는 변수(타입은 임시)
	std::string ball1p;
	std::string ball2p;
};
