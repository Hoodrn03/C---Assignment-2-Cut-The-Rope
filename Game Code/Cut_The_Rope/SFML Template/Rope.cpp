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
	
	b2BodyDef bodyDef; 

	bodyDef.type = b2_dynamicBody;


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

		v_RopeBoxes.at(i).setPosition(sf::Vector2f(v_RopeSegments.at(i + 1)->GetWorldCenter().x, v_RopeSegments.at(i + 1)->GetWorldCenter().y)); 

		v_RopeBoxes.at(i).setRotation(v_RopeSegments.at(i + 1)->GetAngle() * 180 / PI);

	}
}
