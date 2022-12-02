#pragma once

class  Object
{
public: 
	// Sample Game�� ��ü���� �ݵ�� ���� ���� �Լ� �����ؾ� �� 
	virtual void update(float timeElapsed) = 0;

	// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
	virtual void collide( Object& other) = 0;

	// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
	virtual void render(sf::RenderTarget& target) = 0;
}; 