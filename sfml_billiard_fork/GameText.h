#pragma once
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class GameText : public SampleBilliardObject
{
public:
	GameText(std::string text, float x, float y, int size, sf::Color bgColor,int lineSize);
	
	// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
	 void update(float timeElapsed);

	// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
	 void collide(SampleBilliardObject& other);
	  
	// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
	 void render(sf::RenderTarget& target);

private:
	std::string text{};
	float x{};
	float y{};
	int size{};
	sf::Color bgColor{};
	int lineSize{};

	sf::Text t{};
};