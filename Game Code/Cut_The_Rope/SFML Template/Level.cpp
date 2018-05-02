/*!\file Level.cpp
*
* This will house all of the function declarations for the class Level.
*
*/

#include "Level.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
Level::Level()
{
	// Object Textures 
	m_TextureLoader.m_LoadTextureToMap("res/Sprites/Ball.png", "Ball"); 
	m_TextureLoader.m_LoadTextureToMap("res/Sprites/EndPoint.png", "EndPoint");
	m_TextureLoader.m_LoadTextureToMap("res/Sprites/Platform.png", "Platform");
	m_TextureLoader.m_LoadTextureToMap("res/Sprites/Rope.png", "Rope");

	// Background Textures
	m_TextureLoader.m_LoadTextureToMap("res/Backgrounds/Background.png", "Background");

	m_TextureLoader.m_LoadTextureToMap("res/Backgrounds/Main_Background.png", "Main_Background");

	// Background Load Background. 

	m_Background.setSize(sf::Vector2f(10, 8));

	m_MenuBackground.setSize(sf::Vector2f(10, 8));

	m_MenuBackground.setTexture(m_TextureLoader.m_GetTextureFromMap("Main_Background"));

}

//-------------------------------------------------------------

/*! Deconstructor 
\
*/
Level::~Level()
{

}

//-------------------------------------------------------------

/*! Set Level Bounds : This will be used to set the bounds for the game window, constraining all of the game objects to the widndow. 
\Param One - Float : This is the width of the view I am using to display the game, to ensure the bounds are only within the current display.
\Param Two - Float : This is the height of the view I am using to display the game, to ensure the bounds are only within the current display.
\Param Three - b2World : This will allow for the objects to be added into the physics world. 
*/
void Level::m_SetLevelBounds(float viewSizeX, float viewSizeY, b2World *world)
{
	// Base Values 

	// Get Base Values 
	float fBaseWidth = 0.5f, fBaseHeight = 0.5f;

	Platform *tempPlatform; 

	Ball *tempBall;

	// Set Level Background 

	m_Background.setTexture(m_TextureLoader.m_GetTextureFromMap("Background"));

	// Bottom Platform

	tempPlatform = new Platform();

	tempPlatform->m_SetTag(NULL_VALUE);

	tempPlatform->m_SetStartAngle(0);

	tempPlatform->m_CreateBoxObject(viewSizeX, fBaseHeight, false, world, (viewSizeX * HALF), viewSizeY - (fBaseHeight * HALF));

	tempPlatform->m_CreatePlatform(viewSizeX, fBaseHeight);

	tempPlatform->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Platform"));

	tempPlatform->m_SetData(tempPlatform);

	v_Platforms.push_back(*tempPlatform);

	// Top Platform

	tempPlatform = new Platform();

	tempPlatform->m_SetTag(NULL_VALUE);

	tempPlatform->m_SetStartAngle(0);

	tempPlatform->m_CreateBoxObject(viewSizeX, fBaseHeight, false, world, (viewSizeX * HALF), 0 - (fBaseHeight * HALF));

	tempPlatform->m_CreatePlatform(viewSizeX, fBaseHeight);

	tempPlatform->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Platform"));

	tempPlatform->m_SetData(tempPlatform);

	v_Platforms.push_back(*tempPlatform);

	// Left Platform

	tempPlatform = new Platform();

	tempPlatform->m_SetTag(NULL_VALUE);

	tempPlatform->m_SetStartAngle(90);

	tempPlatform->m_CreateBoxObject(viewSizeY, fBaseWidth, false, world, (fBaseWidth * HALF), (viewSizeY * HALF));

	tempPlatform->m_CreatePlatform(viewSizeY, fBaseWidth);

	tempPlatform->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Platform"));

	tempPlatform->m_SetData(tempPlatform);

	v_Platforms.push_back(*tempPlatform);

	// Right Platform

	tempPlatform = new Platform();

	tempPlatform->m_SetTag(NULL_VALUE);

	tempPlatform->m_SetStartAngle(90);

	tempPlatform->m_CreateBoxObject(viewSizeY, fBaseWidth, false, world, viewSizeX - (fBaseWidth * HALF), 0 + (viewSizeY * HALF));

	tempPlatform->m_CreatePlatform(viewSizeY, fBaseWidth);

	tempPlatform->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Platform"));

	tempPlatform->m_SetData(tempPlatform);

	v_Platforms.push_back(*tempPlatform);

	// Ball 

	tempBall = new Ball();

	tempBall->m_SetProperties(0.5f, 0.3f, 1.f);

	tempBall->m_SetTag(BALL_ENTITY);

	tempBall->m_CreateBallObject(0.5f, true, world, 4.f, 1.f);

	tempBall->m_SetBallRadius(0.25f);

	tempBall->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Ball"));

	tempBall->m_SetData(tempBall);

	v_Balls.push_back(*tempBall);

	// Delete Pointers. 

	delete tempBall;

	delete tempPlatform;


}

