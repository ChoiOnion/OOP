#include "Ball.h"
#include "Board.h"
#include "GameBall.h"
#include "SolidBall.h"
#include "BlackBall.h"
#include "StripeBall.h"
#include "Player.h"
#include "Hole.h"
#include "SampleGame.h"

 Ball:: Ball(void) 
	:  Ball(sf::Vector2f(100, 100), 10, sf::Color::Red)

{
	// nothing to do 
}

 Ball:: Ball(sf::Vector2f position, float radius, sf::Color color) 
	: VISCOSITY(1.0f), NUMVERTICES(20)
{
	// ���� ������ Ư��
	this->position = position;
	this->radius = radius;
	this->angle = 0.f;
	this->mass = radius; 
	this->velocity = sf::Vector2f(0, 0);
	this->acceleration = sf::Vector2f(0, 0);

	// �� ����
	this->color = color;

	// ���� ������ �׸��� ���� ������ �ʱ�ȭ 
	vertices.setPrimitiveType(sf::TrianglesFan);
	vertices.clear();
	vertices.resize(NUMVERTICES);
	for (unsigned long i = 0; i != NUMVERTICES - 1; i++)
	{
		float x, y;
		x = position.x + radius * cosf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		y = position.y + radius * sinf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		vertices[i] = sf::Vertex(sf::Vector2f(x, y), color);
	}
}

 Ball:: Ball(const  Ball& rhs) :  Ball(rhs.position, rhs.radius, rhs.color)
{
	// nothing to do 
}

 Ball&  Ball::operator=(const  Ball& rhs)
{
	// ���ؽ� ���� ���� ���� 
	vertices.clear();
	vertices = rhs.vertices;
	position = rhs.position;
	radius = rhs.radius;
	color = rhs.color;

	return *this;
}

 Ball::~ Ball(void)
{
	vertices.clear();
}

void  Ball::setPosition(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}

void  Ball::setPosition(sf::Vector2f position)
{
	this->position = position;

	// ��ġ ���� �� �ش� ��ġ�� ���� ���� ������Ʈ 
	for (unsigned long i = 0; i != NUMVERTICES - 1; i++)
	{
		float x, y;
		x = position.x + radius * cosf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		y = position.y + radius * sinf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		vertices[i] = sf::Vertex(sf::Vector2f(x, y), color);
	}
}

void  Ball::setAcceleration(sf::Vector2f acceleration)
{
	this->acceleration = acceleration;
}

void  Ball::setVelocity(float x, float y)
{
	setVelocity(sf::Vector2f(x, y));
}

void  Ball::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

void  Ball::setAngle(float angle)
{
	this->angle = angle;
}

void  Ball::setRadius(float radius)
{
	this->radius = radius;
}

void  Ball::setMass(float mass)
{
	this->mass = mass;
}

void  Ball::setColor(sf::Color color)
{
	this->color = color; 
}

sf::Vector2f  Ball::getPosition(void) const
{
	return position;
}

sf::Vector2f  Ball::getAcceleration(void) const
{
	return acceleration;
}

sf::Vector2f  Ball::getVelocity(void) const
{
	return velocity;
}

float  Ball::getAngle(void) const
{
	return angle;
}

float  Ball::getRadius(void) const
{
	return radius;
}

float  Ball::getMass(void) const
{
	return mass;
}

sf::Color  Ball::getColor(void) const
{
	return color; 
}

const sf::VertexArray&  Ball::getVertices(void) const
{
	return vertices; 
}

int  Ball::getWhatball() {  //�� �Ǻ��� ���� whatBall�� getter
	return whatBall;
};

void  Ball::setWhatBall(int param) {
	this->whatBall = param;
}

bool  Ball::getGoal() {
	return goal;
}


