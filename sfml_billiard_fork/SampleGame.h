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
	// Sample Game 초기화 
	SampleGame(int width, int height, int fpsLimit);
	
	// Sample Game 해제 
	virtual ~SampleGame(void);

	// Sample Game 전역 폰트 
	static const sf::Font& getFont(void);

protected:
	// 상속 클래스는 반드시 이벤트 핸들링 함수 구현해야 함 
	virtual void handle(sf::Event& ev);

	// 상속 클래스는 반드시 게임 상태 갱신 함수 구현해야 함 
	virtual void update(void);

	// 상속 클래스는 반드시 객체 렌더링 함수 구현해야 함 
	virtual void render(sf::RenderTarget& target);

private:
	// Sample Game 에서 공을 쏘는 강도 표시
	void renderDragpower(sf::RenderTarget& target);

private:
	// Sample Game에서 관리하는 게임 오브젝트들 (공, 당구대 등) 
	std::vector< Object*> gameObjects;

	std::vector< Ball*> balls;

	std::vector<LoadImage*> images;

	std::vector<GameText*>turn;

	// 게임 UI 
	sf::Text explanation;  //설명

	// 게임 시간 
	sf::Clock clock;

	// 마우스 위치
	sf::Vector2f mouseXY;

	// 공 발사용 
	bool isDraggingBall;
	 GameBall* draggedBall;

	// 게임 전역 폰트 
	static sf::Font* font;

	int helpNum = 0;
	int endNum = 0;
	int pauseNum = 0;
	int checkEnd = 0;

	Player* player1=new Player(true);
	Player* player2=new Player(false);

	bool breakShot = true;
}; 