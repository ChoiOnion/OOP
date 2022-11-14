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

//return 값은 임의로 0(1p의 턴), 1(2p)의 턴 으로 합니다. 추후 브레이크 샷이나 게임이 돌아가는 함수가 완성될 때 맞춰서 변경할 필요가 있을 수도 있습니다.
//switch문은 정수형이거나 열거형 형식이여야 한다고 오류가 떠서 좀 복잡하지만 if else문으로 처리했습니다.
//혹시 해결방법을 아시는 분이 있다면 알려주심 감사합니다...
//비정적 멤버 참조는 특정 개체에 상대적이어야 합니다 오류가 뜨길래 일단 인스턴스를 생성했지만... 잘 안될수도 있습니다.
int SampleBilliardPlayer::ismyturn(std::string ball) {
	SampleBilliardStripeBall *isStripe;
	isStripe->isOwner(ball);
	SampleBilliardSolidBall* isSolide;
	isSolide->isOwner(ball);
	SampleBilliardBlackBall* isBlack;
	isBlack->isOwner(ball);
	SampleBilliardGameBall* isGame;
	isGame->isOwner(ball);
	if (turn1p == true) {
		if (isStripe == 0) {
			if (ball1p == "stripe")
			{
				return 0;
			}
			else if (ball1p == "solide")
			{
				turn1p = false;
				turn2p = true;
				return 1;
			}
		}
		else if (isSolide == 0) {
			if (ball1p == "stripe")
			{
				turn1p = false;
				turn2p = true;
				return 1;
			}
			else if (ball1p == "solide")
			{
				return 0;
			}
		}
		else if (isGame == 0) {
			//패배함수
		}
		else if (isBlack == 0) {			//8번 공이 들어갔을 때
			if (alldone(ball) == true) {	//모든 공이 들어간 후 넣는 공이므로 자동 승리 판정입니다.
				//승리함수
			}
			else {
				//패배함수
			}
		}
		else if (ball == "nothing(=null)") {		//아무것도 안들어왔을때의 처리가 어떻게 될지 그냥 else로 해도 될려나 싶습니다.
			turn1p = false;
			turn2p = true;
			return 1;
		}
	}
	if (turn2p == true) {
		if (isStripe == 0) {
			if (ball2p == "stripe")
			{
				return 1;
			}
			else if (ball2p == "solide")
			{
				turn1p = true;
				turn2p = false;
				return 0;
			}
		}
		else if (isSolide == 0) {
			if (ball2p == "stripe")
			{
				turn1p = true;
				turn2p = false;
				return 0;
			}
			else if (ball2p == "solide")
			{
				return 1;
			}
		}
		else if (isGame == 0) {
			//패배함수
		}
		else if (isBlack == 0) {			//8번 공이 들어갔을 때
			if (alldone(ball) == true) {	//모든 공이 들어간 후 넣는 공이므로 자동 승리 판정입니다.
				//승리함수
			}
			else {
				//패배함수
			}
		}
		else if (ball == "nothing(=null)") {
			turn1p = true;
			turn2p = false;
			return 0;
		}
	}
	return 0;
}

bool SampleBilliardPlayer::alldone(std::string ball) {
	//제가 정말... 생각나는게 하나도 없어서 잠깐 미루겠습니다...
	//되도록이면 큐같은걸로 처리하고 싶은데 되돌아오는 값보고 결정하겠습니다.
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

