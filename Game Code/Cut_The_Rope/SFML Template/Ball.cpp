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

	// Ball Appearance 
	m_TempBall.setFillColor(sf::Color::Blue);
	m_TempBall.setOutlineColor(sf::Color::Magenta);

	// Set the values of friction, density and bouncyness. 
	m_SetProperties(1.f, 0.3f, 0.5f);
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

/*! Update Position : This will be used to set the object's sfml sprites position to be equal to that of its b2Body.
\
*/
void Ball::m_UpdatePosition()
{
	// Update Position. 

	m_TempBall.setPosition(m_Body->GetPosition().x, m_Body->GetPosition().y);

	// Update Rotation.

	float angle = m_Body->GetAngle();

	if (angle <= 0)
	{
		angle += 360;
	}
	else if (angle > 360)
	{
		angle -= 360;
	}

	m_TempBall.setRotation(angle);

}
