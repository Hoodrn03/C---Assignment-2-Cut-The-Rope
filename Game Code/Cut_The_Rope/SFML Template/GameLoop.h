/*!\file GameLoop.h
*
* This will be used to house all of the game functions. It will be the main game loop
* and gouse all of the game mechanics and allow for the classes to interact with each other. 
*
*/

#pragma once

#include "defs.h"

#include "Window.h"

class GameLoop
{
	// Constructor 

public:

	GameLoop();

	// Deconstructor 

public:

	~GameLoop();

	// Data Members 

private:

	// Classes 

	// Class containing all of the render window functionality. 
	Window m_Window; 

	// Member Functions 

public:

	// Main Game loop for the project. 
	int m_MainGameLoop();




};