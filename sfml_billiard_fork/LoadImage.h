#pragma once

#include <iostream>
#include <vector> 

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Object.h"

class LoadImage : public Object
{
public:
	// 생성자 
	LoadImage(std::string file, float imageX, float imageY, float x, float y);

	~LoadImage();

	// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
	virtual void update(float timeElapsed);

	// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
	virtual void collide(Object& other);

	// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
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
