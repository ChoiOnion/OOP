#pragma once

#include <iostream>
#include <vector> 

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "SampleBilliardObject.h"

class LoadImage : public SampleBilliardObject
{
public:
	// ������ 
	LoadImage(std::string file, float imageX, float imageY, float x, float y);

	~LoadImage();

	// Sample Game�� ��ü���� �ݵ�� ���� ���� �Լ� �����ؾ� �� 
	virtual void update(float timeElapsed);

	// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
	virtual void collide(SampleBilliardObject& other);

	// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
	virtual void render(sf::RenderTarget& target);

private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string file; 
	float imageX{};
	float imageY{};
	float x{};
	float y{};

};
