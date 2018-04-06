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
	// Pregame Logic.

	m_Level.m_SetLevelBounds(m_Window.m_GetView().getSize().x, m_Window.m_GetView().getSize().y);

	// Start Game Loop. 

	while (m_Window.m_GetWindow().isOpen())
	{
		// Update Logic. 



		// Update Physics. 



		// Handle Events. 

		m_EventHandler.m_HandleEvents(m_Window.m_GetWindow());


		m_Window.m_GetWindow().clear();

		// Draw Items : Backgound items first. 

		m_Level.m_DrawLevelBounds(m_Window.m_GetWindow());

		m_Ball.m_DrawBall(m_Window.m_GetWindow());

		m_Window.m_GetWindow().display();


		// Delete Objects at End of Frame. 



	}

	return 0;
}