// Sample Game�� ��ü���� �ݵ�� ���� ���� �Լ� �����ؾ� �� 
void  Ball::update(float timeElapsed)
{
	// ���� ������ ���� ���ӷ�(���ӵ�) ��� 
	acceleration = -velocity * VISCOSITY;

	// ���� ���ӵ��� �ð��� ���� ���ο� �ӵ� ��� 
	velocity += acceleration * timeElapsed;

	// �ӵ��� ���� ��ġ ������Ʈ 
	setPosition(position.x + velocity.x * timeElapsed, position.y + velocity.y * timeElapsed);

	// xy �ӷ¿� ���� �� ��� 
	// ����: https://ko.khanacademy.org/computing/computer-programming/programming-natural-simulations/programming-angular-movement/a/pointing-towards-movement
	setAngle(atan2f(velocity.y, velocity.x) * 180.f / float(M_PI));

	// �ӵ��� 0.1���� ������ ������ �����Ͽ� 0���� ���� 
	if (std::abs(velocity.x) < 0.1f || std::abs(velocity.y) < 0.1f)
	{
		velocity = sf::Vector2f(0.f, 0.f);
	}
}

// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
void  Ball::collide( Object& other)
{
	// ���� �浹�� ��� 
	if (dynamic_cast< Ball*>(&other) != nullptr)
	{
		 Ball& ball = *dynamic_cast< Ball*>(&other);
		collideWithBall(ball);
	}

	// �籸��� �浹�� ��� 
	if (dynamic_cast< Board*>(&other) != nullptr)
	{
		 Board& board = *dynamic_cast< Board*>(&other);
		collideWithBoard(board);
	}

	// ���� Ȧ�� �浹�� ���
	if (dynamic_cast< Hole*>(&other) != nullptr)
	{
		 Hole& hole = *dynamic_cast< Hole*>(&other);
		collideWithHole(hole);
	}
}

// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
void  Ball::render(sf::RenderTarget& target)
{
	// ������ �����쿡 ���� �����ϴ� ���ؽ��� �׸� 
	target.draw(vertices);
}


void  Ball::collideWithBall( Ball& other)
{
	// ������ �� �񱳽� ���� 
	if (this == &other)
	{
		return;
	}

	// �Ÿ� ��� 
	sf::Vector2f distance = getPosition() - other.getPosition();
	float distanceBetween = (sqrtf((distance.x * distance.x) + (distance.y * distance.y)));

	// �� ���� ��ġ���� �˻� 
	if (distanceBetween < (getRadius() + other.getRadius()))
	{
		// ��ġ�� ���� ��� 
		float overlap = (distanceBetween - getRadius() - other.getRadius()) / 2.f;
		float moveX = (overlap * (getPosition().x - other.getPosition().x) / distanceBetween);
		float moveY = (overlap * (getPosition().y - other.getPosition().y) / distanceBetween);

		// �� ���� ��ġ�� �ʵ��� �ٽ� ������� 
		setPosition(getPosition().x - moveX, getPosition().y - moveY);
		other.setPosition(other.getPosition().x + moveX, other.getPosition().y + moveY);

		// �浹 �� �ӵ� ����Ͽ� ����
		sf::Vector2f normal(distance.x / distanceBetween, distance.y / distanceBetween);
		sf::Vector2f tangential(-normal.y, normal.x);

		float dotProductTangential1 = getVelocity().x * tangential.x + getVelocity().y * tangential.y;
		float dotProductTangential2 = other.getVelocity().x * tangential.x + other.getVelocity().y * tangential.y;

		float dotProductNormal1 = getVelocity().x * normal.x + getVelocity().y * normal.y;
		float dotProductNormal2 = other.getVelocity().x * normal.x + other.getVelocity().y * normal.y;

		float m1 = (2.f * other.getMass() * dotProductNormal2 + dotProductNormal1 * (getMass() - other.getMass())) / (getMass() + other.getMass());
		float m2 = (2.f * getMass() * dotProductNormal1 + dotProductNormal2 * (other.getMass() - getMass())) / (getMass() + other.getMass());

		setVelocity(dotProductTangential1 * tangential + m1 * normal);
		other.setVelocity(dotProductTangential2 * tangential + m2 * normal);
	}
}

