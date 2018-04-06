/*!\file Level.h
*
* This will house all of the level elements for the game. There will be numerous different 
* obsticales within the game, this class will control the placement and management of each of 
* those objects. This class will also maintain the level's background and the bounds around the 
* window. 
*
*/

#pragma once

#include "defs.h"

#include "Platform.h"

class Level
{
	// Constructor 

public:

	Level();

	// Deconstructor 

public:

	~Level();

	// Data Members 

private:

	std::vector<sf::RectangleShape> v_LevelBounds;

	// Classes 
	
	std::vector<Platform> v_Platforms;

	// Member Functions

public:

	void m_SetLevelBounds(float viewSizeX, float viewSizeYz);

	void m_DrawLevelBounds(sf::RenderWindow &window);

};