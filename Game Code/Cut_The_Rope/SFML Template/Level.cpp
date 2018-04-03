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
*/
void Level::m_SetLevelBounds(float viewSizeX, float viewSizeY)
{
	std::unique_ptr<Platform> tempPlatform; 

	float fBaseWidth = 3, fBaseHeight = 3; 

	// Top Bounds 

	tempPlatform.reset(new Platform());

	tempPlatform->m_SetPlatformSize(viewSizeX, fBaseHeight);

	tempPlatform->m_SetPlatformPos(0.0f, 0.0f);

	v_Platforms.push_back(*tempPlatform);

	// Bottom Bounds 

	tempPlatform.reset(new Platform());

	tempPlatform->m_SetPlatformSize(viewSizeX, fBaseHeight);

	tempPlatform->m_SetPlatformPos(0.0f, (viewSizeY - fBaseHeight));

	v_Platforms.push_back(*tempPlatform);

	// Left Bounds

	tempPlatform.reset(new Platform());

	tempPlatform->m_SetPlatformSize(fBaseWidth, viewSizeY);

	tempPlatform->m_SetPlatformPos(0.0f, 0.0f);

	v_Platforms.push_back(*tempPlatform);

	// Right Bounds 

	tempPlatform.reset(new Platform());

	tempPlatform->m_SetPlatformSize(fBaseWidth, viewSizeY);

	tempPlatform->m_SetPlatformPos((viewSizeX - fBaseWidth), 0.0f);

	v_Platforms.push_back(*tempPlatform);

}

//-------------------------------------------------------------

/*! Draw Level Bounds : This will draw all of the level bounds into the game. 
\Param One - Render Window : This will be the main game window for the game, allowing for the sprite to be drawn.
*/
void Level::m_DrawLevelBounds(sf::RenderWindow &window)
{
	if (v_Platforms.size() > 0)
	{
		for (unsigned int i = 0; i < v_Platforms.size(); i++)
		{
			v_Platforms.at(i).m_DrawPlatform(window);
		}
	}
}
