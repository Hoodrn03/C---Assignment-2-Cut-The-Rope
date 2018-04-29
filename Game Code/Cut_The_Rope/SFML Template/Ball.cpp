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

	// Ball Tag
	m_Tag = BALL_ENTITY; 

}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
Ball::~Ball()
{
	
}

//-------------------------------------------------------------

/*! Set Ball Radius : This will be used to set the balls in game radius. 
\Param One - float : The new radius for the ball. 
*/
void Ball::m_SetBallRadius(float radius)
{
	m_TempBall.setRadius(radius);

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
void Ball::m_UpdateBall()
{
	// Update Position. 

	m_TempBall.setPosition(m_Body->GetPosition().x - (m_TempBall.getGlobalBounds().width * HALF), m_Body->GetPosition().y + (m_TempBall.getGlobalBounds().height * HALF));

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

//-------------------------------------------------------------

/*! Assign Texture : This will assign a texture to the object's shape. 
\Param One - Texture : This will be the new texture for the shape. 
*/
void Ball::m_AssignTexture(sf::Texture &texture)
{
	m_TempBall.setTexture(&texture); 
}
