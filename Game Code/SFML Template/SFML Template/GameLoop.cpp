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

		clUserInterface.m_CheckButtons(clMainWindow.m_GetWindow());

		// Handles Events
		clEventHandler.m_checkEvents(*clMainWindow.m_GetWindow());

		clMainWindow.m_GetWindow()->clear();

		// Draw Objects



		clUserInterface.m_DrawButtons(clMainWindow.m_GetWindow());

		clMainWindow.m_GetWindow()->display();


	}

	return 0;
}

//! Level Select :- Will be used to allow for the player to navigate between the different game states. 
/*!
/returns an integer to allow for the game to close.
*/
int Gameloop::m_LevelSelect()
{
	// Pre-Game logic 

	clUserInterface.m_ResetButtons();

	while (clMainWindow.m_GetWindow()->isOpen())
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

//! Options Menu :- Will be used to allow for the player to edit their game options. 
/*!
/returns an integer to allow for the game to close.
*/
int Gameloop::m_OptionsMenu()
{
	// Pre-Game logic 

	clUserInterface.m_ResetButtons();

	while (clMainWindow.m_GetWindow()->isOpen())
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

//! Exit :- This will be used to close the game when called. 
/*
/
*/
int Gameloop::m_Exit()
{
	clMainWindow.m_GetWindow()->close();

	return 0;
}



//! Main Menu Buttons :- This will be used to create all of the buttons which will be on the main menu. 
/*
/
*/
int Gameloop::m_MainMenuButtons()
{

	auto func = std::bind(&Gameloop::m_Exit, this);

	clUserInterface.m_CreateExitButton(clTextureMananger.m_GetTexture("Button"), *clMainWindow.m_GetWindow(), func);

	func = std::bind(&Gameloop::m_LevelSelect, this);

	clUserInterface.m_CreateLevelSelectButton(clTextureMananger.m_GetTexture("Button"), *clMainWindow.m_GetWindow(), func);

	func = std::bind(&Gameloop::m_OptionsMenu, this);

	clUserInterface.m_CreateOptionsButton(clTextureMananger.m_GetTexture("Button"), *clMainWindow.m_GetWindow(), func);

	return 0;
}


//! Load Textures :- This will be used to load all of the textures into the game. 
/*
/
*/
int Gameloop::m_LoadTextures()
{
	clTextureMananger.m_AddTexture("Button", "Res/Sprites/Button.png");

	return 0;
}
