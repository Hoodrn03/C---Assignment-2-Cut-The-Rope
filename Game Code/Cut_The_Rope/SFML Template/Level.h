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


	// Classes 
	
	// This will be used to hold all of the platfoms in this current level. 
	std::vector<Platform> v_Platforms;

	// Member Functions

public:

	// This will be used to set all of the level bounds based on the size of the display window. 
	void m_SetLevelBounds(float viewSizeX, float viewSizeYz);

	// This will be used to draw all elements of the level. 
	void m_DrawLevelBounds(sf::RenderWindow &window);

};