//-------------------------------------------------------------

/*! Level One : This will hold the creation of the very first level, the test level (Codename Level 0). 
\Param One - b2World : This will allow for the objects to be added into the physics world.
*/
void Level::m_LevelOne(b2World * world)
{
	//-------------------------------------------------------------\\

	// Locals

	Platform *tempPlatform; 

	Rope *tempRope; 

	EndPoint *tempEndPoint; 

	//-------------------------------------------------------------\\
	//							Platforms 
	//-------------------------------------------------------------\\

	// Suspended Platform

	tempPlatform = new Platform();

	tempPlatform->m_SetTag(NULL_VALUE); 

	tempPlatform->m_SetStartAngle(0);

	tempPlatform->m_SetProperties(2.f, 0.5f, 0.0f);

	tempPlatform->m_CreateBoxObject(3.f, 0.5f, true, world, 5.f, 4.f);

	tempPlatform->m_CreatePlatform(3.f, 0.5f);

	tempPlatform->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Platform"));

	tempPlatform->m_SetData(tempPlatform);

	v_Platforms.push_back(*tempPlatform);

	//-------------------------------------------------------------\\
	//						EndPoint 
	//-------------------------------------------------------------\\

	// End Point. 

	tempEndPoint = new EndPoint;

	tempEndPoint->m_SetTag(SENSOR_ENTITY);

	tempEndPoint->m_SetStartAngle(0);

	tempEndPoint->m_SetProperties(1.5f, 5.0f, 0.f); 

	tempEndPoint->m_CreateBoxObject(1.f, 1.f, true, world, 8.f, 6.f); 

	tempEndPoint->m_CreateEndPoint(1.f, 1.f);

	b2CircleShape cShape; 

	cShape.m_radius = 0.75f;

	tempEndPoint->m_AddSensor(cShape);

	tempEndPoint->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("EndPoint"));

	tempEndPoint->m_SetData(tempEndPoint);

	v_EndPoints.push_back(*tempEndPoint);

	//-------------------------------------------------------------\\
	//							Ropes 
	//-------------------------------------------------------------\\

	// First Rope.

	tempRope = new Rope();

	tempRope->m_CreateRope(v_Platforms.at(1).m_GetBody(), 3, v_Balls.at(0).m_GetBody(), world, b2Vec2(0.f, 0.25f), b2Vec2(0, 0));

	tempRope->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Rope"));

	v_Ropes.push_back(*tempRope);

	NumberOfRopes += 1;

	// Second Rope.

	tempRope = new Rope();

	tempRope->m_CreateRope(v_Platforms.at(1).m_GetBody(), 5, v_Platforms.at(4).m_GetBody(), world, b2Vec2(1.5f, 0.25f), b2Vec2(1.f, 0));

	tempRope->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Rope"));

	v_Ropes.push_back(*tempRope);

	NumberOfRopes += 1;

	// Third Rope

	tempRope = new Rope();

	tempRope->m_CreateRope(v_Platforms.at(1).m_GetBody(), 5, v_Platforms.at(4).m_GetBody(), world, b2Vec2(-1.5f, 0.25f), b2Vec2(-1.f, 0));

	tempRope->m_AssignTexture(*m_TextureLoader.m_GetTextureFromMap("Rope"));

	v_Ropes.push_back(*tempRope);

	NumberOfRopes += 1;

	//-------------------------------------------------------------\\

	// Delete Pointers

	delete tempPlatform;
	delete tempRope;
	delete tempEndPoint;

}

//-------------------------------------------------------------

