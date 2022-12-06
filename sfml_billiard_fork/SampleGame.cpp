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
	// SampleGame�� ���� �������̽� ���� �� ��� 
	GameText* playerText1 = new GameText("Player1", 50, 610, 20, sf::Color::White, 3);
	GameText* playerText2 = new GameText("Player2", 50, 810, 20, sf::Color::White, 3);
	gameObjects.push_back(playerText1);
	gameObjects.push_back(playerText2);

	LoadImage* player1img = new LoadImage("player.png", 250, 250, 40, 650);
	LoadImage* player2img = new LoadImage("player.png", 250, 250, 40, 850);
	gameObjects.push_back(player1img);
	gameObjects.push_back(player2img);

	Player* player1 = new  Player();
	gameObjects.push_back(player1);
	Player* player2 = new  Player();
	gameObjects.push_back(player2);

	GameText* help = new GameText("Press H : help", 20, 20, 30, sf::Color::White, 3);
	gameObjects.push_back(help);


	// �� �� �ڸ� ǥ��
	LoadImage* ballPosition1 = new LoadImage("ballposition.png", 250, 250, 120, 670);
	gameObjects.push_back(ballPosition1);

	LoadImage* ballPosition2 = new LoadImage("ballposition.png", 250, 250, 120, 870);
	gameObjects.push_back(ballPosition2);
	

	// SampleGame�� ���� �籸�� ���� �� ��� 
	gameObjects.push_back(new  Board());
	gameObjects.push_back(new  Hole());

	// SampleGame�� ���� �籸�� ���� �� ��� 
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
	// UI �ν��Ͻ� ����  

	// ���� ������Ʈ�� ���� 
	for ( Object* obj : gameObjects)
	{
		delete obj;
	}

	for (Ball* b : balls) {
		delete b;
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

// ��� Ŭ������ �ݵ�� �̺�Ʈ �ڵ鸵 �Լ� �����ؾ� �� 
void SampleGame::handle(sf::Event& ev)
{
	// SampleGame�� ���� �Է� �̺�Ʈ ó�� 
	switch (ev.type)
	{
	case sf::Event::Closed:
		// �������� x ��ư ������ �����Ѵ� 
		window->close();
		break;
	case sf::Event::KeyPressed:
		// Ű���� �̺�Ʈ                                            
		if (ev.key.code == sf::Keyboard::Escape && pauseNum == 0)							//���� Ű�� �ϸ� �ȸ���!! Ű ���� �����ؾ� �� �� ���ƿ�
		{
			// TODO: game paused 
			images.push_back(new LoadImage("pause.png", 800, 250, 125, 400));
			pauseNum = 1;
			
		}
		if (ev.key.code == sf::Keyboard::P && pauseNum == 1)
		{
			images.pop_back();
			pauseNum = 0;
		}
		if (ev.key.code == sf::Keyboard::H && helpNum == 0)
		{
			images.push_back(new LoadImage("rule.png", 800, 850, 125, 50));
			helpNum = 1;
		}
		if (ev.key.code == sf::Keyboard::C && helpNum == 1)
		{
			images.pop_back();
			helpNum = 0;
		}
		if (ev.key.code == sf::Keyboard::E && endNum == 1) {
			window->close();
			break;
		}
		if (ev.key.code == sf::Keyboard::R && endNum == 1) {
			//�ٽ� ����
		}
		break;
	case sf::Event::MouseMoved:
		// ���콺 ������ �̺�Ʈ 
		mouseXY.x = (float)ev.mouseMove.x;
		mouseXY.y = (float)ev.mouseMove.y;
		break;
	case sf::Event::MouseButtonPressed:
		// ���콺 ��ư ���� �̺�Ʈ 
		if (ev.mouseButton.button == sf::Mouse::Left)
		{
			for ( Ball* b : balls)
			{
				if (b != nullptr) {
					if (b->getGoal()&&b->check==0) {
						std::cout << b->getWhatball();
						for (Object* obj : gameObjects) {
							Player* player = dynamic_cast<Player*>(obj);
							player->checkTurn(b->getWhatball());
							/*
							Ball->moveBall
Player->checkTurn

�Ѿ�� �ϴ� ����: �극��ũ�� ���� / ��� �¸� Ȥ�� �й� / ���� �� / �� �Ѿ ���� / �÷��̾��� ������

moveBall
->�ʿ���� �� ���⵵ �ϳ׿�..

checkTurn
->�÷��̾� ������, �¸� Ȥ�� �й� �Ǻ�, �극��ũ�� �� �� ���� ����, ���� �� ����

�� �Ѿ�� �� SampleGame���� set�ϱ�.
->�Ǻ��� ���ϰ� �ʿ�, checkTurn���� ������ ��
							*/
						}
						b->check++;
					}
				}
				 GameBall* gameBall = dynamic_cast< GameBall*>(b);
				if (gameBall == nullptr)
				{
					continue;
				}
				// Ŀ���� ���� ���ΰ� �ƴ� ��� pass 
				if (!gameBall->isIntersecting(mouseXY))
				{
					continue;
				}
				// ���� Playable�� �ƴ� ��� pass 
				if (!gameBall->isPlayable()) {
					continue;
				}

				//�巡�� �� ������ ���� �ٲ��� ��

				// �巡�� ������ �� �ӽ� ���� 
				draggedBall = gameBall;
				isDraggingBall = true;
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		// ���콺 ��ư �� �̺�Ʈ 
		if (ev.mouseButton.button == sf::Mouse::Left && isDraggingBall)
		{
			isDraggingBall = false;

		}
		break;
	}
}

// ��� Ŭ������ �ݵ�� ���� ���� ���� �Լ� �����ؾ� �� 
void SampleGame::update(void)
{
	// ���� ������Ʈ ������Ʈ 
	for ( Object* obj : gameObjects)
	{
		obj->update(clock.getElapsedTime().asSeconds());
	}

	// ���� ������Ʈ �浹 �˻�
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
	
	// �����ٰ� ���� ���� �ӵ��� �����ϰ� ǥ�� ���� 
	if (!isDraggingBall && draggedBall != nullptr)
	{
		draggedBall->setVelocity(draggedBall->getPosition().x - mouseXY.x, draggedBall->getPosition().y - mouseXY.y);
		draggedBall = nullptr;
	}


	// ���� ���� �ð��� ���� �ʱ�ȭ 
	clock.restart();

	//���� ������ ��
	if (false && endNum == 0) {
		LoadImage* end = new LoadImage("end.png", 800, 250, 125, 400);
		images.push_back(end);
		endNum = 1;
	}
}

// ��� Ŭ������ �ݵ�� ��ü ������ �Լ� �����ؾ� �� 
void SampleGame::render(sf::RenderTarget& target)
{
	// ȭ�� Ŭ���� 
	window->clear(sf::Color(75, 103, 163));

	// ���� ������Ʈ ������ 
	for ( Object* obj : gameObjects)
	{
		obj->render(target);
	}

	for (Ball* b : balls) {
		b->render(target);
	}


	// ���� �巡�� �ϸ� ���� ǥ�� (���� �� ��)
	renderDragpower(target);

	// ���� UI ������ 
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