void  Ball::collideWithBoard( Board& other)
{
	for ( Board::Border border : other.getBorders())
	{
		sf::Vector2f p = getPosition();
		sf::Vector2f s(border.getPoints()[0].position);
		sf::Vector2f e = border.getPoints()[1].position;
		sf::Vector2f ps = p - s;
		sf::Vector2f se = e - s;

		float lineLength = (e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y);
		float t = ((ps.x * se.x) + (ps.y * se.y)) / lineLength;
		sf::Vector2f st(s.x + t * se.x, s.y + t * se.y);

		sf::Vector2f distance = p - st;
		float distanceBetween = sqrtf((distance.x * distance.x) + (distance.y * distance.y));

		sf::Vector2f normal = distance / distanceBetween;
		float dotProductNormal = getVelocity().x * normal.x + getVelocity().y * normal.y;

		sf::Vector2f tangential = sf::Vector2f(-normal.y, normal.x);
		float dotProductTangential = getVelocity().x * tangential.x + getVelocity().y * tangential.y;

		float overlap = distanceBetween - getRadius();
		if (distanceBetween <= getRadius())
		{
			if (t > -0.f && t < 1.f)
			{
				setPosition(p.x - distance.x * overlap / distanceBetween, p.y - distance.y * overlap / distanceBetween);
				setVelocity(-normal.x * dotProductNormal + tangential.x * dotProductTangential,
					-normal.y * dotProductNormal + tangential.y * dotProductTangential);
			}
		}
	}
}

void  Ball::collideWithHole( Hole& other)
{
	/*is1pStripe... ����� ��� ���� ���� �Ǻ����̶� ����ϰ� ��������!
	 Player a;
	if (a.is1pStripe()) {

	}
	*/


	for ( Hole::HoleIn hole : other.getHoles())
	{
		sf::Vector2f p = getPosition();
		sf::Vector2f s(hole.getPoints()[0].position);
		sf::Vector2f e = hole.getPoints()[1].position;
		sf::Vector2f ps = p - s;
		sf::Vector2f se = e - s;

		float lineLength = (e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y);
		float t = ((ps.x * se.x) + (ps.y * se.y)) / lineLength;
		sf::Vector2f st(s.x + t * se.x, s.y + t * se.y);

		sf::Vector2f distance = p - st;
		float distanceBetween = sqrtf((distance.x * distance.x) + (distance.y * distance.y));

		if (distanceBetween <= getRadius()*2)
		{
			if (t > -0.f && t < 1.f)
			{
				goal = true;
				static int pos = 1;
				setPosition(radius + pos,radius);
				setVelocity(sf::Vector2f(0.f, 0.f));
				pos += 2 * radius;
				if (goal) {
					 GameBall a;
					 BlackBall b;
					 SolidBall c;
					 StripeBall d;
					if (a.isPlayerBall(*this)) {
						this->setWhatBall(3);
						this->setPosition(800, 680);
					}
					else if (b.isEightBall(*this)) {
						this->setWhatBall(4);
					}
					else if (c.isSolidBall(*this)) {
						this->setWhatBall(2);
						//player1
						// if player1->setTurn(true)
						//this->setPosition(163, 720); //ù��° ���� �� ��ġ
						//this->setPosition(193, 720); //2
						//player2
						// else
						//this->setPosition(163, 920); //ù��° ���� �� ��ġ
						//this->setPosition(193, 920); //2
					}
					else if (d.isStripeBall(*this)) {
						this->setWhatBall(1);
					}
				}
			}
		}
	}
}


void Ball::moveBall(int ballType) {
	int a = 0;
	if (turn == 1) {
		std::cout << "1p" << std::endl;
		if (ballType == 1) {

		}
		else if (ballType == 2) {

		}
		else if (ballType == 3) {

		}
		else if (ballType == 4) {

		}
		else if (ballType == 0) {
			turn = 2;
		}
	}
	else if (turn == 2) {
		std::cout << "2p" << std::endl;
		if (ballType == 1) {

		}
		else if (ballType == 2) {

		}
		else if (ballType == 3) {

		}
		else if (ballType == 4) {

		}
		else if (ballType == 0) {
			turn = 1;
		}
	}
}