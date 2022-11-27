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

class SampleBilliardPlayer:public SampleBilliardObject
{
public:
	SampleBilliardPlayer();

	//getter,setter
	void setOwner(std::string owner);
	bool isOwner(std::string owner);
	std::string getOwner(void);
	//사용이 불가해서 뺍니다
	/*
	void setBall1p(std::string whatBall);	//아직 들어온 공 판별식이 나오지 않았으니 나오면 추후 변경
	void setBall2p(std::string whatBall);
	static std::string getBall1p();
	static std::string getBall2p();
	*/

	//혹시몰라 만드는 1p와 2p의 턴 getter,setter
	void setTurn1p();
	bool getTurn1p();
	void setTurn2p();
	bool getTurn2p();


	//이거 안되면 판별식 부터 안되는거니깐 연락주세요
	bool is1pStripe();
	bool is2pStripe();
	bool is1pSolide();
	bool is2pSolide();

	//자신이 넣어야 할 공을 다 넣었는지 판별하는 함수
	bool allDone(bool who);

	// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
	virtual void update(float timeElapsed);

	// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
	virtual void collide(SampleBilliardObject& other);

	// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
	virtual void render(sf::RenderTarget& target);

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

	bool breakShot = true;
};
