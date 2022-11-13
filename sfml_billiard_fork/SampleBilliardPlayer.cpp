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
 
int SampleBilliardPlayer::ismyturn(std::string ball) {
	if (ball=="stripe") {
		
	}
	else if (ball=="solide") {

	}
	else if (ball == "player") {

	}
	else if (ball == "black") {			//8번 공이 들어갔을 때
		if (alldone(ball) == true) {	//모든 공이 들어간 후 넣는 공이므로 자동 승리 판정입니다.
			//승리함수
		}
		else {
			//패배함수
		}
	}
	return 0;
}

bool SampleBilliardPlayer::alldone(std::string ball) {
	//제가 정말... 생각나는게 하나도 없어서 잠깐 미루겠습니다...
	return false;
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

