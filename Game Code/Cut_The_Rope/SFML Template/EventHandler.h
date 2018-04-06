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

	sf::Event m_Event;

	// Member Functions 

public:

	void m_HandleEvents(sf::RenderWindow &window); 

};