#pragma once

/*!\file UserInterface.h
*
*This will be used to manage the user interface for the game. It will hold configs 
*for each game state: Main Menu, Options Menu, Main Game and level Select. 
*
*/

//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

class UserInterface
{
	// Constructor

public:

	//! This is the main constructor for this class
	UserInterface();



	// Deconstrutor 

public:

	// This is the deconstructor for this class. 
	~UserInterface();



	// Data Members 

private:



	// Member Functions

public:

	//! This will load the buttons for the Main Menu. 
	int m_MainMenuButtons();

};