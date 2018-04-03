/*!\file Ball.h
*
* This class will stand as the player's gameobject, the ball is the main part of the game and 
* the player's goal for this game will be to make the ball fall into an end point within the 
* level. 
*
* This class will hold all of the functionality for the ball, as well as the sprite and texture 
* associated with the ball. 
* 
*/

#pragma once

#include "defs.h"

class Ball
{
	// Constructor 

public:

	Ball();

	// Deconstructor 

	~Ball();

public:

	// Data Members 

private:

	sf::CircleShape m_TempBall;


	// Member functions 

public:

	void m_DrawBall(sf::RenderWindow &window); 

};
