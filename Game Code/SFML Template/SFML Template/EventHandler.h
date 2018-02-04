#pragma once

/*!\file EventHandler.h
*
*This will be used to handle all events which will arise within my game.
*It will be called once every frame and will be used to ensure that if an event 
*were to arise it will be handled acordingly; events such as the window being closed. 
*
*/

//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

class EventHandler
{
	// Constructor 

public:

	//! This will be the default constructor for this class.
	EventHandler();

	// Deconstructor 

public:

	//! This will be the deconstructor for this class. 
	~EventHandler();

	// Data Members 

public:

	//! This will be used to check for events. 
	sf::Event event; 

	// Member Functions 

public:

	//! This will be used to check for events in the current loop. 
	int m_checkEvents(sf::RenderWindow &window);

};
