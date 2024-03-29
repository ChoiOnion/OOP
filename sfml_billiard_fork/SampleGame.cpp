#include "SampleGame.h"
#include "Board.h"
#include "GameBall.h"
#include "SolidBall.h"
#include "BlackBall.h"
#include "StripeBall.h"
#include "Object.h"
#include "GameText.h"
#include "LoadImage.h"
#include "Player.h"
#include "Hole.h"

// 123112
SampleGame::SampleGame(int width, int height, int fpsLimit)
	:BaseGame(width, height, fpsLimit), isDraggingBall(false), draggedBall(nullptr)
{
	// SampleGame을 위한 인터페이스 생성 및 등록 
	GameText* playerText1 = new GameText("Player1", 50, 610, 20, sf::Color::White, 3);
	GameText* playerText2 = new GameText("Player2", 50, 810, 20, sf::Color::White, 3);
	gameObjects.push_back(playerText1);
	gameObjects.push_back(playerText2);

	LoadImage* player1img = new LoadImage("player.png", 250, 250, 40, 650);
	LoadImage* player2img = new LoadImage("player.png", 250, 250, 40, 850);
	gameObjects.push_back(player1img);
	gameObjects.push_back(player2img);

	GameText* myTurn = new GameText("My Turn!", 150, 610, 50, sf::Color::Yellow, 8);
	turn.push_back(myTurn);

	GameText* help = new GameText("Press H : help", 20, 20, 30, sf::Color::White, 3);
	gameObjects.push_back(help);

	// 공 들어갈 자리 표시
	LoadImage* ballPosition1 = new LoadImage("ballposition.png", 250, 250, 120, 670);
	gameObjects.push_back(ballPosition1);

	LoadImage* ballPosition2 = new LoadImage("ballposition.png", 250, 250, 120, 870);
	gameObjects.push_back(ballPosition2);

	//승패판정그림

	// SampleGame을 위한 당구대 생성 및 등록 
	gameObjects.push_back(new  Board());
	gameObjects.push_back(new  Hole());

	// SampleGame을 위한 당구공 생성 및 등록 
	 GameBall* playerBall = new  GameBall(sf::Vector2f(800, 680), 10, sf::Color::White);
	 SolidBall* ball1 = new  SolidBall(sf::Vector2f(800, 300), 10, sf::Color::Yellow);
	 SolidBall* ball2 = new  SolidBall(sf::Vector2f(785, 280), 10, sf::Color::Blue);
	 SolidBall* ball3 = new  SolidBall(sf::Vector2f(815, 280), 10, sf::Color::Red);
	 SolidBall* ball4 = new  SolidBall(sf::Vector2f(770, 260), 10, sf::Color::Magenta);
	 SolidBall* ball5 = new  SolidBall(sf::Vector2f(800, 260), 10, sf::Color::Cyan);
	 SolidBall* ball6 = new  SolidBall(sf::Vector2f(830, 260), 10, sf::Color::Green);
	 SolidBall* ball7 = new  SolidBall(sf::Vector2f(755, 240), 10, sf::Color::White);
	 BlackBall* ball8 = new  BlackBall(sf::Vector2f(785, 240), 10, sf::Color::Black);
	 StripeBall* ball9 = new  StripeBall(sf::Vector2f(815, 240), 10, sf::Color::Yellow);
	 StripeBall* ball10 = new  StripeBall(sf::Vector2f(845, 240), 10, sf::Color::Blue);
	 StripeBall* ball11 = new  StripeBall(sf::Vector2f(740, 220), 10, sf::Color::Red);
	 StripeBall* ball12 = new  StripeBall(sf::Vector2f(770, 220), 10, sf::Color::Magenta);
	 StripeBall* ball13 = new  StripeBall(sf::Vector2f(800, 220), 10, sf::Color::Cyan);
	 StripeBall* ball14 = new  StripeBall(sf::Vector2f(830, 220), 10, sf::Color::Green);
	 StripeBall* ball15 = new  StripeBall(sf::Vector2f(860, 220), 10, sf::Color::White);
	
	playerBall->setNumber("*");
	ball1->setNumber("1");
	ball2->setNumber("2");
	ball3->setNumber("3");
	ball4->setNumber("4");
	ball5->setNumber("5");
	ball6->setNumber("6");
	ball7->setNumber("7");
	ball8->setNumber("8");
	ball9->setNumber("9");
	ball10->setNumber("10");
	ball11->setNumber("11");
	ball12->setNumber("12");
	ball13->setNumber("13");
	ball14->setNumber("14");
	ball15->setNumber("15");

	playerBall->setPlayable(true);
	ball1->setPlayable(false);
	ball2->setPlayable(false);
	ball3->setPlayable(false);
	ball4->setPlayable(false);
	ball5->setPlayable(false);
	ball6->setPlayable(false);
	ball7->setPlayable(false);
	ball8->setPlayable(false);
	ball9->setPlayable(false);
	ball10->setPlayable(false);
	ball11->setPlayable(false);
	ball12->setPlayable(false);
	ball13->setPlayable(false);
	ball14->setPlayable(false);
	ball15->setPlayable(false);

	balls.push_back(playerBall);
	balls.push_back(ball1);
	balls.push_back(ball2);
	balls.push_back(ball3);
	balls.push_back(ball4);
	balls.push_back(ball5);
	balls.push_back(ball6);
	balls.push_back(ball7);
	balls.push_back(ball8);
	balls.push_back(ball9);
	balls.push_back(ball10);
	balls.push_back(ball11);
	balls.push_back(ball12);
	balls.push_back(ball13);
	balls.push_back(ball14);
	balls.push_back(ball15);
}

