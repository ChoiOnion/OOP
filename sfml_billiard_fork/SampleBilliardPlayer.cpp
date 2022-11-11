#include "SampleBilliardPlayer.h"
#include "SampleGame.h"
#include "SampleBilliardBall.h"
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

int SampleBilliardPlayer::ismyball(std::string ball) {
	if (turn1p == true) {
		if (ball1p == "스트라이프") {
			if (ball == "스트라이프")		// soild,stripe... 등등에게서 get number 함수라던가,,, 구분 할 수있는 변수를 가져올 수 있도록 할 수 있는지 묻기
			{

			}
			else if (ball == "솔리드")
			{

			}
			else if (ball == "블랙볼(8)")		//그리고 넣은 볼을 어떻게 관리할지 고민해보기
			{
				//패배함수
			}
		}
		else if (ball1p == "솔리드") {
			if (ball == "스트라이프")
			{

			}
			else if (ball == "솔리드")
			{

			}
			else if (ball == "블랙볼(8)")

			}
		}
	}
	else if(turn2p==true) {

	}
	return 0;
}


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

