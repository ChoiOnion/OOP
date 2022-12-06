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

void  Player::update(float timeElapsed) {

}

void  Player::collide( Object& other) {

}

void  Player::render(sf::RenderTarget& target) {

}

void Player::checkTurn(int ballType) {
	if (this->turn) {

	}
}

bool Player::allDone() {
	if (this->remainBall == 0)
		return true;
	else
		return false;
}