SampleGame::~SampleGame(void)
{
	// UI 인스턴스 해제  

	// 게임 오브젝트들 해제 
	for ( Object* obj : gameObjects)
	{
		delete obj;
	}

	for (Ball* b : balls) {
		delete b;
	}

	for (GameText* txt : turn) {
		delete txt;
	}

	for (LoadImage* img : images) {
		delete img;
	}
}

sf::Font* SampleGame::font = nullptr;
const sf::Font& SampleGame::getFont(void)
{
	if (font == nullptr) {
		font = new sf::Font;
		font->loadFromFile("Arial.ttf");
	}
	return *font;
}

// 상속 클래스는 반드시 이벤트 핸들링 함수 구현해야 함 
void SampleGame::handle(sf::Event& ev)
{
	// SampleGame을 위한 입력 이벤트 처리 
	switch (ev.type)
	{
	case sf::Event::Closed:
		// 윈도우의 x 버튼 누르면 종료한다 
		window->close();
		break;
	case sf::Event::KeyPressed:
		// 키보드 이벤트                                            
		if (ev.key.code == sf::Keyboard::Escape && pauseNum == 0)							//같은 키로 하면 안먹음!! 키 따로 설정해야 될 거 같아요
		{
			images.push_back(new LoadImage("pause.png", 800, 250, 125, 400));
			pauseNum = 1;
			break;
		}
		if (ev.key.code == sf::Keyboard::Escape && pauseNum == 1)
		{
			images.pop_back();
			pauseNum = 0;
			break;
		}
		if (ev.key.code == sf::Keyboard::H && helpNum == 0)
		{
			images.push_back(new LoadImage("rule.png", 800, 850, 125, 100));
			helpNum = 1;
			break;
		}
		if (ev.key.code == sf::Keyboard::H && helpNum == 1)
		{
			images.pop_back();
			helpNum = 0;
			break;
		}
		if (ev.key.code == sf::Keyboard::E && endNum == 1) {
			window->close();
			break;
		}
		break;
	case sf::Event::MouseMoved:
		// 마우스 움직임 이벤트 
		mouseXY.x = (float)ev.mouseMove.x;
		mouseXY.y = (float)ev.mouseMove.y;
		break;
	case sf::Event::MouseButtonPressed:
		// 마우스 버튼 누름 이벤트 
		if (ev.mouseButton.button == sf::Mouse::Left)
		{
			for ( Ball* b : balls)
			{
				if (b != nullptr) {
					if (b->getGoal()&&b->check==0) {
						if (breakShot == true) {
							//브레이크 샷
							if (player1->getTurn() == true) {
								if (b->getWhatball() == 1) {
									player1->setType(1);
									player2->setType(2);
									b->setPosition(163, 720);
									player1->setRBall();
									this->breakShot = false;
								}
								else if (b->getWhatball() == 2) {
									player1->setType(2);
									player2->setType(1);
									b->setPosition(163, 720);
									player1->setRBall();
									this->breakShot = false;
								}
								else if (b->getWhatball() == 4) { //8번 공
									images.push_back(new LoadImage("end2.png", 800, 250, 125, 400));
									endNum = 1;
								}
							}
							else if (player2->getTurn() == true) {
								if (b->getWhatball() == 1) {
									player2->setType(1);
									player1->setType(2);
									b->setPosition(163, 920);
									player2->setRBall();
									this->breakShot = false;
								}
								else if (b->getWhatball() == 2) {
									player2->setType(2);
									player1->setType(1);
									b->setPosition(163, 920);
									player2->setRBall();
									this->breakShot = false;
								}
								else if (b->getWhatball() == 4) { //8번 공
									images.push_back(new LoadImage("end1.png", 800, 250, 125, 400));
									endNum = 1;
								}
							}
						}
						else if(breakShot==false){
							int x = 7 - player1->getRBall();
							int y = 7 - player2->getRBall();
							if (player1->checkTurn(b->getWhatball()) == 1) {
								player1->setTurn(true);
								player2->setTurn(false);
								if (b->getWhatball() != 3 && b->getWhatball() != 4) { //플레이어 볼이 아닐시 player 1의 공이 맞음
									if (b->getWhatball() == player1->getType()) {
										b->setPosition(163 + 31 * x, 720);
										player1->setRBall();
									}
									else if (b->getWhatball() == player2->getType()) {
										b->setPosition(163 + 31 * y, 920);
										player2->setRBall();
									}
								}
							}
							else if (player1->checkTurn(b->getWhatball()) == 0) {
								player1->setTurn(false);
								player2->setTurn(true);
								if (b->getWhatball() != 3 && b->getWhatball() != 4) { //플레이어 볼이 아닐시 player 2의 공이 맞음
									if (b->getWhatball() == player2->getType()) {
										b->setPosition(163 + 31 * y, 920);
										player2->setRBall();
									}
									else if (b->getWhatball() == player1->getType()) {
										b->setPosition(163 + 31 * x, 720);
										player1->setRBall();
									}
								}
							}
							else if (b->getWhatball() == 4) {
								if (player2->checkTurn(b->getWhatball()) == (-10) || player1->checkTurn(b->getWhatball()) == 10) {
									images.push_back(new LoadImage("end1.png", 800, 250, 125, 400));
									endNum = 1;
								}
								else if (player1->checkTurn(b->getWhatball()) == (-10) || player2->checkTurn(b->getWhatball()) == 10) {
									images.push_back(new LoadImage("end2.png", 800, 250, 125, 400));
									endNum = 1;
								}
							}
						}
						b->check++;
						continue;
					}
				}
				 GameBall* gameBall = dynamic_cast< GameBall*>(b);
				if (gameBall == nullptr)
				{
					continue;
				}
				// 커서가 공의 내부가 아닌 경우 pass 
				if (!gameBall->isIntersecting(mouseXY))
				{
					continue;
				}
				// 공이 Playable이 아닌 경우 pass 
				if (!gameBall->isPlayable()) {
					continue;
				}

				//드래그 할 때마다 턴이 바뀌어야 함

				if (player1->getTurn()) {
					player1->setTurn(false);
					player2->setTurn(true);
				}
				else {
					player1->setTurn(true);
					player2->setTurn(false);
				}
				// 드래그 가능한 공 임시 저장 
				draggedBall = gameBall;
				isDraggingBall = true;


				std::cout << "\n\n1p :" << player1->getRBall();
				std::cout << "\n2p :" << player2->getRBall();
				std::cout << "\ntype 1p :" << player1->getType();
				std::cout << "\ntype 2p :" << player2->getType();
				std::cout << "\nbreakShot : " << std::boolalpha << breakShot;
				std::cout << "\nturn 1p :" << player1->getTurn();
				std::cout << "\nturn 2p :" << player2->getTurn();
			}
		}
		break;


	case sf::Event::MouseButtonReleased:
		// 마우스 버튼 뗌 이벤트 
		if (ev.mouseButton.button == sf::Mouse::Left && isDraggingBall)
		{
			isDraggingBall = false;
		}
		if (endNum == 0) {
			if (player1->getTurn()) {
				for (GameText* t : turn) {
					t->setPosition(150, 610);
				}
			}
			if (player2->getTurn()) {
				for (GameText* t : turn) {
					t->setPosition(150, 810);
				}
			}
			break;
		}
	}
}

