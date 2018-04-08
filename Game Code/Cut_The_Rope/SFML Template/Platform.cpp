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

	m_PlatformBox.SetAsBox(width, height);

	std::cout << "Platform Created" << std::endl;
}

//-------------------------------------------------------------

/*! Set Platform Pos : This will be used to easily set the platfoms possition in the game world.
\Param One - Float : The X coordinate for the platform.
\Param Two - Float : The Y coordinate for the platform.
*/
void Platform::m_SetPlatformPos(float newX, float newY)
{

	m_PlatformBodyDef.position.Set(newX, newY);

	m_TempPlatform.setPosition(m_PlatformBodyDef.position.x, m_PlatformBodyDef.position.y);
	
	std::cout << "Platform Placed" << std::endl;

}

//-------------------------------------------------------------

/*! SetPlatform Rotation : This will be used to angle the platform. 
\Param One - float : The new angle for the platform. 
*/
void Platform::m_SetPlatformRotation(float newAngle)
{
	m_PlatformBodyDef.angle = (float)(newAngle * 3.14f / 180.f); 

	m_TempPlatform.setRotation(newAngle);
}

//-------------------------------------------------------------

/*! Add To Physics World : This will allow for the platform to interact with objects within the physics world. 
\Param One - b2World : This function requires reference to the current physics world. 
*/
void Platform::m_AddToPhysicsWorld(b2World *world)
{
	m_PlatformFixtureDef.shape = &m_PlatformBox; 

	m_PlatformBody = world->CreateBody(&m_PlatformBodyDef);

	m_PlatformBody->CreateFixture(&m_PlatformFixtureDef);

	std::cout << "Platform Added to Physics World" << std::endl;
}
