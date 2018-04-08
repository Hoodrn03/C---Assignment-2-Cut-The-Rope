/*!\file Window.cpp
*
* This will house all of the function declarations for the class window.
*
*/

#include "Window.h"

//-------------------------------------------------------------

/*! Constructor 
\
*/
Window::Window()
{
	// Create a window with a size of 500 width by 500 height. With the name Cut the Rope. 

	m_Window.create(sf::VideoMode(720, 800), "Cut the Rope");

	m_View.reset(sf::FloatRect(0.0f, 0.0f, m_fScaleX, m_fScaleY)); 

	m_Window.setView(m_View);
}

//-------------------------------------------------------------

/*! Deconstructor 
\ 
*/
Window::~Window()
{

}

//-------------------------------------------------------------

/*! Get Window : This will allow access to the game's window.
\
*/
sf::RenderWindow &Window::m_GetWindow()
{
	return m_Window;
}

//-------------------------------------------------------------

/*! Get View : This will allow access to the game's View.
\
*/
sf::View Window::m_GetView()
{
	return m_View;
}


