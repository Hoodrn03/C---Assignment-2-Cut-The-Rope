/*!\file Platform.h
*
* This class will allow for the simple creation of either a static or dynamic platform in the game. 
* This will hold methods for creating the new platform and thus the integration between the SFML shape 
* and the box2D body held within the inherited PhysicsObject class. 
*
*/

#pragma once

#include "defs.h"

#include "PhysicsObject.h"

class Platform : public PhysicsObject
{
	// Constructor

public:

	Platform();

	// Deconstructor 

public:

	~Platform();

	// Data Members 

private:

	sf::RectangleShape m_TempPlatform; 

	// Member Functions

public:

	void m_DrawPlatform(sf::RenderWindow &window);

	void m_CreatePlatform(float width, float height);

	void m_UpdatePlatform(); 

};
