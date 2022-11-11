#include "SampleBilliardBoard.h"


SampleBilliardBoard::SampleBilliardBoard(void)
{
	// Sample Game을 위한 당구대 텍스처 이미지 로드 
	// Sample Game을 위한 당구대 텍스처 이미지 로드 
	texture.loadFromFile("textureBoard.png", sf::IntRect(1, 1, 454, 848));

	// 스프라이트 설정 
	// 스프라이트 설정 
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);

	// 당구대 경계 초기화 - 상하좌우 
	// 당구대 경계 초기화 - 상하좌우 
	SampleBilliardBoard::Border lineTop(602.5f, 55.f, 998.5f, 55.f);
	SampleBilliardBoard::Border lineLeft(602.5f, 55.f, 602.5f, 830.5f);
	SampleBilliardBoard::Border lineBottom(602.5f, 830.5f, 998.5f, 830.5f);
	SampleBilliardBoard::Border lineRight(998.5f, 55.f, 998.5f, 830.5f);
	borderLines.push_back(lineTop);
	borderLines.push_back(lineBottom);
	borderLines.push_back(lineLeft);
	borderLines.push_back(lineRight);

	SampleBilliardBoard::Border holeTopLeft(582.5f, 49.f, 596.5f, 35.f);
	SampleBilliardBoard::Border holeTopRight(1003.5f, 35.f, 1017.5f, 49.f);
	SampleBilliardBoard::Border holeLeft(587.5f, 458.5f, 587.5f, 442.5f);
	SampleBilliardBoard::Border holeRight(1012.5f, 442.f, 1012.5f, 458.5f);
	SampleBilliardBoard::Border holeDownLeft(596.5f, 865.5f, 582.5f, 851.f);
	SampleBilliardBoard::Border holeDownRight(1017.5f, 851.f, 1003.5f, 865.f);
	Holes.push_back(holeTopLeft);
	Holes.push_back(holeTopRight);
	Holes.push_back(holeLeft);
	Holes.push_back(holeRight);
	Holes.push_back(holeDownLeft);
	Holes.push_back(holeDownRight);
}

// 소멸자 
SampleBilliardBoard::~SampleBilliardBoard(void)
{
	borderLines.clear();
	Holes.clear();
}

void SampleBilliardBoard::update(float timeElapsed)
{
	// Sample Game의 당구대는 상태 갱신 X 
}

// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
void SampleBilliardBoard::collide(SampleBilliardObject& other)
{
	// Sample Game의 당구대는 고정 오브젝트이기 때문에 충돌 X 
}

// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
void SampleBilliardBoard::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

// 당구대를 구성하는 경계 요소 반환 
const std::vector<SampleBilliardBoard::Border>& SampleBilliardBoard::getBorders(void) const
{
	return borderLines;
}

const std::vector<SampleBilliardBoard::Border>& SampleBilliardBoard::getHoles(void) const
{
	return Holes;
}
