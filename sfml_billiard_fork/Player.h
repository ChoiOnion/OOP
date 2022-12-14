#pragma once

#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class  Player
{
public:
	 Player(bool turn);
	~ Player();

	void setTurn(bool param);
	bool getTurn();

	void setType(int a);
	int getType();

	void setRBall();
	int getRBall();

	int checkTurn(int ballType);

private:
	//플레이어 턴을 판별하기 위한 변수
	bool turn = true;
	//서로 어떤 공을 넣어야하는지 판별하는 변수
	int ballType{};

	int remainBall=7;
};
