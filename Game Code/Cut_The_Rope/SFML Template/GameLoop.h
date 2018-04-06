/*!\file GameLoop.h
*
* This will be used to house all of the game functions. It will be the main game loop
* and gouse all of the game mechanics and allow for the classes to interact with each other. 
*
*/

#pragma once

#include "defs.h"

#include "Window.h"
#include "Ball.h"
#include "Level.h"
#include "EventHandler.h"

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

	// This will be the constant value for gravity in the game world. 
	const b2Vec2 m_Gravity = { 0.0f, -10.0f };

	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	float32 timeStep = 1.0f / 60.0f;

	// Classes 

	// Class containing all of the render window functionality. 
	Window m_Window; 

	// This will be the the player's object, the player's aim will be to get the ball to an end point on the level. 
	Ball m_Ball;

	// The level object will hold all of the level pieces for the game. 
	Level m_Level;

	// This will be used to handle all of the events that occur within the game. 
	EventHandler m_EventHandler; 

	// Member Functions 

public:

	// Main Game loop for the project. 
	int m_MainGameLoop();




};