#include "SampleGame.h"
#include "SampleBilliardBoard.h"
#include "SampleBilliardGameBall.h"
#include "SampleBilliardObject.h"
#include "GameText.h"
#include "LoadImage.h"


SampleGame::SampleGame(int width, int height, int fpsLimit)
	:BaseGame(width, height, fpsLimit), isDraggingBall(false), draggedBall(nullptr)
{
	// SampleGame�� ���� �������̽� ���� �� ��� 
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

	// SampleGame�� ���� �籸�� ���� �� ��� 
	gameObjects.push_back(new SampleBilliardBoard());

	// SampleGame�� ���� �籸�� ���� �� ��� 
	SampleBilliardGameBall* ball1 = new SampleBilliardGameBall(sf::Vector2f(800, 500), 10, sf::Color::Yellow);
	SampleBilliardGameBall* ball2 = new SampleBilliardGameBall(sf::Vector2f(800, 400), 10, sf::Color::Yellow);
	ball2->setOwner("2P");
	ball1->setPlayable(true);
	ball2->setPlayable(true);
	gameObjects.push_back(ball1);
	gameObjects.push_back(ball2);

}

SampleGame::~SampleGame(void)
{
	// UI �ν��Ͻ� ����  

	// ���� ������Ʈ�� ���� 
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
		if (ev.key.code == sf::Keyboard::Escape && pauseNum == 0)							//���� Ű�� �ϸ� �ȸԤ��� �Ф�
		{
			// TODO: game paused 
			gameObjects.push_back(new LoadImage("pause.png", 800, 250, 125, 400));
			pauseNum = 1;
			//�÷��̾� �� false ����
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
			for (SampleBilliardObject* obj : gameObjects)
			{
				// SampleBilliardBall�� �ν��Ͻ��� �ƴ� ��� pass
				SampleBilliardGameBall* gameBall = dynamic_cast<SampleBilliardGameBall*>(obj);
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
	for (SampleBilliardObject* obj : gameObjects)
	{
		obj->update(clock.getElapsedTime().asSeconds());
	}

	// ���� ������Ʈ �浹 �˻�
	for (SampleBilliardObject* obj1 : gameObjects)
	{
		for (SampleBilliardObject* obj2 : gameObjects)
		{
			obj1->collide(*obj2);
		}
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
		gameObjects.push_back(end); 
		endNum = 1;
	}
}

// ��� Ŭ������ �ݵ�� ��ü ������ �Լ� �����ؾ� �� 
void SampleGame::render(sf::RenderTarget& target)
{
	// ȭ�� Ŭ���� 
	window->clear(sf::Color(75, 103, 163));

	// ���� ������Ʈ ������ 
	for (SampleBilliardObject* obj : gameObjects)
	{
		obj->render(target);
	}

	// ���� �巡�� �ϸ� ���� ǥ�� (���� �� ��)
	renderDragpower(target);

	// ���� UI ������ 
	
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
