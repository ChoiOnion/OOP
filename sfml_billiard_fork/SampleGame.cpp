#include "SampleGame.h"
#include "SampleBilliardBoard.h"
#include "SampleBilliardGameBall.h"
#include "SampleBilliardSolidBall.h"
#include "SampleBilliardBlackBall.h"
#include "SampleBilliardStripeBall.h"
#include "SampleBilliardObject.h"
#include "GameText.h"
#include "LoadImage.h"

// 123112
SampleGame::SampleGame(int width, int height, int fpsLimit)
	:BaseGame(width, height, fpsLimit), isDraggingBall(false), draggedBall(nullptr)
{
	// SampleGame을 위한 인터페이스 생성 및 등록 
	GameText* playerText1 = new GameText("Player1", 50, 600, 50, sf::Color::White, 3);
	GameText* playerText2 = new GameText("Player2", 50, 800, 50, sf::Color::White, 3);
	gameObjects.push_back(playerText1);
	gameObjects.push_back(playerText2);


	LoadImage* player1 = new LoadImage("player.png", 250, 250, 40, 650);
	LoadImage* player2 = new LoadImage("player.png", 250, 250, 40, 850);
	gameObjects.push_back(player1);
	gameObjects.push_back(player2);

	GameText* help = new GameText("Press H : help", 40, 40, 40, sf::Color::White, 3);

	gameObjects.push_back(help);

	// SampleGame을 위한 당구대 생성 및 등록 
	gameObjects.push_back(new SampleBilliardBoard());

	// SampleGame을 위한 당구공 생성 및 등록 
	SampleBilliardGameBall* playerBall = new SampleBilliardGameBall(sf::Vector2f(800, 680), 10, sf::Color::White);
	SampleBilliardSolidBall* ball1 = new SampleBilliardSolidBall(sf::Vector2f(800, 300), 10, sf::Color::Yellow);
	SampleBilliardSolidBall* ball2 = new SampleBilliardSolidBall(sf::Vector2f(785, 280), 10, sf::Color::Blue);
	SampleBilliardSolidBall* ball3 = new SampleBilliardSolidBall(sf::Vector2f(815, 280), 10, sf::Color::Red);
	SampleBilliardSolidBall* ball4 = new SampleBilliardSolidBall(sf::Vector2f(770, 260), 10, sf::Color::Magenta);
	SampleBilliardSolidBall* ball5 = new SampleBilliardSolidBall(sf::Vector2f(800, 260), 10, sf::Color::Cyan);
	SampleBilliardSolidBall* ball6 = new SampleBilliardSolidBall(sf::Vector2f(830, 260), 10, sf::Color::Green);
	SampleBilliardSolidBall* ball7 = new SampleBilliardSolidBall(sf::Vector2f(755, 240), 10, sf::Color::White);
	SampleBilliardBlackBall* ball8 = new SampleBilliardBlackBall(sf::Vector2f(785, 240), 10, sf::Color::Black);
	SampleBilliardStripeBall* ball9 = new SampleBilliardStripeBall(sf::Vector2f(815, 240), 10, sf::Color::Yellow);
	SampleBilliardStripeBall* ball10 = new SampleBilliardStripeBall(sf::Vector2f(845, 240), 10, sf::Color::Blue);
	SampleBilliardStripeBall* ball11 = new SampleBilliardStripeBall(sf::Vector2f(740, 220), 10, sf::Color::Red);
	SampleBilliardStripeBall* ball12 = new SampleBilliardStripeBall(sf::Vector2f(770, 220), 10, sf::Color::Magenta);
	SampleBilliardStripeBall* ball13 = new SampleBilliardStripeBall(sf::Vector2f(800, 220), 10, sf::Color::Cyan);
	SampleBilliardStripeBall* ball14 = new SampleBilliardStripeBall(sf::Vector2f(830, 220), 10, sf::Color::Green);
	SampleBilliardStripeBall* ball15 = new SampleBilliardStripeBall(sf::Vector2f(860, 220), 10, sf::Color::White);
	
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

	gameObjects.push_back(playerBall);
	gameObjects.push_back(ball1);
	gameObjects.push_back(ball2);
	gameObjects.push_back(ball3);
	gameObjects.push_back(ball4);
	gameObjects.push_back(ball5);
	gameObjects.push_back(ball6);
	gameObjects.push_back(ball7);
	gameObjects.push_back(ball8);
	gameObjects.push_back(ball9);
	gameObjects.push_back(ball10);
	gameObjects.push_back(ball11);
	gameObjects.push_back(ball12);
	gameObjects.push_back(ball13);
	gameObjects.push_back(ball14);
	gameObjects.push_back(ball15);

}

