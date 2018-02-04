#include "GameLoop.h"


//! Constructor :- This will be called when a new instance of this class is created.
/*!
/
*/
Gameloop::Gameloop()
{

}


//! Deconstructor :- This will  be called at the end of the program or when it goes out of scope. 
/*!
/
*/
Gameloop::~Gameloop()
{

}

//! Main Menu :- Will be used to allow for the player to navigate between the different game states. 
/*!
/returns an integer to allow for the game to close. 
*/
int Gameloop::m_MainMenu()
{

	// Pre-Game logic 

	while(clMainWindow.m_GetWindow()->isOpen())
	{
		// Update Game Logic

		// Handles Events
		clEventHandler.m_checkEvents(*clMainWindow.m_GetWindow());

		clMainWindow.m_GetWindow()->clear();

		// Draw Objects

		clMainWindow.m_GetWindow()->display();


	}

	return 0;
}
