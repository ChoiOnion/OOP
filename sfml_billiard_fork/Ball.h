#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Object.h"
#include "Board.h"
#include "Hole.h"

class  Ball : public  Object
{
public:
	// ������ ���� ���� ��� 
	const float VISCOSITY;

	// �������� ���� ���ؽ� ��� 
	const int NUMVERTICES;

public:
	// ������ 
	 Ball(void);
	 Ball(sf::Vector2f center, float radius, sf::Color color);
	 Ball(const  Ball&);

	// �Ҹ��� 
	virtual ~ Ball(void);

	// ������ 
	 Ball& operator=(const  Ball&);

	// Sample Game�� ��ü���� �ݵ�� ���� ���� �Լ� �����ؾ� �� 
	virtual void update(float timeElapsed);

	// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
	virtual void collide( Object& other);

	// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
	virtual void render(sf::RenderTarget& target);

	// setter 
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	void setAcceleration(sf::Vector2f acceleration);
	void setVelocity(float x, float y);
	void setVelocity(sf::Vector2f velocity);
	void setAngle(float angle);
	void setRadius(float radius);
	void setMass(float mass);
	void setColor(sf::Color color);
	void setWhatBall(int param);

	void moveBall(int ballType);

	// getter 
	sf::Vector2f	getPosition(void) const;
	sf::Vector2f	getAcceleration(void) const;
	sf::Vector2f	getVelocity(void) const;
	float getAngle(void) const;
	float getRadius(void) const;
	float getMass(void) const;
	sf::Color getColor(void) const;
	const sf::VertexArray& getVertices(void) const;
	//�� �Ǻ��� ���� whatBall�� getter
	int getWhatball();
	bool getGoal();


	int check = 0;

private:
	// ���� �浹�� ��� 
	void collideWithBall( Ball& other);

	// �籸��� �浹�� ��� 
	void collideWithBoard( Board& other);

	//���� ���� ���
	void collideWithHole( Hole& other);

private:
	sf::Vector2f position;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;

	float angle;
	float radius;
	float mass;

	bool goal = false;

	sf::VertexArray vertices;
	sf::Color color;

	int whatBall = 0; //�Ǻ��� ���� ����

	int turn = 1;
};