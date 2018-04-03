/*!\file Window.h
*
* This will be used to control all of the window and drawing to window functions. 
*
*/

#pragma once

#include "defs.h"

class Window
{
	// Constructor 

public:

	Window();

	// Dectonstructor 

public:

	~Window();

	// Data Members 

private:

	sf::RenderWindow m_Window; 

	sf::View m_View; 

	// Member Functions 

public: 

	// Allows access to the render window outside the class. 
	sf::RenderWindow &m_GetWindow();

	sf::View m_GetView();

};
