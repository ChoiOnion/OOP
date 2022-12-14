#include "Hole.h"

 Hole:: Hole()
{
	texture.loadFromFile("textureBoard.png", sf::IntRect(1, 1, 454, 848));

	// 스프라이트 설정 
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);

	Hole::HoleIn holeTopLeft(582.5f, 49.f, 596.5f, 35.f);
	Hole::HoleIn holeTopRight(1003.5f, 35.f, 1017.5f, 49.f);
	Hole::HoleIn holeLeft(587.5f, 458.5f, 587.5f, 442.5f);
	Hole::HoleIn holeRight(1012.5f, 442.f, 1012.5f, 458.5f);
	Hole::HoleIn holeDownLeft(596.5f, 865.5f, 582.5f, 851.f);
	Hole::HoleIn holeDownRight(1017.5f, 851.f, 1003.5f, 865.f);
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
}

// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
void  Hole::collide(Object& other)
{ 
}
 
void  Hole::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

const std::vector< Hole::HoleIn>&  Hole::getHoles(void) const
{
	return Holes;
}