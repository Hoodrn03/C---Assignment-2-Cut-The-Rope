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

	// Member Functions 

public: 

	// This will add the current definition of the body to the physics world. 
	void m_AddToPhysicsWorld(b2World *world);

	// This will be used to set the start pos for the object. 
	void m_SetStartPos(float newX, float newY, float angle);

	// This will be used to create a circular object. 
	void m_CreateBallObject(float radius, bool dynamic);

	// This will  be used to create a rectangular object.
	void m_CreateBoxObject(float width, float height, bool dynamic);

	// This will be used to set the objects properties. 
	void m_SetProperties(float density, float friction, float bouncyness);

	// This will allow access to the body of the physics object. 
	b2Body *m_GetBody();

	// THis will allow for easy access to the objects values, (Height, Width, Radius, X and Y). 
	values m_Get();
};