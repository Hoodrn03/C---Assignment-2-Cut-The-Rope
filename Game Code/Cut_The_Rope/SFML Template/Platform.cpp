/*!\file Platform.cpp
*
* This will house all of the function declarations for the class Platfom.
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
void Platform::m_SetPlatformSize(float width, float height, bool dynamicPlatform)
{
	m_TempPlatform.setSize(sf::Vector2f(width, height));

	m_CreateBoxObject(width, height, dynamicPlatform);
}

//-------------------------------------------------------------

/*! Set Platform Pos : This will be used to easily set the platfoms possition in the game world.
\Param One - Float : The X coordinate for the platform.
\Param Two - Float : The Y coordinate for the platform.
\Param Three - Float : The new angle for the platform.
*/
void Platform::m_SetPlatformPos(float newX, float newY, float newAngle)
{

	m_SetStartPos(newX, newY, newAngle);

	m_TempPlatform.setPosition(newX, newY);
	
	m_TempPlatform.setRotation(newAngle);
}

//-------------------------------------------------------------

/*! Update Platform : This will be used to update the current possition of the platform. 
\
*/
void Platform::m_UpdatePlatform()
{

	// Update Position.

	m_TempPlatform.setPosition(m_Body->GetPosition().x, m_Body->GetPosition().y);

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

	m_TempPlatform.setRotation(angle);
	
}





