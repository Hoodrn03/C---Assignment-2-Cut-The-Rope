#include "MainWindow.h"


//! Constructor :- This will be called when a new instance of this class is created.
/*!
/This will assign a new render window to the pointer when a new instance of this class is created. 
*/
MainWindow::MainWindow()
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(uiWindowWidth, uiWindowHeight), "Game Window");
}


//! Deconstructor :- This will  be called at the end of the program or when it goes out of scope.
/*!
/This will delete the pointer to the game window when the class is deconstructed. 
*/
MainWindow::~MainWindow()
{
	delete gameWindow;
}

//! Get Window :- This will be used to get access to the current game window. 
/*!
/This will return a pointer to the game window. 
*/
sf::RenderWindow * MainWindow::m_GetWindow()
{
	return gameWindow;
}
