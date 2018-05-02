/*!\file Level.cpp
*
* This will house all of the function declarations for the class Level.
*
*/

#include "Button.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
Button::Button()
{
}

Button::Button(float width, float height, float xPos, float yPos, std::string text, sf::Font font)
{
	m_buttonBody.setSize(sf::Vector2f(width, height)); 

	m_buttonBody.setPosition(xPos, yPos); 

	m_ButtonText.setFont(font); 

	m_ButtonText.setPosition(xPos, yPos); 
}

//-------------------------------------------------------------

/*! Constructor
\
*/
Button::~Button()
{
}

void Button::m_DrawButton(sf::RenderWindow &window)
{
	window.draw(m_buttonBody);
	window.draw(m_ButtonText);
}
