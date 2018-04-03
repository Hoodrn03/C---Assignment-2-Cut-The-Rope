/*!\file Physics.cpp
*
* This will house all of the function declarations for the class Physics.
*
*/

#include "Platform.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
Platform::Platform()
{

	m_TempPlatform.setFillColor(sf::Color::White);
	m_TempPlatform.setOutlineColor(sf::Color::Blue);
	m_TempPlatform.setOutlineThickness(0.5f);

}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
Platform::~Platform()
{
	
}

//-------------------------------------------------------------

/*! Draw Platform : This will be used to draw this platfrom into the game world. 
\Param One - Render Window : This is for the main game window to allow for the platform to be drawn into the game world. 
*/
void Platform::m_DrawPlatform(sf::RenderWindow &window)
{
	window.draw(m_TempPlatform);
}

//-------------------------------------------------------------

/*! Set Platform Size : This will be used to easily set the platfoms size. 
\Param One - Float : The width of the platform.
\Param Two - Float : The height of the platform. 
*/
void Platform::m_SetPlatformSize(float width, float height)
{
	m_TempPlatform.setSize(sf::Vector2f(width, height));
}

//-------------------------------------------------------------

/*! Set Platform Pos : This will be used to easily set the platfoms possition in the game world.
\Param One - Float : The X coordinate for the platform.
\Param Two - Float : The Y coordinate for the platform.
*/
void Platform::m_SetPlatformPos(float newX, float newY)
{
	m_TempPlatform.setPosition(newX, newY);
}
