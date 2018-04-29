/*!\file PhysicsObject.h
*
* This class will be used to hold all of the physics items within the game. This
* class will be th baseline for all of the physics objects in the game. 
*
*/

#pragma once

#include "defs.h"

//! Values : This will be used to get the values accociated with the physics object. 
struct values
{
	// Height value. 
	float height;

	// Width value.
	float width;

	// Radius value.
	float radius; 

	// X coordinate. 
	float x;

	// Y coordinate.
	float y;

	// This tag for the object.
	tag thisTag; 
};


//! Physics Object : This will be used to enable an object to have physics within the game. 
class PhysicsObject
{
	// Constructor

public:

	PhysicsObject();

	// Deconstructor 

public:

	~PhysicsObject();

	// Data Members 

public:

	// The tag accociated with the object. 
	tag m_Tag = NULL_VALUE;

protected:

	// The dencity for the object.
	float m_fDensity = 1.0f;

	// The friction for the object. 
	float m_fFriction = 0.3f;

	// The value for the object bouncyness. 
	float m_fBouncyness = 0.5f;

	// The definition of the physics objects body. 
	b2BodyDef m_BodyDef;

	// The fixture definition for the physics object. 
	b2FixtureDef m_FixtureDef;
	
	// The body used to simulate physics. 
	b2Body *m_Body = nullptr;

	// Used to make the physics object a ball (or Circle).
	b2CircleShape m_DynamicBall;

	// Used to make the pysics object a box (or Square). 
	b2PolygonShape m_DynamicBox;

	// The height of the object. 
	float m_fHeight; 

	// The width of the object. 
	float m_fWidth;

	// The radius for the object.
	float m_fRadius; 

	// Initial Coordinates for the object. 
	float m_fX, m_fY; 

	// This will check to see if the object needs to be deleted. 
	bool m_MarkedForDeleteion = false; 

	// Member Functions 

public: 

	// This will be used to allow for the assignment of a new tag. 
	void m_SetTag(tag newTag);

	// This will allow access to the objects current tag. 
	tag m_GetTag();

	// This will be used to set the start pos for the object. 
	void m_SetStartAngle(float angle);

	// This will be used to create a circular object. 
	void m_CreateBallObject(float radius, bool dynamic, b2World *world, float fXPos, float fYPos);

	// This will  be used to create a rectangular object.
	void m_CreateBoxObject(float width, float height, bool dynamic, b2World *world, float fXPos, float fYPos);

	// This will be used to set the objects properties. 
	void m_SetProperties(float density, float friction, float bouncyness);

	// This will allow access to the body of the physics object. 
	b2Body *m_GetBody();

	// This will allow for easy access to the objects values, (Height, Width, Radius, X and Y). 
	values m_Get();

	// This will be used to determine whether the object needs to be deleted. 
	void m_MarkForDeletion(); 

	// This will be used to check if any items need to be deteled at the end of the frame. 
	bool m_CheckForDeletion(b2World * world);

	// This will allow for the easy addition of a sensor to an existing body. 
	void m_AddSensor(b2CircleShape newShape); 

	// This will allow for the user data to be assigned to the b2Body. 
	void m_SetData(void* data);
};
