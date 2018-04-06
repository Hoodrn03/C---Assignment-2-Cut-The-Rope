/*!\file Physics.cpp
*
* This will house all of the function declarations for the class Physics.
*
*/

#include "EventHandler.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
EventHandler::EventHandler()
{

}

//-------------------------------------------------------------

/*! Deconstructor 
\
*/
EventHandler::~EventHandler()
{

}

//-------------------------------------------------------------

/*! Handle Events : This will be used to handle the events within the game. 
\Param One - Render Window : This will allow for the class to poll the window for events.
*/
void EventHandler::m_HandleEvents(sf::RenderWindow &window)
{
	while (window.pollEvent(m_Event))
	{
		if (m_Event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}
