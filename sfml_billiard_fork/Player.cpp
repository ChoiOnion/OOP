#include "Player.h"
#include "SampleGame.h"
#include "Ball.h"
#include "BlackBall.h"
#include "SolidBall.h"
#include "StripeBall.h"
#include "GameText.h"

 Player:: Player(bool turn) {
	 this->turn = turn;
}
 Player::~ Player() {}
//getter,setter

void  Player::setTurn(bool param) {
	this->turn = param;
}
bool  Player::getTurn() {
	return turn;
}



void Player::setType(int a) {
	this->ballType = a;
};

int Player::getType() {
	return ballType;
};

/*
즉시 패배는 - 10 반환, 승리는 10 반환
턴이 넘어가면 0 반환
턴 유지 시 1 반환
*/
int Player::checkTurn(int ballType) {

	if (this->turn) {
		if (ballType == 1) {
			if (this->myBall == ballType) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (ballType == 2) {
			if (this->myBall == ballType) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (ballType == 3) {
			return 0;
		}
	}
	return 0;
}