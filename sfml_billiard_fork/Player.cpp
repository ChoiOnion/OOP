#include " Player.h"
#include "SampleGame.h"
#include " Ball.h"
#include " BlackBall.h"
#include " SolidBall.h"
#include " StripeBall.h"
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



//한번 지금 판별식 처럼 바꿨습니다(대입x) 안될거 같아서 일단 주석 걸어둘게요.
//부모 클래스 Object로 변경했고, 기존 isMyTurn 함수를 update함수로 옮겨뒀습니다.
//else 부분 수정 필요합니다. 마우스 클릭마다 update함수가 작동하는 게 아니고, 시간을 기준으로
//반응하기 때문에 else로 두면 턴이 계속 넘어가요.
//제가 많이 바꿔둬서 헷갈릴 수도 있는데 혹시 다른 방법 있거나, 다른 방식이 편할 거 같으면
//수정해도 됩니다!.
void  Player::update(float timeElapsed) {

}

void  Player::moveBall( Ball ball){
	int ballDist{};
	std::cout << ball.getGoal();
	if (ball.getGoal()) {
		ballDist = ball.getWhatball();
		std::cout << "  x" << ballDist << "x  ";
	}
	if (ballDist != 0)
		std::cout << "  b" << ballDist << "b  ";
	//그러고 보니 두개 들어오는건 어떻게 해야할지 모르겠네요
	//두 개가 다른 종류면 그때 키보드 이용해서 선택하기로 했었어요!
	if (this->getTurn1p()==true) {
		if (breakShot == true) {
			if (ballDist == 1) {
				this->ball1p = "stripe";
				this->breakShot = false;
			}
			else if (ballDist == 2) {
				this->ball1p = "solide";
				this->breakShot = false;
			}
			else if (ballDist == 3) {
				//다시 공 놓는 함수로(혹은 제작해 두심 읽고 변경하겠습니다)
				setTurn2p();
			}
			else if (ballDist == 4) {
				//패배함수
			}
			else {
				//setTurn2p();
			}
		}
		else {
			if (ballDist == 1) {
				if (ball1p == "stripe")
				{
					this->remainStripe -= 1;
				}
				else if (ball1p == "solide")
				{
					setTurn2p();
					this->remainSolide -= 1;
				}
			}
			else if (ballDist == 2) {
				if (ball1p == "stripe")
				{
					setTurn2p();
					this->remainStripe -= 1;
				}
				else if (ball1p == "solide")
				{
					this->remainSolide -= 1;
				}
			}
			else if (ballDist == 3) {
				//공 불러오기? 일단 턴을 바꾼다.
				//turn2p = true;
				//turn1p = false;
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
				//setTurn2p();
			}
		}
	}
	else if (this->getTurn2p()==true) {
		if (breakShot == true) {
			if (ballDist == 1) {
				this->ball2p = "stripe";
				this->breakShot = false;
			}
			else if (ballDist == 2) {
				this->ball2p = "solide";
				this->breakShot = false;
			}
			else if (ballDist == 3) {
				setTurn1p();
			}
			else if (ballDist == 4) {

			}
			else {
				//setTurn1p();
			}
		}
		else {
			if (ballDist == 1) {
				if (ball2p == "stripe")
				{
					this->remainStripe -= 1;
				}
				else if (ball2p == "solide")
				{
					setTurn1p();
					this->remainSolide -= 1;
				}
			}
			else if (ballDist == 2) {
				if (ball2p == "solide")
				{
					setTurn1p();
					this->remainStripe -= 1;
				}
				else if (ball2p == "stripe")
				{
					this->remainSolide -= 1;
				}
			}
			else if (ballDist == 3) {
				//공 불러오기? 일단 턴을 바꾼다.
				setTurn1p();
			}
			else if (ballDist == 4) {			//8번 공이 들어갔을 때
				if (allDone(turn1p) == true) {	//모든 공이 들어간 후 넣는 공이므로 자동 승리 판정입니다.
					//승리함수
				}
				else {
					//패배함수
				}
			}
			else {						//아무것도 들어오지 않았을때
				//setTurn1p();
			}
		}
	}
	else {
		//상대에게 턴 넘김
	}
}

bool  Player::allDone(bool who) {
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
}

void  Player::collide( Object& other) {

}

void  Player::render(sf::RenderTarget& target) {

}
