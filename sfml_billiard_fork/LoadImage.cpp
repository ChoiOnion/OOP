#include "LoadImage.h"

LoadImage::LoadImage(std::string file, float imageX, float imageY, float x, float y)
{
	this->file = file;
	this->imageX = imageX;
	this->imageY = imageY;
	this->x - x;
	this->y = y;

	texture.loadFromFile(file, sf::IntRect(0, 0, imageX, imageY)); 

	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void LoadImage::update(float timeElapsed)
{
}

// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
void LoadImage::collide(SampleBilliardObject& other)
{
}

// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
void LoadImage::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}