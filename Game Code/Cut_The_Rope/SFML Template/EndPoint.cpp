/*!\file EndPoint.cpp
*
* This will house all of the function declarations for the class EndPoint.
*
*/

#include "EndPoint.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
EndPoint::EndPoint()
{
}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
EndPoint::~EndPoint()
{
}

//-------------------------------------------------------------

/*! Draw Platform : This will be used to draw the platform into the game window.
\Param One - RenderWindow : This will be the window the platfrom is drawn onto.
*/
void EndPoint::m_DrawEndPoint(sf::RenderWindow & window)
{
	window.draw(m_TempEndPoint);
}

//-------------------------------------------------------------

/*! Create Platform : This will be used to set the height and width of the platform as well as it's origin.
\Param One - float : New Width for the rectangle shape.
\Param Two - float : New Height for the rectangle shape.
*/
void EndPoint::m_CreateEndPoint(float width, float height)
{
	m_TempEndPoint.setSize(sf::Vector2f(width, height));

	m_TempEndPoint.setOrigin(width * HALF, height * HALF);
}

//-------------------------------------------------------------

/*! Update Platform : This will be used to update the position and rotation for the rectangle shape.
\
*/
void EndPoint::m_UpdateEndPoint()
{

	m_TempEndPoint.setPosition(m_Get().x, m_Get().y + m_Get().height * HALF);

	m_TempEndPoint.setRotation(m_GetBody()->GetAngle() * RADTODEG);
}
//-------------------------------------------------------------

/*! Set Colour : This will be used to set the colour of the platform.
\Param One - float : This is the Red value for the shape (Min : 0 - Max : 255).
\Param Two - float : This is the Green value for the shape (Min : 0 - Max : 255).
\Param Three - float : This is the Blue value for the shape (Min : 0 - Max : 255).
*/
void EndPoint::m_SetColour(float r, float g, float b)
{
	sf::Color newColour;

	newColour.r = (sf::Uint8)r;
	newColour.g = (sf::Uint8)g;
	newColour.b = (sf::Uint8)b;

	m_TempEndPoint.setFillColor(newColour);
}