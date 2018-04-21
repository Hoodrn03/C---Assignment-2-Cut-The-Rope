/*!\file Ball.cpp
*
* This will house all of the function declarations for the class Ball.
*
*/

#include "PhysicsObject.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
PhysicsObject::PhysicsObject()
{
}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
PhysicsObject::~PhysicsObject()
{

}

//-------------------------------------------------------------

/*! Add To Physics World : This will allow for the object to interact with objects within the physics world.
\Param One - b2World : This function requires reference to the current physics world.
*/
void PhysicsObject::m_AddToPhysicsWorld(b2World *world)
{
	m_Body = world->CreateBody(&m_BodyDef);

	m_Body->CreateFixture(&m_FixtureDef);
}

//-------------------------------------------------------------

/*! Set Start Pos : This will set the starting position for the physics object. 
\Param One - float : the new x coordinate.
\Param Two - float : the new y coordinate.
\Param Three - float : the angle for the object. 
*/
void PhysicsObject::m_SetStartPos(float newX, float newY, float angle)
{
	m_BodyDef.position.Set(newX, newY);
	m_BodyDef.angle = (float)(angle * 3.14f / 180.f);
}

//-------------------------------------------------------------

/*! Create Ball Object : This will create a circular physics object. 
\Param One - float : The radius for the circle. 
\Param Two - bool : Whether the object is dynamic or static.
*/
void PhysicsObject::m_CreateBallObject(float radius, bool dynamic)
{
	m_DynamicBall.m_radius = radius;

	m_fRadius = radius;

	m_FixtureDef.shape = &m_DynamicBall;

	if (dynamic)
	{
		m_BodyDef.type = b2_dynamicBody;	
		
		m_FixtureDef.density = m_fDensity;
		m_FixtureDef.friction = m_fFriction;
		m_FixtureDef.restitution = m_fBouncyness;
	}


}

//-------------------------------------------------------------

/*! Create Box Object : This will create a rectangular physics object.
\Param One - float : The width of the physics object.
\Param Two - float : The height of the physics object.
\Param Three - bool : Whether the object is dynamic or static.
*/
void PhysicsObject::m_CreateBoxObject(float width, float height, bool dynamic)
{

	// Set Box Height and Width. 
	m_DynamicBox.SetAsBox(width, height);

	m_fHeight = height; 
	m_fWidth = width; 

	m_fRadius = 0.f;

	// Set Box Radius
	m_DynamicBox.m_radius = 0.f;

	// Assign the shape to the fixture. 
	m_FixtureDef.shape = &m_DynamicBox;

	if (dynamic)
	{
		// Set the body to be dynamic 

		m_BodyDef.type = b2_dynamicBody;

		// Assign the properties of the dynamic box. 
		m_FixtureDef.density = m_fDensity;
		m_FixtureDef.friction = m_fFriction;
		m_FixtureDef.restitution = m_fBouncyness;
	}

}

//-------------------------------------------------------------

/*! Set Properties : This will be used to set the properties for the physics object. 
\Param One - float : The new desity for the physics object. 
\Param Two - float : The new friction value for the physics object. 
\Param Three - float : The bouncyness value for the object. 
*/
void PhysicsObject::m_SetProperties(float density, float friction, float bouncyness)
{
	m_fDensity = density;
	m_fFriction = friction;
	m_fBouncyness = bouncyness;
}

//-------------------------------------------------------------

/*! Get Body : This will allow access to the body. 
\
*/
b2Body * PhysicsObject::m_GetBody()
{

	return m_Body;
}

//-------------------------------------------------------------

/*! Get : This will allow access to the objects values.
\
*/
values PhysicsObject::m_Get()
{
	// Set the values to return. 
	values v = {
		{ m_fHeight }, // Height 
		{ m_fWidth }, // Width 
		{ m_fRadius }, // Radius
		{ m_Body->GetPosition().x }, // X 
		{ m_Body->GetPosition().y }	// Y
	};

	// Return the set of values. 
	return v;
}


