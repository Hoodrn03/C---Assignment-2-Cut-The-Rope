/*!\file Level.cpp
*
* This will house all of the function declarations for the class Level.
*
*/

#include "Level.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
Level::Level()
{

}

//-------------------------------------------------------------

/*! Deconstructor 
\
*/
Level::~Level()
{

}

//-------------------------------------------------------------

/*! Set Level Bounds : This will be used to set the bounds for the game window, constraining all of the game objects to the widndow. 
\Param One - Float : This is the width of the view I am using to display the game, to ensure the bounds are only within the current display.
\Param Two - Float : This is the height of the view I am using to display the game, to ensure the bounds are only within the current display.
\Param Three - b2World : This will allow for the objects to be added into the physics world. 
*/
void Level::m_SetLevelBounds(float viewSizeX, float viewSizeY, b2World *world)
{
	// Locals : 

	Platform * tempPlatform; 

	// Set the base height and width for the platfoms. Get the correct size then multiply by 0.5f to get the half extents.
	float fBaseWidth = ((viewSizeX * 0.05f) * 0.5f), fBaseHeight = ((viewSizeY * 0.05f) * 0.5f); 

	// Top Bounds 

	tempPlatform = new Platform();

	tempPlatform->m_SetPlatformSize(viewSizeX, fBaseHeight, false);

	tempPlatform->m_SetPlatformPos(0.0f, 0.0f, 0.f);

	tempPlatform->m_AddToPhysicsWorld(world);

	v_Platforms.push_back(*tempPlatform);

	// Bottom Bounds 

	tempPlatform = new Platform();

	tempPlatform->m_SetPlatformSize(viewSizeX, fBaseHeight, false);

	tempPlatform->m_SetPlatformPos(0.0f, (viewSizeY - fBaseHeight), 0.f);

	tempPlatform->m_AddToPhysicsWorld(world);

	v_Platforms.push_back(*tempPlatform);

	// Left Bounds

	tempPlatform = new Platform();

	tempPlatform->m_SetPlatformSize(fBaseWidth, viewSizeY, false);

	tempPlatform->m_SetPlatformPos(0.0f, 0.0f, 0.f);

	tempPlatform->m_AddToPhysicsWorld(world);

	v_Platforms.push_back(*tempPlatform);

	// Right Bounds 

	tempPlatform = new Platform();

	tempPlatform->m_SetPlatformSize(fBaseWidth, viewSizeY, false);

	tempPlatform->m_SetPlatformPos((viewSizeX - fBaseWidth), 0.0f, 0.f);

	tempPlatform->m_AddToPhysicsWorld(world);

	v_Platforms.push_back(*tempPlatform);

	// Angled platform.  

	tempPlatform = new Platform();

	tempPlatform->m_SetProperties(1.f, 0.3f, 0.1f);

	tempPlatform->m_SetPlatformPos((viewSizeX * 0.1f), (viewSizeY * 0.6f), 15.f);

	tempPlatform->m_SetPlatformSize(2.0f, (fBaseHeight * 0.5f), true);

	tempPlatform->m_AddToPhysicsWorld(world);

	v_Platforms.push_back(*tempPlatform);

	// Delete temp Pointer

	delete tempPlatform;

}

//-------------------------------------------------------------

/*! Draw Level Bounds : This will draw all of the level bounds into the game. 
\Param One - Render Window : This will be the main game window for the game, allowing for the sprite to be drawn.
*/
void Level::m_DrawLevel(sf::RenderWindow &window)
{
	if (v_Platforms.size() > 0)
	{
		for (unsigned int i = 0; i < v_Platforms.size(); i++)
		{
			v_Platforms.at(i).m_DrawPlatform(window);
		}
	}
	
}

//-------------------------------------------------------------

/*! Update Level Items : This will be used to update all of the level items in the current level. 
\
*/
void Level::m_UpdateLevelItems()
{
	if (v_Platforms.size() > 0)
	{
		for (unsigned int i = 0; i < v_Platforms.size(); i++)
		{
			v_Platforms.at(i).m_UpdatePlatform();
		}
	}
	
}
