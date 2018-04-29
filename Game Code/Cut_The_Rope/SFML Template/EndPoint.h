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

	// The temporary shape for the end point. 
	sf::RectangleShape m_TempEndPoint; 


	// Member Functions 

public:

	// This will be used to draw the end point. 
	void m_DrawEndPoint(sf::RenderWindow & window);

	// This will be used to create the end point. 
	void m_CreateEndPoint(float width, float height);

	// This will be used to update the position of the end point. 
	void m_UpdateEndPoint();

	// This will be used to set the colour of the end point. 
	void m_SetColour(float r, float g, float b);

	// This will be used to assign a texture to the EndPoints Rectangle shape. 
	void m_AssignTexture(sf::Texture &texture);

};