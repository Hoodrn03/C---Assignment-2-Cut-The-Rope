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

	// This is a temparary platform, later a texture and a sprite will be added into the game. 
	sf::RectangleShape m_TempPlatform;

	b2BodyDef m_PlatformBodyDef; 

	b2FixtureDef m_PlatformFixtureDef; 

	b2PolygonShape m_PlatformBox;

	b2Body *m_PlatformBody;

	// Member Functions 

public:

	// This will be used to draw the platform. 
	void m_DrawPlatform(sf::RenderWindow &window);

	// This will be used to set the platfom's size. 
	void m_SetPlatformSize(float width, float height);

	// This will be used to set the platform's position. 
	void m_SetPlatformPos(float newX, float newY);

	void m_SetPlatformRotation(float angle);

	// This will be used to add this platform into the physics world.
	void m_AddToPhysicsWorld(b2World *world);
};
