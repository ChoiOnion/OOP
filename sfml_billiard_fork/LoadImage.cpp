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
LoadImage::~LoadImage () {

}

void LoadImage::update(float timeElapsed)
{
}

// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
void LoadImage::collide(Object& other)
{
}

// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
void LoadImage::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}