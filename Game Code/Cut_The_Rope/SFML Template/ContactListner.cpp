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

//-------------------------------------------------------------

/*! Begin Contact : This will be called when an item gets within the sensors range. Psedo collision. 
\Param One - b2Contact : This will be automatically passed in from the b2World. 
*/
void ContactListner::BeginContact(b2Contact * contact)
{
	PhysicsObject * l_EndPointEntity; 
	PhysicsObject * l_BallEntity; 

	if (m_GetBallAndEndPoint(contact, l_BallEntity, l_EndPointEntity))
	{
		if (l_BallEntity->m_GetTag() == BALL_ENTITY)
		{

			m_bBallReachedZone = true; 
		}

		l_BallEntity->m_SetTag(BALL_ENTITY);

	}
}

//-------------------------------------------------------------

/*! End Contact : This will be called when an item gets within the sensors range. Psedo collision.
\Param One - b2Contact : This will be automatically passed in from the b2World.
*/
void ContactListner::EndContact(b2Contact * contact)
{

}

//-------------------------------------------------------------

/*! Get Ball And EndPoint : This will be used to evaluate the collision between the two collided bodies.  
\Param One - b2Collision : This will hold the information for both of the bodies involved with the collision. 
\Param Two - PhysicsObject : This is a pointer reference to a temporary object which will allow for evaluation outside of this method if both bodies are correct. 
\Param Three - PhysicsObject : This is a pointer reference to a temporary object which will allow for evaluation outside of this method if both bodies are correct. 
*/
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
		l_EntityA = (PhysicsObject*)l_BodyUserData;
	}
	else
	{
		return false; 
	}

	l_BodyUserData = l_FixtureB->GetBody()->GetUserData();

	if (l_BodyUserData)
	{
		l_EntityB = (PhysicsObject*)l_BodyUserData;
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

//-------------------------------------------------------------

/*! Game End : This will be used to check the value of ballReachedZone to determine if the game should end.
\
*/
bool ContactListner::m_GameEnd()
{

	if (m_bBallReachedZone)
	{
		return true; 
	}

	return false;
}
