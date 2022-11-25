#include "SampleBilliardGameBall.h"
#include "SampleGame.h"
#include "GameText.h"
#include "SampleBilliardPlayer.h"

GameText::GameText(std::string text, float x, float y,int size,sf::Color bgColor,int lineSize) {
	this->text = text;
	this->x = x;
	this->y = y;
	this->size = size;
	this->bgColor = bgColor; 
	this->lineSize = lineSize;
}

void GameText::update(float timeElapsed) {
	SampleBilliardPlayer p{};
	if (p.getturn1p()) {
		t.setPosition(150, 600);
	}
	else if (p.getturn2p()) {
		t.setPosition(150, 800);
	}
}

void GameText::collide(SampleBilliardObject& other) {

}



void GameText::render(sf::RenderTarget& target)
{
	// �� ���� �׸� 

	// SampleGame������ �� ���� �÷��̾� ���� ǥ�� 
	t.setFont(SampleGame::getFont());
	t.setFillColor(sf::Color::Black);
	t.setOutlineColor(bgColor);
	t.setOutlineThickness(lineSize);
	t.setString(text);
	t.setCharacterSize(size);
	t.setPosition(x, y);
	target.draw(t);
}