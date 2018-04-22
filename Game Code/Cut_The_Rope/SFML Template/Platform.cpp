/*!\file Platform.cpp
*
* This will house all of the function declarations for the class Platform.
*
*/

#include "Platform.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
Platform::Platform()
{

}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
Platform::~Platform()
{

}

void Platform::m_DrawPlatform(sf::RenderWindow & window)
{
	window.draw(m_TempPlatform); 
}

void Platform::m_CreatePlatform(float width, float height)
{
	m_TempPlatform.setSize(sf::Vector2f(width, height));

	m_TempPlatform.setOrigin(width * HALF, height * HALF);
}

void Platform::m_UpdatePlatform()
{
	
	m_TempPlatform.setPosition(m_Get().x, m_Get().y + m_Get().height * HALF);

	m_TempPlatform.setRotation(m_GetBody()->GetAngle() * RADTODEG); 
}
