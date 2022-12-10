#include "Board.h"



 Board:: Board(void)
{
	// Sample Game을 위한 당구대 텍스처 이미지 로드 
	// Sample Game을 위한 당구대 텍스처 이미지 로드 
	texture.loadFromFile("textureBoard.png", sf::IntRect(1, 1, 454, 848));

	// 스프라이트 설정 
	// 스프라이트 설정 
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);

	// 당구대 경계 초기화 - 상하좌우
	 Board::Border lineTopL(602.5f, 40.f, 617.f, 55.f);
	 Board::Border lineTop(617.f, 55.f, 983.5, 55.f);
	 Board::Border lineTopR(983.5f, 45.f, 998.5f, 40.f);
	borderLines.push_back(lineTopL);
	borderLines.push_back(lineTop);
	borderLines.push_back(lineTopR);

	 Board::Border lineTopRightL(1012.5f, 54.f, 997.5f, 69.5f);
	 Board::Border lineTopRight(997.5f, 69.5f, 887.5f, 443.5f);
	 Board::Border lineTopRightR(997.5f, 433.5f, 1012.5f, 442.f);
	borderLines.push_back(lineTopRightL);
	borderLines.push_back(lineTopRight);
	borderLines.push_back(lineTopRightR);

	 Board::Border lineDownRightL(1012.5f, 458.5f, 997.5f, 466.5f);
	 Board::Border lineDownRight(1002.5f, 466.5f, 1002.5f, 830.5f);
	 Board::Border lineDownRightR(997.5f, 830.5f, 1012.5f, 846.f);
	borderLines.push_back(lineDownRightL);
	borderLines.push_back(lineDownRight);
	borderLines.push_back(lineDownRightR);

	 Board::Border lineDownL(998.5f, 860.f, 983.5f, 845.f);
	 Board::Border lineDown(983.5f, 845.f, 616.5f, 845.f);
	 Board::Border lineDownR(616.5f, 850.f, 602.5f, 860.5f);
	borderLines.push_back(lineDownL);
	borderLines.push_back(lineDown);
	borderLines.push_back(lineDownR);

	 Board::Border lineDownLeftL(587.5f, 846.f, 602.5f, 830.5f);
	 Board::Border lineDownLeft(602.5f, 830.5f, 602.5f, 466.5f);
	 Board::Border lineDownLeftR(602.5f, 466.5f, 587.5f, 458.5f);
	borderLines.push_back(lineDownLeftL);
	borderLines.push_back(lineDownLeft);
	borderLines.push_back(lineDownLeftR);

	 Board::Border lineTopLeftL(587.5f, 442.5f, 602.5f, 433.5f);
	 Board::Border lineTopLeft(602.5f, 433.5f, 602.5f, 69.5f);
	 Board::Border lineTopLeftR(602.5f, 69.5f, 587.5f, 54.f);
	borderLines.push_back(lineTopLeftL);
	borderLines.push_back(lineTopLeft);
	borderLines.push_back(lineTopLeftR);

	//홀 경계 초기화
	
}	


// 소멸자 
 Board::~ Board(void)
{
	borderLines.clear();
}

void  Board::update(float timeElapsed)
{
	// Sample Game의 당구대는 상태 갱신 X 
}

// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
void  Board::collide( Object& other)
{
	// Sample Game의 당구대는 고정 오브젝트이기 때문에 충돌 X 
}

// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
void  Board::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

// 당구대를 구성하는 경계 요소 반환 
const std::vector< Board::Border>&  Board::getBorders(void) const
{
	return borderLines;
}


