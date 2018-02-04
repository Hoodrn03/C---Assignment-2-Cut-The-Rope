#include "EventHandler.h"

//! Constructor :- This is the default constructor for this class 
/*!
/
*/
EventHandler::EventHandler()
{

}

//! Deconstructor :- This is the deconstructor for this class. 
/*!
/
*/
EventHandler::~EventHandler()
{

}

//! Check Events :- This will check for events in the current game loop. 
/*!
/Param one :- an sf::RenderWindow It will be used to check the window for any events. 
/Returns an integer to exit the function if either if it finds an event or not. 
*/
int EventHandler::m_checkEvents(sf::RenderWindow &window)
{
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}

	return 0;
}


