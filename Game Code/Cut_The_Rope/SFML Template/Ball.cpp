/*!\file Ball.cpp
*
* This will house all of the function declarations for the class Ball.
*
*/

#include "Ball.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
Ball::Ball()
{

	// Ball Size
	m_TempBall.setRadius(m_fBallSize); 
	m_DynamicBall.m_radius = m_fBallSize;

	// Ball Possition
	m_TempBall.setPosition(1.f, 1.f);
	m_BallBodyDef.type = b2_dynamicBody; 
	m_BallBodyDef.position.Set(1.f, 1.f);

	// Ball Appearance 
	m_TempBall.setFillColor(sf::Color::Blue);
	m_TempBall.setOutlineColor(sf::Color::Magenta);

	// Set Fixture Values 
	m_FixtureDef.shape = &m_DynamicBall;
	m_FixtureDef.density = m_fDensity;
	m_FixtureDef.friction = m_fFriction;
	m_FixtureDef.restitution = m_fBouncyness;

	std::cout << "Ball Created" << std::endl;
}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
Ball::~Ball()
{
	
}

//-------------------------------------------------------------

/*! Draw Ball : This will draw the ball into the game window.
\Param One - Render Window : This will be the main game window for the game, allowing for the sprite to be drawn. 
*/
void Ball::m_DrawBall(sf::RenderWindow &window)
{
	window.draw(m_TempBall);
}

//-------------------------------------------------------------

/*! Add To Physics World : This will allow for the platform to interact with objects within the physics world.
\Param One - b2World : This function requires reference to the current physics world.
*/
void Ball::m_AddToPhysicsWorld(b2World * world)
{
	m_BallBody = world->CreateBody(&m_BallBodyDef);

	m_BallBody->CreateFixture(&m_FixtureDef);

	std::cout << "Ball Added to Physics World" << std::endl;
}

//-------------------------------------------------------------

/*! Update Position : This will be used to set the object's sfml sprites position to be equal to that of its b2Body.
\
*/
void Ball::m_UpdatePosition()
{
	m_TempBall.setPosition(m_BallBody->GetPosition().x, m_BallBody->GetPosition().y);

	// std::cout << "Ball X: " << std::abs(m_BallBody->GetPosition().x) << " Ball Y: " << std::abs(m_BallBody->GetPosition().y) << std::endl;
}