// 상속 클래스는 반드시 게임 상태 갱신 함수 구현해야 함 
void SampleGame::update(void)
{
	// 게임 오브젝트 업데이트 
	for ( Object* obj : gameObjects)
	{
		obj->update(clock.getElapsedTime().asSeconds());
	}
	for (GameText* txt : turn) {
		txt->update(clock.getElapsedTime().asSeconds());
	}

	for (LoadImage* img : images) {
		img->update(clock.getElapsedTime().asSeconds());
	}

	// 게임 오브젝트 충돌 검사
	for ( Ball* obj1 : balls)
	{
		for ( Object* obj2 : gameObjects)
		{
			obj1->collide(*obj2);
		}
	}

	for (Ball* b : balls) {
		for (Ball* b2 : balls) {
			b->collide(*b2);
		}
	}

	for (Ball* b : balls) {
		b->update(clock.getElapsedTime().asSeconds());
	}
	
	// 끌었다가 놓은 공에 속도를 지정하고 표시 해제 
	if (!isDraggingBall && draggedBall != nullptr)
	{
		draggedBall->setVelocity(draggedBall->getPosition().x - mouseXY.x, draggedBall->getPosition().y - mouseXY.y);
		draggedBall = nullptr;
	}

	// 다음 단위 시간을 위해 초기화 
	clock.restart();

}

