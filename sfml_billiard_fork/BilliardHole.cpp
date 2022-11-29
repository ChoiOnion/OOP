#include "BilliardHole.h"

SampleBilliardHole::SampleBilliardHole(void)
{
	texture.loadFromFile("textureBoard.png", sf::IntRect(1, 1, 454, 848));

	// 스프라이트 설정 
	// 스프라이트 설정 
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);

	SampleBilliardHole::Hole holeTopLeft(582.5f, 49.f, 596.5f, 35.f);
	SampleBilliardHole::Hole holeTopRight(1003.5f, 35.f, 1017.5f, 49.f);
	SampleBilliardHole::Hole holeLeft(587.5f, 458.5f, 587.5f, 442.5f);
	SampleBilliardHole::Hole holeRight(1012.5f, 442.f, 1012.5f, 458.5f);
	SampleBilliardHole::Hole holeDownLeft(596.5f, 865.5f, 582.5f, 851.f);
	SampleBilliardHole::Hole holeDownRight(1017.5f, 851.f, 1003.5f, 865.f);
	Holes.push_back(holeTopLeft);
	Holes.push_back(holeTopRight);
	Holes.push_back(holeLeft);
	Holes.push_back(holeRight);
	Holes.push_back(holeDownLeft);
	Holes.push_back(holeDownRight);
}
SampleBilliardHole::~SampleBilliardHole(void)
{
	Holes.clear();
}
void SampleBilliardHole::update(float timeElapsed)
{
	// Sample Game의 당구대는 상태 갱신 X 
}

// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
void SampleBilliardHole::collide(SampleBilliardObject& other)
{
	// Sample Game의 당구대는 고정 오브젝트이기 때문에 충돌 X 
}

// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
void SampleBilliardHole::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

const std::vector<SampleBilliardHole::Hole>& SampleBilliardHole::getHoles(void) const
{
	return Holes;
}