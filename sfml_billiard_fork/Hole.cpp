#include "BilliardHole.h"

 Hole:: Hole()
{
	texture.loadFromFile("textureBoard.png", sf::IntRect(1, 1, 454, 848));

	// ��������Ʈ ���� 
	// ��������Ʈ ���� 
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);

	 Hole::Hole holeTopLeft(582.5f, 49.f, 596.5f, 35.f);
	 Hole::Hole holeTopRight(1003.5f, 35.f, 1017.5f, 49.f);
	 Hole::Hole holeLeft(587.5f, 458.5f, 587.5f, 442.5f);
	 Hole::Hole holeRight(1012.5f, 442.f, 1012.5f, 458.5f);
	 Hole::Hole holeDownLeft(596.5f, 865.5f, 582.5f, 851.f);
	 Hole::Hole holeDownRight(1017.5f, 851.f, 1003.5f, 865.f);
	Holes.push_back(holeTopLeft);
	Holes.push_back(holeTopRight);
	Holes.push_back(holeLeft);
	Holes.push_back(holeRight);
	Holes.push_back(holeDownLeft);
	Holes.push_back(holeDownRight);
}
 Hole::~ Hole(void)
{
	Holes.clear();
}
void  Hole::update(float timeElapsed)
{
	// Sample Game�� �籸��� ���� ���� X 
}

// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
void  Hole::collide( Object& other)
{
	// Sample Game�� �籸��� ���� ������Ʈ�̱� ������ �浹 X 
}

// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
void  Hole::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

const std::vector< Hole::Hole>&  Hole::getHoles(void) const
{
	return Holes;
}