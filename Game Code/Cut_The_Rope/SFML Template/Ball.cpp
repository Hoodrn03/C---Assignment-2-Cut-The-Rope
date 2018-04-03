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
	m_TempBall.setRadius(2.0f); 

	m_TempBall.setPosition(25, 25);

	m_TempBall.setFillColor(sf::Color::Blue);

	m_TempBall.setOutlineColor(sf::Color::Magenta);

	m_TempBall.setOutlineThickness(0.5f);
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
