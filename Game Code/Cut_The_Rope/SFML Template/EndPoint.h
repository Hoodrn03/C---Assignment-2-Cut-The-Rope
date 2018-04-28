/*!\file EndPoint.h
*
* This will be used to create an end point for the game. Once an object with the tag ball 
* comes into contact with the endpoint object the level will finish. 
*
*/

#pragma once

#include "defs.h"

#include "PhysicsObject.h"

class EndPoint : public PhysicsObject
{
	// Constructor 

public:

	EndPoint();


	// Deconstructor 

public:

	~EndPoint();


	// Data Members 

private:

	sf::RectangleShape m_TempEndPoint; 


	// Member Functions 

public:

	void m_DrawEndPoint(sf::RenderWindow & window);

	void m_CreateEndPoint(float width, float height);

	void m_UpdateEndPoint();

	void m_SetColour(float r, float g, float b);
};