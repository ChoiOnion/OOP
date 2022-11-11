#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


#include "SampleBilliardObject.h"

class BilliardHole : public SampleBilliardObject
{
public:
	const int NUMVERTICES;

public:
	BilliardHole(void);
	BilliardHole(sf::Vector2f center, float radius, sf::Color color);
	BilliardHole(const BilliardHole&);

	virtual ~BilliardHole(void);

	BilliardHole& operator=(const BilliardHole&);

	virtual void update(float timeElapsed);

	virtual void collide(SampleBilliardObject& other);

	virtual void render(sf::RenderTarget& target);

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	void setAcceleration(sf::Vector2f acceleration);
	void setVelocity(float x, float y);
	void setVelocity(sf::Vector2f velocity);
	void setAngle(float angle);
	void setRadius(float radius);
	void setMass(float mass);
	void setColor(sf::Color color);

	sf::Vector2f	getPosition(void) const;
	sf::Vector2f	getAcceleration(void) const;
	sf::Vector2f	getVelocity(void) const;
	float getAngle(void) const;
	float getRadius(void) const;
	float getMass(void) const;
	sf::Color getColor(void) const;
	const sf::VertexArray& getVertices(void) const;

private:
	void collideWithBall(BilliardHole& other);

private:

	sf::Vector2f position;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;

	float angle;
	float radius;
	float mass;

	sf::VertexArray vertices;
	sf::Color color;
};
