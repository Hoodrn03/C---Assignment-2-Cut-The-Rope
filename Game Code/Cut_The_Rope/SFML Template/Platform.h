/*!\file Platform.h
*
* This will be used to build a simple platform for the game. 
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

	// Data members 

private:

	// This is a temparary platform, later a texture and a sprite will be added into the game. 
	sf::RectangleShape m_TempPlatform;



	// Member Functions 

public:

	// This will be used to draw the platform. 
	void m_DrawPlatform(sf::RenderWindow &window);

	// This will be used to set the platfom's size. 
	void m_SetPlatformSize(float width, float height, bool dynamicPlatform);

	// This will be used to set the platform's position. 
	void m_SetPlatformPos(float newX, float newY, float newAngle);

	// This will update this platform.
	void m_UpdatePlatform(); 

};


