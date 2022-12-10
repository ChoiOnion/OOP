#pragma once

#include <iostream> 
#include <vector> 

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "BaseGame.h"
#include "Object.h"
#include "GameBall.h"
#include "LoadImage.h"
#include "GameText.h"
#include "Player.h"


class SampleGame : public BaseGame
{
public:
	// Sample Game �ʱ�ȭ 
	SampleGame(int width, int height, int fpsLimit);
	
	// Sample Game ���� 
	virtual ~SampleGame(void);

	// Sample Game ���� ��Ʈ 
	static const sf::Font& getFont(void);

protected:
	// ��� Ŭ������ �ݵ�� �̺�Ʈ �ڵ鸵 �Լ� �����ؾ� �� 
	virtual void handle(sf::Event& ev);

	// ��� Ŭ������ �ݵ�� ���� ���� ���� �Լ� �����ؾ� �� 
	virtual void update(void);

	// ��� Ŭ������ �ݵ�� ��ü ������ �Լ� �����ؾ� �� 
	virtual void render(sf::RenderTarget& target);

private:
	// Sample Game ���� ���� ��� ���� ǥ��
	void renderDragpower(sf::RenderTarget& target);

private:
	// Sample Game���� �����ϴ� ���� ������Ʈ�� (��, �籸�� ��) 
	std::vector< Object*> gameObjects;

	std::vector< Ball*> balls;

	std::vector<LoadImage*> images;

	std::vector<GameText*>turn;

	// ���� UI 
	sf::Text explanation;  //����

	// ���� �ð� 
	sf::Clock clock;

	// ���콺 ��ġ
	sf::Vector2f mouseXY;

	// �� �߻�� 
	bool isDraggingBall;
	 GameBall* draggedBall;

	// ���� ���� ��Ʈ 
	static sf::Font* font;

	int helpNum = 0;
	int endNum = 0;
	int pauseNum = 0;
	int checkEnd = 0;

	Player* player1=new Player(true);
	Player* player2=new Player(false);

	bool breakShot = true;
	int remainStripe = 7;
	int remainSolide = 7;
}; 