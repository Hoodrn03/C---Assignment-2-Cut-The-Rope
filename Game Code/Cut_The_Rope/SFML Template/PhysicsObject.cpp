/*!\file PhysicsObject.cpp
*
* This will house all of the function declarations for the class PhysicsObject.
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

/*! Set Tag : This will be used to set the tag for the physics object. 
\Param One - tag : This is an enum with a variety of different tags which can be used. 
*/
void PhysicsObject::m_SetTag(tag newTag)
{
	m_Tag = newTag;
}

//-------------------------------------------------------------

/*! Get Tag : This will be used to get the tag accociated with this object. 
\
*/
tag PhysicsObject::m_GetTag()
{

	return m_Tag;
}

//-------------------------------------------------------------

/*! Set Start Pos : This will set the starting position for the physics object.
\Param One - float : the new x coordinate.
\Param Two - float : the new y coordinate.
\Param Three - float : the angle for the object. 
*/
void PhysicsObject::m_SetStartAngle(float angle)
{

	m_BodyDef.angle = (float)(angle * DEGTORAD);
}

//-------------------------------------------------------------

/*! Create Ball Object : This will create a circular physics object. 
\Param One - float : The radius for the circle. 
\Param Two - bool : Whether the object is dynamic or static.
*/
void PhysicsObject::m_CreateBallObject(float radius, bool dynamic, b2World *world, float fXPos, float fYPos)
{
	m_DynamicBall.m_radius = radius;

	m_fRadius = radius;

	m_BodyDef.position.Set(fXPos, fYPos);

	m_FixtureDef.shape = &m_DynamicBall;

	if (dynamic)
	{
		m_BodyDef.type = b2_dynamicBody;	
		
		m_FixtureDef.density = m_fDensity;
		m_FixtureDef.friction = m_fFriction;
		m_FixtureDef.restitution = m_fBouncyness;
	}


	m_Body = world->CreateBody(&m_BodyDef);
	m_Body->CreateFixture(&m_FixtureDef);
}

//-------------------------------------------------------------

/*! Create Box Object : This will create a rectangular physics object.
\Param One - float : The width of the physics object.
\Param Two - float : The height of the physics object.
\Param Three - bool : Whether the object is dynamic or static.
*/
void PhysicsObject::m_CreateBoxObject(float width, float height, bool dynamic, b2World *world, float fXPos, float fYPos)
{

	// Scale Height and width values. 
	m_fWidth = width;
	m_fHeight = height;

	// Set Box Height and Width. 
	m_DynamicBox.SetAsBox(width * HALF, height * HALF);

	m_BodyDef.position.Set(fXPos, fYPos);

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

	m_Body = world->CreateBody(&m_BodyDef);
	m_Body->CreateFixture(&m_FixtureDef);
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

	values v; 

	if (m_Body != nullptr)
	{
		// Set the values to return. 
		v = {
			{ m_fHeight },					// Height 
			{ m_fWidth },					// Width 
			{ m_fRadius },					// Radius
			{ m_Body->GetPosition().x },	// X 
			{ m_Body->GetPosition().y },	// Y
			{ m_Tag }						// The tag for the object. 
		};
	}
	else
	{
		// Unable to get values to return. 
		v = {
			{ NULL },	// Height 
			{ NULL },	// Width 
			{ NULL },	// Radius
			{ NULL },	// X 
			{ NULL },	// Y
			{ NULL_VALUE }
		};
	}

	// Return the set of values. 
	return v;
}

//-------------------------------------------------------------

/*! Mark For Deletion : This will be used set a body to be deleted at the end of the frame. 
\
*/
void PhysicsObject::m_MarkForDeletion()
{
	m_MarkedForDeleteion = true; 
}

//-------------------------------------------------------------

/*! Check For Deletion : This will be used to remove the body from the world. 
\Param One - b2World : The world the body was apart of. 
*/
bool PhysicsObject::m_CheckForDeletion(b2World * world)
{
	if (m_MarkedForDeleteion)
	{
		world->DestroyBody(m_GetBody());

		return true;
	}

	return false; 
}

//-------------------------------------------------------------

/*! Add Sensor : This will be used to add a sensor to a body. 
\Param One - b2CircleShape : This is the size of the circular radius sensor. 
*/
void PhysicsObject::m_AddSensor(b2CircleShape newShape)
{
	b2FixtureDef newSensor; 

	newSensor.shape = &newShape; 

	newSensor.isSensor = true; 

	newSensor.filter.categoryBits = SENSOR_ENTITY; 

	newSensor.filter.maskBits = BALL_ENTITY; 

	m_Body->CreateFixture(&newSensor); 
}

void PhysicsObject::m_SetData(void* data)
{
	m_Body->SetUserData(data);
}


