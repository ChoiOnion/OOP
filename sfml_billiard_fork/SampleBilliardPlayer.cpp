#include "SampleBilliardPlayer.h"
#include "SampleGame.h"
#include "SampleBilliardBall.h"
#include "SampleBilliardBlackBall.h"
#include "SampleBilliardSolidBall.h"
#include "SampleBilliardStripeBall.h"
#include "GameText.h"

//getter,setter
void SampleBilliardPlayer::setOwner(std::string owner) {
	this->owner = owner;
};
bool SampleBilliardPlayer::isOwner(std::string owner) {
	return owner.compare(this->owner) == 0;
};
std::string SampleBilliardPlayer::getOwner(void) {
	return owner;
};

void SampleBilliardPlayer::setBall1p(std::string whatBall) {
	this->ball1p = whatBall;
}
void SampleBilliardPlayer::setBall2p(std::string whatBall) {
	this->ball2p = whatBall;
}
std::string SampleBilliardPlayer::getBall1p() {
	return ball1p;
}
std::string SampleBilliardPlayer::getBall2p() {
	return ball2p;
}

//이건 혹시 몰라서 만든 1p와 2p 턴 세팅 함수입니다. 아무것도 안들어갔을때 쓰기 좋을거 같아요
//보니깐 만든 판별식이 홀에 들어갔을때를 전제로 하는거 같아서 만들었어요.
void SampleBilliardPlayer::setturn1p() {
	this->turn1p = true;
	this->turn2p = false;
};
bool SampleBilliardPlayer::getturn1p() {
	return turn1p;
};
void SampleBilliardPlayer::setturn2p() {
	this -> turn2p = true;
	this->turn1p = false;
};
bool SampleBilliardPlayer::getturn2p() {
	return turn2p;
};


//return 값은 임의로 0(1p의 턴), 1(2p)의 턴 으로 합니다. 추후 브레이크 샷이나 게임이 돌아가는 함수가 완성될 때 맞춰서 변경할 필요가 있을 수도 있습니다.
//bool로 변경했습니다.
//무슨 공인지 판별식 완성되면 이것도 setball1p..등등과 함께 바꾸겠습니다.
//한번 지금 판별식 처럼 바꿨습니다(대입x) 안될거 같아서 일단 주석 걸어둘게요.

bool SampleBilliardPlayer:: isMyTurn() {
	int breakshot = 0;
	int ballDist = SampleBilliardBall::getWhatball();
	//그러고 보니 두개 들어오는건 어떻게 해야할지 모르겠네요
	if (turn1p == true) {
		if (breakShot == true) {
			if (ballDist == 1) {
				this->ball1p = "stripe";
				return 0;
				this->breakShot = false;
			}
			else if (ballDist == 2) {
				this->ball1p = "solide";
				return 0;
				this->breakShot = false;
			}
			else if (ballDist == 3) {
				//다시 공 놓는 함수로(혹은 제작해 두심 읽고 변경하겠습니다)
				turn2p = true;
				turn1p = false;
				return 1;
			}
			else if (ballDist == 4) {
				//패배함수
			}
			else {
				turn2p = true;
				turn1p = false;
				return 1;
			}
		}
		else {
			if (ballDist == 1) {
				if (ball1p == "stripe")
				{
					this->remainStripe -= 1;
					return 0;
				}
				else if (ball1p == "solide")
				{
					this->turn1p = false;
					this->turn2p = true;
					this->remainSolide -= 1;
					return 1;
				}
			}
			else if (ballDist == 2) {
				if (ball1p == "stripe")
				{
					this->turn1p = false;
					this->turn2p = true;
					this->remainStripe -= 1;
					return 1;
				}
				else if (ball1p == "solide")
				{
					this->remainSolide -= 1;
					return 0;
				}
			}
			else if (ballDist == 3) {
				//공 불러오기? 일단 턴을 바꾼다.
				turn2p = true;
				turn1p = false;
				return 1;
			}
			else if (ballDist == 4) {			//8번 공이 들어갔을 때
				if (allDone(turn1p) == true) {	//모든 공이 들어간 후 넣는 공이므로 자동 승리 판정입니다.
					//승리함수
				}
				else {
					//패배함수
				}
			}
			else {							//아무것도 들어오지 않았을때
				this->turn1p = false;
				this->turn2p = true;
				return 1;
			}
		}
	}
	else if (turn2p == true) {

		if (breakShot == true) {
			if (ballDist == 1) {
				this->ball2p = "stripe";
				return 1;
				this->breakShot = false;
			}
			else if (ballDist == 2) {
				this->ball2p = "solide";
				return 1;
				this->breakShot = false;
			}
			else if (ballDist == 3) {
				turn1p = true;
				turn2p = false;
				return 0;
			}
			else if (ballDist == 4) {

			}
			else {
				turn1p = true;
				turn2p = false;
				return 0;
			}
		}
		else {
			if (ballDist == 1) {
				if (ball2p == "stripe")
				{
					this->remainStripe -= 1;
					return 1;
				}
				else if (ball2p == "solide")
				{
					this->turn2p = false;
					this->turn1p = true;
					this->remainSolide -= 1;
					return 0;
				}
			}
			else if (ballDist == 2) {
				if (ball2p == "solide")
				{
					this->turn2p = false;
					this->turn1p = true;
					this->remainStripe -= 1;
					return 0;
				}
				else if (ball2p == "stripe")
				{
					this->remainSolide -= 1;
					return 1;
				}
			}
			else if (ballDist == 3) {
				//공 불러오기? 일단 턴을 바꾼다.
				turn1p = true;
				turn2p = false;
				return 0;
			}
			else if (ballDist == 4) {			//8번 공이 들어갔을 때
				if (allDone(turn1p) == true) {	//모든 공이 들어간 후 넣는 공이므로 자동 승리 판정입니다.
					//승리함수
				}
				else {
					//패배함수
				}
			}
			else {							//아무것도 들어오지 않았을때
				this->turn2p = false;
				this->turn1p = true;
				return 1;
			}
		}
	}
	else {
		//상대에게 턴 넘김
	}
}

bool SampleBilliardPlayer::allDone(bool who) {
	if (turn1p == true) {
		if (ball1p=="stripe")
		{
			if (remainStripe==0) {	// 다 넣었을 때 0이 된다
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (remainSolide==0) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else if (turn2p == true) {
		if (ball2p == "stripe")
		{
			if (remainStripe == 0) {	// 다 넣었을 때 0이 된다
				return true;
			}
			else {
				return false;
			}
		}
		else {
			if (remainSolide == 0) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};



//1p,2p를 표기하기 위한 렌더함수
void SampleBilliardPlayer::render(sf::RenderTarget& target) {
	sf::Text PlayerText;
	PlayerText.setFont(SampleGame::getFont());
	PlayerText.setFillColor(sf::Color::Black);
	PlayerText.setString(owner[0]);
	PlayerText.setCharacterSize(18);
	PlayerText.setPosition(getPosition() - sf::Vector2f(5, 12));
	target.draw(PlayerText);
};

