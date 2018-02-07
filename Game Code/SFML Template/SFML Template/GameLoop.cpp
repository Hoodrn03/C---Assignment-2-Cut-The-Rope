#include "GameLoop.h"


//! Constructor :- This will be called when a new instance of this class is created.
/*!
/
*/
Gameloop::Gameloop()
{
	m_LoadTextures();
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

	clUserInterface.m_ResetButtons();

	m_MainMenuButtons();

	while(clMainWindow.m_GetWindow()->isOpen())
	{
		// Update Game Logic

		// Handles Events
		clEventHandler.m_checkEvents(*clMainWindow.m_GetWindow());

		clMainWindow.m_GetWindow()->clear();

		// Draw Objects

		clUserInterface.m_DrawButtons();

		clMainWindow.m_GetWindow()->display();


	}

	return 0;
}

//! Main Menu Buttons :- This will be used to create all of the buttons which will be on the main menu. 
/*
/
*/
int Gameloop::m_MainMenuButtons()
{
	clUserInterface.m_CreateExitButton(clTextureMananger.m_GetFont("Arial"), clTextureMananger.m_GetTexture("Button"));

	return 0;
}


//! Load Textures :- This will be used to load all of the textures into the game. 
/*
/
*/
int Gameloop::m_LoadTextures()
{
	clTextureMananger.m_AddTexture("Button", "Res/Sprites/Button.png");

	clTextureMananger.m_AddFont("Arial", "Res/Fonts/arial.ttf");

	return 0;
}
