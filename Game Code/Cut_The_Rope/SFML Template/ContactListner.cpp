/*!\file ContactListner.cpp
*
* This will house all of the function declarations for the class ContactListner.
*
*/

#include "ContactListner.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
ContactListner::ContactListner()
{
}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
ContactListner::~ContactListner()
{
}

void ContactListner::BeginContact(b2Contact * contact)
{
	PhysicsObject * l_EndPointEntity; 
	PhysicsObject * l_BallEntity; 

	if (m_GetBallAndEndPoint(contact, l_BallEntity, l_EndPointEntity))
	{		
		std::cout << "Curret Tag : " << l_BallEntity->m_GetTag() << std::endl;

		std::cout << "EndPoint Tag : " << l_EndPointEntity->m_GetTag() << std::endl;

		std::cout << "BALL ENTITY : " << BALL_ENTITY << std::endl;

		if (l_BallEntity->m_GetTag() == BALL_ENTITY)
		{
			std::cout << "Ball Collided" << std::endl;
		}
	}
}

void ContactListner::EndContact(b2Contact * contact)
{

}

bool ContactListner::m_GetBallAndEndPoint(b2Contact * contact, PhysicsObject*& ballEntity, PhysicsObject*& EndPointEntity)
{
	//--------------------------------------------------------
	//						Locals 
	//--------------------------------------------------------

	b2Fixture* l_FixtureA = contact->GetFixtureA(); 
	b2Fixture* l_FixtureB = contact->GetFixtureB();

	void* l_BodyUserData;

	PhysicsObject* l_EntityB;
	PhysicsObject* l_EntityA;

	// Ensure There is Only One Sensor

	bool l_SensorA = l_FixtureA->IsSensor(); 
	bool l_SensorB = l_FixtureB->IsSensor();

	if (!(l_SensorA ^ l_SensorB))
	{
		return false;
	}

	l_BodyUserData = l_FixtureA->GetBody()->GetUserData();

	// Check to see if there is any data to get. 

	if (l_BodyUserData)
	{
		l_EntityA = static_cast<PhysicsObject*>(l_BodyUserData);
	}
	else
	{
		return false; 
	}

	l_BodyUserData = l_FixtureB->GetBody()->GetUserData();

	if (l_BodyUserData)
	{
		l_EntityB = static_cast<PhysicsObject*>(l_BodyUserData);
	}
	else
	{
		return false;
	}


	// The first item must be the endpoint.  
	if (l_SensorA)
	{
		EndPointEntity = l_EntityA; 

		ballEntity = l_EntityB;

	}
	else // The endpoint must be the second item. 
	{
		EndPointEntity = l_EntityB;

		ballEntity = l_EntityA;
	}

	return true;
}
