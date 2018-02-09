#pragma once

/*!\file UserInterface.h
*
*This will be used to manage the user interface for the game. It will hold configs 
*for each game state: Main Menu, Options Menu, Main Game and level Select. 
*
*/

//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

#include "Button.h"

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

// Main Menu buttons:

	//! This is the exit button for the main menu
	Button<int> exitButton;

	std::vector<Button<int>> listOfButtons;

	// Member Functions

public:

	//! This will be used to create the exit button. 
	int m_CreateExitButton(sf::Texture newTexture, sf::RenderWindow &thisWindow);

	//! This will be used to draw all of the current buttons. 
	int m_DrawButtons(sf::RenderWindow *currentDisplay);

	//! This will be used to empty the vector of buttons. 
	int m_ResetButtons();

};