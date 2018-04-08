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

public:

	~Ball();

	// Data Members 

private:

	sf::CircleShape m_TempBall;

	b2BodyDef m_BallBodyDef;
	b2CircleShape m_DynamicBall;
	b2FixtureDef m_FixtureDef; 
	b2Body *m_BallBody; 

	float m_fDensity = 1.0f; 
	float m_fFriction = 0.3f;
	float m_fBouncyness = 0.5f;

	float m_fBallSize = {0.15f};

	// Member functions 

public:

	void m_DrawBall(sf::RenderWindow &window); 

	void m_AddToPhysicsWorld(b2World *world);

	void m_UpdatePosition();

};
