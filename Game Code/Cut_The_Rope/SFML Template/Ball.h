/*!\file Ball.h
*
* This class will stand as the player's gameobject, the ball is the main part of the game and 
* the player's goal for this game will be to make the ball fall into an end point within the 
* level. 
*
* This class will hold all of the functionality for the ball, as well as the sprite and texture 
* associated with the ball. 
*
* This class Inherits from Physics Object to gain access to the creation of a box 2d body and allows
* for the ball to interact with other items in the 'physics world'. 
* 
*/

#pragma once

#include "defs.h"
#include "PhysicsObject.h"

class Ball : public PhysicsObject
{
	// Constructor 

public:

	Ball();

	// Deconstructor 

public:

	~Ball();

	// Data Members 

private:

	// This is the temp object used for displaying the ball without the need of a texture or sprite (It is a block colour). 
	sf::CircleShape m_TempBall;

	// This is the base size for the ball. 
	float m_fBallSize = {0.25f};

	// Member functions 

public:

	// This will be used to set the radius for the ball. 
	void m_SetBallRadius(float radius);

	// This will be used to draw the ball. 
	void m_DrawBall(sf::RenderWindow &window); 

	// This will be used to update the ball.
	void m_UpdateBall();

};
