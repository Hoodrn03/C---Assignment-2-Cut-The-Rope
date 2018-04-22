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
	// Base Values 

	// Get Base Values 
	float fBaseWidth = 0.5f, fBaseHeight = 0.5f;

	Platform temp; 

	// Bottom Platform

	temp.m_SetStartAngle(0);

	temp.m_CreateBoxObject(viewSizeX, fBaseHeight, false, world, (viewSizeX * HALF), viewSizeY - (fBaseHeight * HALF));

	temp.m_CreatePlatform(viewSizeX, fBaseHeight); 

	v_Platforms.push_back(temp);

	// Top Platform

	temp.m_SetStartAngle(0);

	temp.m_CreateBoxObject(viewSizeX, fBaseHeight, false, world, (viewSizeX * HALF), 0 - (fBaseHeight * HALF));

	temp.m_CreatePlatform(viewSizeX, fBaseHeight);

	v_Platforms.push_back(temp);

	// Left Platform

	temp.m_SetStartAngle(90);

	temp.m_CreateBoxObject(viewSizeY, fBaseWidth, false, world, (fBaseWidth * HALF), (viewSizeY * HALF));

	temp.m_CreatePlatform(viewSizeY, fBaseWidth);

	v_Platforms.push_back(temp);

	// Right Platform

	temp.m_SetStartAngle(90);

	temp.m_CreateBoxObject(viewSizeY, fBaseWidth, false, world, viewSizeX - (fBaseWidth * HALF), 0 + (viewSizeY * HALF));

	temp.m_CreatePlatform(viewSizeY, fBaseWidth);

	v_Platforms.push_back(temp);


}

//-------------------------------------------------------------

/*! Level One : This will hold the creation of the very first level, the test level (Codename Level 0). 
\Param One - b2World : This will allow for the objects to be added into the physics world.
*/
void Level::m_LevelOne(b2World * world)
{


}

//-------------------------------------------------------------

/*! Draw Level Bounds : This will draw all of the level bounds into the game. 
\Param One - Render Window : This will be the main game window for the game, allowing for the sprite to be drawn.
*/
void Level::m_DrawLevel(sf::RenderWindow &window)
{
	// Draw Ropes.

	if (v_Ropes.size() > 0)
	{
		for (unsigned int i = 0; i < v_Ropes.size(); i++)
		{
			v_Ropes.at(i).m_DrawRope(window);
		}
	}

	// Draw Level Platforms. 

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
void Level::m_UpdateLevel()
{

	// Update Platforms. 

	if (v_Platforms.size() > 0)
	{
		for (unsigned int i = 0; i < v_Platforms.size(); i++)
		{
			v_Platforms.at(i).m_UpdatePlatform();
		}
	}

	// Update Ropes.

	if (v_Ropes.size() > 0)
	{
		for (unsigned int i = 0; i < v_Ropes.size(); i++)
		{
			v_Ropes.at(i).m_UpdateRope();
		}
	}
	
}
