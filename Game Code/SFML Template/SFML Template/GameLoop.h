#pragma once

/*!\file GameLoop.h
*
*This will be used to hold the main game states, from the main menu to the 
*options menu. It will also be used to hold the main game state and be 
*responsible for navigating between the game states. 
*
*/

//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

//! This will give access to the the game window.
#include "MainWindow.h"

//! THis will allow access to event handling functions. 
#include "EventHandler.h"

//! This will give access to all of the textures which will be used in the game.
#include "TextureManager.h"

//! This will be used to get access to all of the buttons in the game. 
#include "UserInterface.h"



class Gameloop
{
	// Constructor 

public:

	//! This will be the default constructor for this class.
	Gameloop();

	// Deconstructor 

public:

	//! This will be the deconstructor for this class. 
	~Gameloop();

	// Data members 
	
private:

	//! This is an instance for the game window, it will control the game window for the game. 
	MainWindow clMainWindow;

	/*! 
	This is an instance of the event handler class, it will be used to handle all of the events which will arise 
	within the game. 
	*/
	EventHandler clEventHandler;

	//! This will create an instance of the texture manager. A class which will hold references to all of the game textures. 
	TextureManager clTextureMananger;

	//! This will be used to hold and maintain all of the buttons within the game. 
	UserInterface clUserInterface;

	// Member Functions 

public:

	// Game States :-

	//! This will be the main hub which the player will use to navigate between the different game states. 
	int m_MainMenu();

	//! This will be used to allow for the player to select a level. 
	int m_LevelSelect();

	//! This will be used to allow for the player to change game options. 
	int m_OptionsMenu();

	// Aditional Functionality :- 

	//! This will be used to Exit the game. 
	int m_Exit();

	//! This will be used to create all of the buttons which will be used on gthe main menu. 
	int m_MainMenuButtons();

	// This will be used to assign all of the textures into the texture manager. 
	int m_LoadTextures();
};
