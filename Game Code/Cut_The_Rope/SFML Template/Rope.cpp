/*!\file Rope.cpp
*
* This will house all of the function declarations for the class Rope.
*
*/

#include "Rope.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
Rope::Rope()
{
}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
Rope::~Rope()
{
}

//-------------------------------------------------------------

/*! Create Rope : This will be used to create a rope between two objects. 
\Param One - b2Body : This will be the first body in the chain. 
\Param Two - float : This will be the number of segments to add, thus the size of the rope. 
\Param Three - b2Body : The last body the rope connects to. 
\Param Four - b2World : The physics world the items will be added to. 
*/
void Rope::m_CreateRope(b2Body * firstBody, int iNumberOfSegments, b2Body * finalBody, b2World * world)
{
	
	// Create bases for the rope segments. 

		// Create Body Def for the segments. 
	b2BodyDef bodyDef; 

	bodyDef.type = b2_dynamicBody;

	bodyDef.position.Set(2.f, 3.f);

		// Create a Fixture Def for the segments. 
	b2FixtureDef fixtureDef;

	fixtureDef.density = 1;

		// Create the shape for the rope. 
	b2PolygonShape polygonShape; 

	polygonShape.SetAsBox(0.5f, 0.15f); 

	polygonShape.m_radius = 0.f;

	fixtureDef.shape = &polygonShape;

	// Assign body to be the first body (A static object in the level). 
	b2Body * preveousBody = firstBody;

	// Create the joint. 

	b2RevoluteJointDef revoluteJointDef;

	revoluteJointDef.collideConnected = false;

		// Set the anchor points for the initial two bodies. 
	revoluteJointDef.localAnchorA.Set(2.f, 0);
	revoluteJointDef.localAnchorB.Set(-0.375f, 0);

	v_RopeSegments.push_back(preveousBody);

	// Create SFML rectangle object. 
	sf::RectangleShape box;

	box.setSize(sf::Vector2f(1.f, 0.3f));

	box.setOrigin(0.5f, 0.15f);

	box.setFillColor(sf::Color::Magenta);


	// Create n number of rope segments.
	for (int i = 0; i <= iNumberOfSegments; i++)
	{
		// New bofy for the rope. 

		b2Body * newBody = world->CreateBody(&bodyDef);
		newBody->CreateFixture(&fixtureDef);

		v_RopeSegments.push_back(newBody);

		// Joint Createion. 

		revoluteJointDef.bodyA = preveousBody;
		revoluteJointDef.bodyB = newBody;

		world->CreateJoint(&revoluteJointDef);

		// Make the newly created object become the preveous body. 
		preveousBody = newBody;

		// Add a new box for the new rope segment. 
		v_RopeBoxes.push_back(box);

		revoluteJointDef.localAnchorA.Set(0.375f, 0);
		revoluteJointDef.localAnchorB.Set(-0.375f, 0);
	}

	/*

	// Join to final body. 

		// Set final anchor points.
	revoluteJointDef.localAnchorA.Set(0.375f, 0);
	revoluteJointDef.localAnchorB.Set(0, 0.5f);

	revoluteJointDef.bodyA = preveousBody;
	revoluteJointDef.bodyB = finalBody;

	world->CreateJoint(&revoluteJointDef);

	*/

}

void Rope::m_DrawRope(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < v_RopeBoxes.size(); i++)
	{
		window.draw(v_RopeBoxes.at(i));
	}
}

void Rope::m_UpdateRope()
{
	for (unsigned int i = 0; i < v_RopeBoxes.size(); i++)
	{

		v_RopeBoxes.at(i).setPosition(sf::Vector2f(v_RopeSegments.at(i)->GetPosition().x, v_RopeSegments.at(i)->GetPosition().y));

		v_RopeBoxes.at(i).setRotation(v_RopeSegments.at(i)->GetAngle() * RADTODEG);

	}
}