/*! Draw Level Bounds : This will draw all of the level bounds into the game. 
\Param One - Render Window : This will be the main game window for the game, allowing for the sprite to be drawn.
*/
void Level::m_DrawLevel(sf::RenderWindow &window)
{
	// Draw Ropes.

	if (v_Ropes.size() > 0)
	{
		for (unsigned int i = 0; i < v_Ropes.size(); i++)
		{
			v_Ropes.at(i).m_DrawRope(window);
		}
	}

	// Draw Level Platforms. 

	if (v_Platforms.size() > 0)
	{
		for (unsigned int i = 0; i < v_Platforms.size(); i++)
		{
			v_Platforms.at(i).m_DrawPlatform(window);
		}
	}

	// Draw End Points. 

	if (v_EndPoints.size() > 0)
	{
		for (unsigned int i = 0; i < v_EndPoints.size(); i++)
		{
			v_EndPoints.at(i).m_DrawEndPoint(window);
		}
	}

	// Draw Balls

	if (v_Balls.size() > 0)
	{
		for (unsigned int i = 0; i < v_Balls.size(); i++)
		{
			v_Balls.at(i).m_DrawBall(window);
		}
	}
}

//-------------------------------------------------------------

/*! Draw Background : This will be used to draw the background into the game. 
\Param One - Render Window : This will be the main game window for the game, allowing for the sprite to be drawn.
*/
void Level::m_DrawBackground(sf::RenderWindow & window)
{
	window.draw(m_Background); 
}

void Level::m_DrawMenuBackground(sf::RenderWindow & window)
{
	window.draw(m_MenuBackground);
}

//-------------------------------------------------------------

/*! Update Level Items : This will be used to update all of the level items in the current level. 
\
*/
void Level::m_UpdateLevel()
{

	// Update Platforms. 

	if (v_Platforms.size() > 0)
	{
		for (unsigned int i = 0; i < v_Platforms.size(); i++)
		{
			v_Platforms.at(i).m_UpdatePlatform();
		}
	}

	// Draw End Points. 

	if (v_EndPoints.size() > 0)
	{
		for (unsigned int i = 0; i < v_EndPoints.size(); i++)
		{
			v_EndPoints.at(i).m_UpdateEndPoint();
		}
	}

	// Update Ropes.

	if (v_Ropes.size() > 0)
	{
		for (unsigned int i = 0; i < v_Ropes.size(); i++)
		{
			v_Ropes.at(i).m_UpdateRope();
		}
	}
	
	// Update Balls

	if (v_Balls.size() > 0)
	{
		for (unsigned int i = 0; i < v_Balls.size(); i++)
		{
			v_Balls.at(i).m_UpdateBall();
		}
	}

}

//-------------------------------------------------------------

/*! Check For Deleteion : THis will be used to check if any items need to be removed from the game world
\Param One - b2World : The world the items were a part of. 
*/
void Level::m_CheckForDeleteion(b2World *world)
{
	if (v_Platforms.size() > 0)
	{
		for (unsigned int i = 0; i < v_Platforms.size(); i++)
		{
			if (v_Platforms.at(i).m_CheckForDeletion(world))
			{
				v_Platforms.erase(v_Platforms.begin() + i);
			}
		}
	}

	if (v_Balls.size() > 0)
	{
		for (unsigned int i = 0; i < v_Balls.size(); i++)
		{
			if (v_Balls.at(i).m_CheckForDeletion(world))
			{
				v_Balls.erase(v_Balls.begin() + i);
			}
		}
	}
}

//-------------------------------------------------------------

/*! Check Rope : This will be used to check if any ropes are intersecting with a player defined line. 
\Param One - int : The index for which group of rope segements. 
\Param Two - int : Which segment of rope to check. 
*/
sf::Vector2f Level::m_CheckRope(int index, int segment)
{
	return sf::Vector2f(v_Ropes.at(index).v_RopeSegments.at(segment)->GetPosition().x, v_Ropes.at(index).v_RopeSegments.at(segment)->GetPosition().y);
}

//-------------------------------------------------------------

/*! Delete Segement : THis will b eused t remove a specific segment from the vector of ropes. 
\Param One - int : The index for which group of rope segements.
\Param Two - int : Which segment of rope to check.
\Param Three - b2World : The world allowong for the destruction of the body. 
*/
void Level::m_DeleteSegemnt(int index, int segment, b2World *world)
{
	
	world->DestroyBody(v_Ropes.at(index).v_RopeSegments.at(segment));

	v_Ropes.at(index).v_RopeSegments.erase(v_Ropes.at(index).v_RopeSegments.begin() + segment); 

	v_Ropes.at(index).v_RopeSegments.shrink_to_fit();

	v_Ropes.at(index).v_RopeBoxes.pop_back();

}