// 상속 클래스는 반드시 객체 렌더링 함수 구현해야 함 
void SampleGame::render(sf::RenderTarget& target)
{
	// 화면 클리어 
	window->clear(sf::Color(75, 103, 163));

	// 게임 오브젝트 렌더링 
	for ( Object* obj : gameObjects)
	{
		obj->render(target);
	}

	for (Ball* b : balls) {
		b->render(target);
	}


	// 공을 드래그 하면 세기 표시 (길이 및 색)
	renderDragpower(target);

	// 게임 UI 렌더링 
	for (GameText* txt : turn) {
		txt->render(target);
	}


	for (LoadImage* img : images) {
		img->render(target);
	}
	
}

void SampleGame::renderDragpower(sf::RenderTarget& target)
{
	if (isDraggingBall)
	{
		sf::Vector2f distance = (mouseXY - draggedBall->getPosition());
		float distanceBetween = sqrt(distance.x * distance.x + distance.y * distance.y);
		sf::Vector2f invert = distance / distanceBetween;
		sf::Color directionColor = sf::Color(255, (255 - ((int)distanceBetween / 2) % 255), 0);
		if (distanceBetween > 510)
		{
			directionColor = sf::Color::Red;
		}

		sf::Vector2f toSubtract(distanceBetween * invert.x, distanceBetween * invert.y);
		sf::Vertex start = sf::Vertex(draggedBall->getPosition(), directionColor);
		sf::Vertex end = sf::Vertex(draggedBall->getPosition() - toSubtract, directionColor);

		sf::VertexArray points; 
		points.setPrimitiveType(sf::LineStrip);
		points.append(start);
		points.append(end);

		target.draw(points);
	}
}


