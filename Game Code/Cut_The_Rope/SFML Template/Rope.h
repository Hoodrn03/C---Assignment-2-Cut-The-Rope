/*!\file Rope.h
*
* This will be used to create a rope-like object in the game world using a bunch of connected 
* bodies, using revolute joints (Two per body; one to connect the top to the preveous body). 
*
* The ropes will be dynamic and be able to vary, for example a number of segments (length) can
* be specified. 
*
*/

#pragma once

#include "defs.h"

#include "PhysicsObject.h"

class Rope
{
	// Constructor 

public:

	Rope();

	// Deconstructor 

public:

	~Rope();

	// Data Members 


public:

	// This will be used to create the rope by connecting a bundle of bodies. 
	std::vector<b2Body*> v_RopeSegments;

	// This will hold all of the rope boxes for all of the rope segemnts. 
	std::vector<sf::RectangleShape> v_RopeBoxes;

private:

	// This will be used to hold all of the joints connecting all of the bodies. 
	std::vector<b2RevoluteJoint*> v_RopeConnections;

	// The base height for a rope segment. 
	float m_fHeight = 0.1f; 

	// The base width for a rope segment. 
	float m_fWidth = 0.5f; 

	// This will be used to check if the rope needs to be deleted. 
	bool m_BMarkedForDeleteion = false; 

	// Member Functions 

public:

	// This will be used to create a rope between two bodies. 
	void m_CreateRope(b2Body * firstBody, int iNumberOfSegments, b2Body * finalBody, b2World * world, b2Vec2 initialAnchor, b2Vec2 finalAnchor);

	// This will be used to draw the rope. 
	void m_DrawRope(sf::RenderWindow & window);

	// This will be used to update the position of the rope segments.
	void m_UpdateRope(); 

	// This will be used to assign a texture to the Ropes rope segmnets. 
	void m_AssignTexture(sf::Texture &texture);
};
