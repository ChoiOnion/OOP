#include "SampleBilliardPlayer.h"
#include "SampleGame.h"
#include "SampleBilliardBall.h"

//생성자
SampleBilliardPlayer::SampleBilliardPlayer() {

}; //기본 생성자
SampleBilliardPlayer::SampleBilliardPlayer(sf::Vector2f center) {

}; //복사 생성자, 받을 것들 생각해두기.


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
#include "SampleBilliardPlayer.h"
#include "SampleGame.h"
#include "SampleBilliardBall.h"
#include "GameText.h"

int SampleBilliardPlayer::ismyball(std::string ball) {				//스트라이프=1, 솔리드=0, 8번볼=8로 수정해뒀습니다 (빌드 오류 방지)
	if (turn1p == true) {
		if (1) {
			if (1)		// soild,stripe... 등등에게서 get number 함수라던가,,, 구분 할 수있는 변수를 가져올 수 있도록 할 수 있는지 묻기
			{
				int a;
			}
			else if (0)
			{
				int a;
			}
			else if (8)		//그리고 넣은 볼을 어떻게 관리할지 고민해보기
			{
				//패배함수
			}
		}
		else if (0) {
			if (1)
			{
				int a; // 오류 방지용
			}
			else if (0)
			{
				int a;
			}
			else if (8)
				int a;
		}
	}
	else if (turn2p == true) {
	}
	return 0;
}
