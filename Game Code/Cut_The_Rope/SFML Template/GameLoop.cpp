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
	delete m_World;
}


//-------------------------------------------------------------

/*! Main Game Loop : This will house the main game play/ mechanics for the project. 
\
*/
int GameLoop::m_MainGameLoop()
{
	// Pregame Logic.

	m_World = new b2World(m_Gravity);

	m_Level.m_SetLevelBounds(10, 8, m_World);

	m_Level.m_LevelOne(m_World); 


	// Start Game Loop. 

	while (m_Window.m_GetWindow().isOpen())
	{

		// Update Physics. 

		m_fElapsedTime = m_Clock.getElapsedTime().asSeconds();

		if (m_fElapsedTime > m_fTimeStep)
		{
			m_World->Step(m_fTimeStep, m_iVelocityIterations, m_iPositionIterations);
		
			// Update Positions.

			m_Level.m_UpdateLevel();

			// Restart the clock. 

			m_Clock.restart();
		}

		// Update Logic.



		// Handle Events. 

		m_EventHandler.m_HandleEvents(m_Window.m_GetWindow());


		m_Window.m_GetWindow().clear();

		// Draw Items : Backgound items first. 

		m_Level.m_DrawLevel(m_Window.m_GetWindow());

		m_Window.m_GetWindow().display();


		// Delete Objects at End of Frame. 



	}

	return 0;
}

