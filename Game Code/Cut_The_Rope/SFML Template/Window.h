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

	/* 
	* This is the game window, it will be used to display the game and register events within the game.
	*/ 
	sf::RenderWindow m_Window; 

	// This is the game's view, it acts like a movable camera allowing for objects to be scaled easily. 
	sf::View m_View; 

	// The Scale for the game will be 8 meters by 6. 
	float m_fScaleX = 9, m_fScaleY = 7; 

	// Member Functions 

public: 

	// Allows access to the render window outside the class. 
	sf::RenderWindow &m_GetWindow();

	// This will allow access to the game's view (camera). 
	sf::View m_GetView();

};
