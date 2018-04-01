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

	window.create(sf::VideoMode(500, 500), "Cut the Rope");
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
	return window;
}


