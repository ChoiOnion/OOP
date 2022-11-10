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
	//좌표랑 구멍 크기 찾아야댐...
	SampleBilliardBoard::Hole Hole1();
	SampleBilliardBoard::Hole Hole2();
	SampleBilliardBoard::Hole Hole3();
	SampleBilliardBoard::Hole Hole4();
	SampleBilliardBoard::Hole Hole5();
	SampleBilliardBoard::Hole Hole6();

}

// 소멸자 
SampleBilliardBoard::~SampleBilliardBoard(void)
{
	borderLines.clear();
}
void SampleBilliardBoard::getHole()
{
}

bool SampleBilliardBoard::isHole()
{
	if (false)    //공 들어가면
		return true;
	else
		return false;
}
void SampleBilliardBoard::setHole()
{

// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
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
