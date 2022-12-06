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
#include "Object.h"

class  Player:public Object
{
public:
	 Player();
	~ Player();

	void setTurn(bool param);
	bool getTurn();

	//자신이 넣어야 할 공을 다 넣었는지 판별하는 함수
	bool allDone();

	// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
	virtual void update(float timeElapsed);

	// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
	virtual void collide(Object& other);

	// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
	virtual void render(sf::RenderTarget& target);

	void checkTurn(int ballType);

private:
	//각각의 플레이어 턴을 판별하기 위한 변수
	bool turn = true;
	//서로 어떤 공을 넣어야하는지 판별하는 변수(타입은 임시)
	std::string ballType;
	//각각볼이 몇개 남았는지 판별(어차피 둘다 7개니깐 턴에서 넣을때마다 하나씩 빼는걸로 하겠습니다.)
	int remainBall = 7;

	bool breakShot = true;
};
