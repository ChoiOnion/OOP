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
	// 마찰에 따른 감속 상수 
	const float VISCOSITY;

	// 렌더링을 위한 버텍스 상수 
	const int NUMVERTICES;

public:
	// 생성자 
	 Ball(void);
	 Ball(sf::Vector2f center, float radius, sf::Color color);
	 Ball(const  Ball&);

	// 소멸자 
	virtual ~ Ball(void);

	// 연산자 
	 Ball& operator=(const  Ball&);

	// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
	virtual void update(float timeElapsed);

	// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
	virtual void collide( Object& other);

	// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
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
	//턴 판별을 위한 whatBall의 getter
	int getWhatball();
	bool getGoal();


	int check = 0;

private:
	// 공과 충돌한 경우 
	void collideWithBall( Ball& other);

	// 당구대와 충돌한 경우 
	void collideWithBoard( Board& other);

	//공이 들어갔을 경우
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

	int whatBall = 0; //판별을 위한 변수

	int turn = 1;
};