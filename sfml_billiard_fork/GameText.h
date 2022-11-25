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
	
	// Sample Game�� ��ü���� �ݵ�� ���� ���� �Լ� �����ؾ� �� 
	 void update(float timeElapsed);

	// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
	 void collide(SampleBilliardObject& other);
	  
	// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
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