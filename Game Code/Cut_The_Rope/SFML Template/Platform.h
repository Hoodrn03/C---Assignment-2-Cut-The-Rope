/*!\file Platform.h
*
* This will be used to build a simple platform for the game. 
*
*/

#pragma once

#include "defs.h"

class Platform
{
	// Constructor 

public:

	Platform();

	// Deconstructor 

public:

	~Platform();

	// Data members 

private:

	sf::RectangleShape m_TempPlatform;

	// Member Functions 

public:

	void m_DrawPlatform(sf::RenderWindow &window);

	void m_SetPlatformSize(float width, float height);

	void m_SetPlatformPos(float newX, float newY);

};
