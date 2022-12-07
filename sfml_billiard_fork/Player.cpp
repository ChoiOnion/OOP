#include "Player.h"
#include "SampleGame.h"
#include "Ball.h"
#include "BlackBall.h"
#include "SolidBall.h"
#include "StripeBall.h"
#include "GameText.h"

 Player:: Player() {
}
 Player::~ Player() {}
//getter,setter

void  Player::setTurn(bool param) {
	this->turn = param;
}
bool  Player::getTurn() {
	return turn;
}

int Player::checkTurn(int ballType) {
	if (this->breakShot) {
		if (ballType == 1) {
			this->ballType = 1;
			this->remainBall--;
			this->breakShot = false;
			return 3;
		}
		else if (ballType == 2) {
			this->ballType = 2;
			this->remainBall--;
			this->breakShot = false;
			return 3;
		}
		else if (ballType == 3) {
			return 0;
		}
		else if (ballType == 4) {
			return -10;
		}
	}
	if (this->turn&& this->breakShot == false) {
		if (ballType == 1) {
			if (this->myBall == ballType) {
				this->remainBall--;
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (ballType == 2) {
			if (this->myBall == ballType) {
				this->remainBall--;
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (ballType == 3) {

		}
		else if (ballType == 4) {
			if (this->allDone())
				return 10;
			else
				return -10;
		}
		else if (ballType == 0) {

		}
	}
}

bool Player::allDone() {
	if (this->remainBall == 0)
		return true;
	else
		return false;
}