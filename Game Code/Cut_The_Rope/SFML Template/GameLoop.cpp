/*!\file Gameloop.cpp
*
* This will house all of the function declarations for the class GameLoop.
*
*/

#include "GameLoop.h"


//-------------------------------------------------------------

/*! Constructor
\
*/
GameLoop::GameLoop()
{

}


//-------------------------------------------------------------

/*! Deconstructor
\
*/
GameLoop::~GameLoop()
{

}


//-------------------------------------------------------------

/*! Main Game Loop : This will house the main game play/ mechanics for the project. 
\
*/
int GameLoop::m_MainGameLoop()
{
	// Pregame Logic

	while (m_Window.m_GetWindow().isOpen())
	{
		// Update Logic

		sf::Event event; 

		// Handle Events. 

		while (m_Window.m_GetWindow().pollEvent(event))
		{
			// If window closed close window. 

			if (event.type == sf::Event::Closed)
			{
				m_Window.m_GetWindow().close();
			}
		}

		m_Window.m_GetWindow().clear();

		// Draw Items : Backgound items first. 

		m_Window.m_GetWindow().display();

	}

	return 0;
}

