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

	//getter,setter
	void setOwner(std::string owner);
	bool isOwner(std::string owner);
	std::string getOwner(void);
	void setBall1p(SampleBilliardBoard& other);	//아직 들어온 공 판별식이 나오지 않았으니 나오면 추후 변경
	void setBall2p(SampleBilliardBoard& other);
	//혹시몰라 만드는 1p와 2p의 턴 getter,setter
	void setturn1p();
	bool getturn1p();
	void setturn2p();
	bool getturn2p();

	// 게임 공에 숫자를 그리기 위해 virtual 함수 재정의 
	void render(sf::RenderTarget& window);

	//플레이어 공격권 표시
	bool isMyTurn(SampleBilliardBoard& other);

	//자신이 넣어야 할 공을 다 넣었는지 판별하는 함수
	bool allDone(bool who);

private:
	std::string owner;

	//각각의 플레이어 턴을 판별하기 위한 변수
	bool turn1p = true;
	bool turn2p = false;
	//서로 어떤 공을 넣어야하는지 판별하는 변수(타입은 임시)
	std::string ball1p;
	std::string ball2p;
	//각각볼이 몇개 남았는지 판별(어차피 둘다 7개니깐 턴에서 넣을때마다 하나씩 빼는걸로 하겠습니다.)
	int remainStripe = 7;
	int remainSolide = 7;
};