SampleGame::~SampleGame(void)
{
	// UI 인스턴스 해제  

	// 게임 오브젝트들 해제 
	for (SampleBilliardObject* obj : gameObjects)
	{
		delete obj;
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
			// TODO: game paused 
			gameObjects.push_back(new LoadImage("pause.png", 800, 250, 125, 400));
			pauseNum = 1;
			//플레이어 볼 false 설정
			// TODO: call sample GUI 
		}
		if (ev.key.code == sf::Keyboard::P && pauseNum == 1)
		{
			gameObjects.pop_back();
			pauseNum = 0;
		}
		if (ev.key.code == sf::Keyboard::H && helpNum == 0)
		{
			gameObjects.push_back(new LoadImage("rule.png", 800, 850, 125, 50));
			helpNum = 1;
		}
		if (ev.key.code == sf::Keyboard::C && helpNum == 1)
		{
			gameObjects.pop_back();
			helpNum = 0;
		}
		if (ev.key.code == sf::Keyboard::E && endNum == 1) {
			window->close();
			break;
		}
		if (ev.key.code == sf::Keyboard::R && endNum == 1) {
			//다시 시작
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
			for (SampleBilliardObject* obj : gameObjects)
			{
				// SampleBilliardBall의 인스턴스가 아닌 경우 pass
				SampleBilliardGameBall* gameBall = dynamic_cast<SampleBilliardGameBall*>(obj);
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



				// 드래그 가능한 공 임시 저장 
				draggedBall = gameBall;
				isDraggingBall = true;
			}
		}
		break;

	case sf::Event::MouseButtonReleased:
		// 마우스 버튼 뗌 이벤트 
		if (ev.mouseButton.button == sf::Mouse::Left && isDraggingBall)
		{
			isDraggingBall = false;
		}
		break;
	}
}

// 상속 클래스는 반드시 게임 상태 갱신 함수 구현해야 함 
void SampleGame::update(void)
{
	// 게임 오브젝트 업데이트 
	for (SampleBilliardObject* obj : gameObjects)
	{
		obj->update(clock.getElapsedTime().asSeconds());
	}

	// 게임 오브젝트 충돌 검사
	for (SampleBilliardObject* obj1 : gameObjects)
	{
		for (SampleBilliardObject* obj2 : gameObjects)
		{
			obj1->collide(*obj2);
		}
	}

	
	// 끌었다가 놓은 공에 속도를 지정하고 표시 해제 
	if (!isDraggingBall && draggedBall != nullptr)
	{
		draggedBall->setVelocity(draggedBall->getPosition().x - mouseXY.x, draggedBall->getPosition().y - mouseXY.y);
		draggedBall = nullptr;
	}

	// 다음 단위 시간을 위해 초기화 
	clock.restart();

	//게임 끝났을 시
	if (false && endNum == 0) {
		LoadImage* end = new LoadImage("end.png", 800, 250, 125, 400);
		gameObjects.push_back(end); 
		endNum = 1;
	}
}

// 상속 클래스는 반드시 객체 렌더링 함수 구현해야 함 
void SampleGame::render(sf::RenderTarget& target)
{
	// 화면 클리어 
	window->clear(sf::Color(75, 103, 163));

	// 게임 오브젝트 렌더링 
	for (SampleBilliardObject* obj : gameObjects)
	{
		obj->render(target);
	}

	// 공을 드래그 하면 세기 표시 (길이 및 색)
	renderDragpower(target);

	// 게임 UI 렌더링 
	
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
