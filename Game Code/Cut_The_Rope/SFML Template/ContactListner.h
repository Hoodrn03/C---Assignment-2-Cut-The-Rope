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

	// Member Functions 

public:

	void BeginContact(b2Contact* contact);

	void EndContact(b2Contact* contact); 

	bool m_GetBallAndEndPoint(b2Contact* contact, PhysicsObject*& ballEntity, PhysicsObject*& EndPointEntity);
};