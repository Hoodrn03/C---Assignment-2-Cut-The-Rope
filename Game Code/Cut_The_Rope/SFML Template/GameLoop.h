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
#include "MouseTool.h"

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
	const b2Vec2 m_Gravity{ 0.0f, 10.0f };

	// This will be used to control all of the physics within the game. 
	b2World * m_World;

	// This will be used to check if the physics should be updated (World step). 
	float32 m_fTimeStep = 1.0f / 60.0f;

	// The number of velocity interation for the game, (Increase to improve accuracy, but may decrease performance). 
	int32 m_iVelocityIterations = 7;

	// The number of Position interation for the game, (Increase to improve accuracy, but may decrease performance). 
	int32 m_iPositionIterations = 5;

	// The current ellapsed time since last physics world step. 
	float m_fElapsedTime; 

	// The clock for keeping track of the current ellapsed time.
	sf::Clock m_Clock; 

	//-------------------------------------------------------------\\
	// Classes 
	//-------------------------------------------------------------//

	// Class containing all of the render window functionality. 
	Window m_Window; 

	// The level object will hold all of the level pieces for the game. 
	Level m_Level;

	// This will be used to handle all of the events that occur within the game. 
	EventHandler m_EventHandler; 

	// This will be used to handle all of the mouse functionality, (mainly cutting the ropes). 
	MouseTool m_MouseTool; 

	// Member Functions 

public:

	// Main Game loop for the project. 
	int m_MainGameLoop();

};