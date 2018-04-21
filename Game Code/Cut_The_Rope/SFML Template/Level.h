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
#include "Rope.h"

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

	std::vector<Rope> v_Ropes;
	
	// Member Functions

public:

	// This will be used to set all of the level bounds based on the size of the display window. 
	void m_SetLevelBounds(float viewSizeX, float viewSizeY, b2World *world);

	void m_SetRopes(b2World * world);

	// This will be used to draw all elements of the level. 
	void m_DrawLevel(sf::RenderWindow &window);

	// This will be used to update all items in the level. 
	void m_UpdateLevel();

};