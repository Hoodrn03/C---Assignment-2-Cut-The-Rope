/*!\file EventHandler.h
*
* This will be used to handle any events that occur within the game.
*
*/

#pragma once

#include "defs.h"

class EventHandler
{
	// Constructor 

public:

	EventHandler();

	// Deconstructor 

public:

	~EventHandler();

	// Data Members 

private:

	// This will be used to check the current event against a list of possible events. 
	sf::Event m_Event;

	// Member Functions 

public:

	// This will be used to handle all of the events within the game.
	void m_HandleEvents(sf::RenderWindow &window); 

};