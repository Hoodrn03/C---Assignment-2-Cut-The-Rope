/*!\file ContactListner.h
*
* This class will be used to monitor the sensor collisions in the game. 
*
*/

#pragma once

#include "defs.h"

#include "PhysicsObject.h"

class ContactListner : public b2ContactListener
{
	// Constructor 

public:

	ContactListner();

	// Deconstructor 

public:

	~ContactListner();

	// Data Members 

private:
	
	// This will be used to check if the ball has reached the end zone. 

	bool m_bBallReachedZone = false; 

	// Member Functions 

public:

	// This will be used to check when something enters contact range.
	void BeginContact(b2Contact* contact);

	// This will be used to check when something exits contact range.
	void EndContact(b2Contact* contact); 

	// This will be used to check for the contact between the ball and the endpoint.
	bool m_GetBallAndEndPoint(b2Contact* contact, PhysicsObject*& ballEntity, PhysicsObject*& EndPointEntity);

	// This will be used to check the to see if the ball has reached the endpoint. 
	bool m_GameEnd(); 
};