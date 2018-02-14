#pragma once


/*!\file MainWindow.h
*
*This will be used to manage the main game window and the views accosiated with it.
*As well as holding a reference to the window and the views it will also hold other
*functions regarding the window like resize and close functions. 
*
*/


//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

class MainWindow
{
	// Constructor 

public:

	//! This will be the default constructor for this class.
	MainWindow();



	// Deconstructor 

public:

	//! This will be the deconstructor for this class. 
	~MainWindow();



	// Member Functions 

private:

	//! This will hold the main game window. The default value for this is null until the class is initalized.  
	sf::RenderWindow * gameWindow = nullptr; 

	//! This will be the predefined width for the window.
	unsigned int uiWindowWidth = 750; 

	//! This will be the predefined height for the window. 
	unsigned int uiWindowHeight = 750; 

	const std::string sWindowName  = "Game Window";

	// Data members 

public:

	//! This will be used to get access to the current window. 
	sf::RenderWindow * m_GetWindow();

	//! This will be used to either set the window to fullscreen or turn it off. 
	int m_SetWindowToFullscreen(bool isTriggered);

};