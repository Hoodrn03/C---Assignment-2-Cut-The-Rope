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
#include "Ball.h"
#include "EndPoint.h"

#include "TextureLoader.h"

class Level
{
	// Constructor 

public:

	Level();

	// Deconstructor 

public:

	~Level();

	// Data Members 

public:

	// This will be used to keep track of how many ropes are in the level. 
	int NumberOfRopes = 0;

private:

	sf::RectangleShape m_Background; 

	sf::RectangleShape m_MenuBackground;

	// Classes 
	
	// This will hold all of the textures in the game.
	TextureLoader m_TextureLoader; 

	// This will be used to hold all of the platfoms in this current level. 
	std::vector<Platform> v_Platforms;

	// This will hold all of the endpoints within the level. 
	std::vector<EndPoint> v_EndPoints; 

public:

	// This will hold all of the ropes within the current level.
	std::vector<Rope> v_Ropes;

	// This should hold all of the balls created for the level.
	std::vector<Ball> v_Balls;

	// Member Functions

public:

	// This will be used to set all of the level bounds based on the size of the display window. 
	void m_SetLevelBounds(float viewSizeX, float viewSizeY, b2World *world);

	// This will be the hardcoded first level.
	void m_LevelOne(b2World *world);

	// This will be used to draw all elements of the level. 
	void m_DrawLevel(sf::RenderWindow &window);

	void m_DrawBackground(sf::RenderWindow &window);

	void m_DrawMenuBackground(sf::RenderWindow &window);

	// This will be used to update all items in the level. 
	void m_UpdateLevel();
	
	// This will check all of the items for ones that need deleting. 
	void m_CheckForDeleteion(b2World *world);

	// This will be used to check the ropes for intersections. 
	sf::Vector2f m_CheckRope(int index, int segment);

	// This will be used to remove rope segements from the game. 
	void m_DeleteSegemnt(int index, int segment, b2World *world);
};