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

#include "ToggleButton.h"

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

	//! This is the exit button for the main menu.
	Button<int> exitButton;

	//! This is the level select button for the main menu.
	Button<int> levelSelectButton;

	//! This is the options menu button. 
	Button<int> optionsButton;

// Options Menu buttons.  

	//! This is the toggle button for toggling fullscreen.
	ToggleButton<int> fullScreenToggle;

// Button Vectors 

	//! This will hold all of the current buttons in the game.
	std::vector<Button<int>> a_listOfButtons;

	//! This will hold all of the current toggles.
	std::vector<ToggleButton<int>> a_listOfToggles;

	// Member Functions

public:

	// Create Buttons 

	// Main Menu :- 

	//! This will be used to create the exit button. 
	int m_CreateExitButton(sf::Texture newTexture, sf::RenderWindow &thisWindow, std::function<int()> func, float fWidth, float fHeight, sf::Vector2f buttonPos);

	//! This will be used to create the level select menu. 
	int m_CreateLevelSelectButton(sf::Texture newTexture, sf::RenderWindow &thisWindow, std::function<int()> func, float fWidth, float fHeight, sf::Vector2f buttonPos);

	//! This will be used to create the options button. 
	int m_CreateOptionsButton(sf::Texture newTexture, sf::RenderWindow &thisWindow, std::function<int()> func, float fWidth, float fHeight, sf::Vector2f buttonPos);

	// Options Menu :- 

	//! This will create the fullscreen toggle button for the options menu. 
	int m_CreateFullScreenToggle(sf::Texture newTextureOn, sf::Texture newTextureOff, float fWidth, float fHeight);

	// Manage Buttons 

	//! This will be used to draw all of the current buttons. 
	int m_DrawButtons(sf::RenderWindow *currentDisplay);

	//! This will be used to check if the button has been pressed. 
	int m_CheckButtons(sf::RenderWindow *currentDisplay);

	//! This will be used to empty the vector of buttons. 
	int m_ResetButtons();

};