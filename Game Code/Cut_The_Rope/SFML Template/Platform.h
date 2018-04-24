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

	//The temp shape used for displaying the platform without the use of a texture or sprite. 
	sf::RectangleShape m_TempPlatform; 

	// Member Functions

public:

	// This will be used to draw the platform onto the window. 
	void m_DrawPlatform(sf::RenderWindow &window);

	// This will be used to create a platform ready to be displayed. 
	void m_CreatePlatform(float width, float height);

	// This will update the platforms current position. 
	void m_UpdatePlatform(); 

	// This will allow for the platform to be coloured. 
	void m_SetColour(float r, float g, float b); 

};
