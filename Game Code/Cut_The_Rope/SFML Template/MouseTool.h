/*!\file MouseTool.h
*
* This will be used to cut the ropes within the game. This class will control the mouse
* functionality. 
*
*/

#pragma once

#include "defs.h"

class MouseTool
{
	// Constructor 

public:

	MouseTool();

	// Deconstructor 

public:

	~MouseTool();

	// Data Members

private:

	// This will be used to show where the mouse currently is. 
	sf::RectangleShape m_MouseMarker; 

	// This is the current position for the mouse. 
	sf::Vector2f m_MousePos; 

	// This will be used to define the cuts start point. 
	sf::Vector2f m_CutStart;

	// This will be used to define the cuts end point. 
	sf::Vector2f m_CutEnd;

	// This will display the line the player made. 
	sf::VertexArray m_Line; 

	// Member Functions 

public:

	// This will be used to get the current mouse position. 
	sf::Vector2f m_GetMousePos(sf::RenderWindow &window);

	// This will be used to update the mouse's position. 
	void m_UpdateMouse(); 

	// This will be used to draw the mouse. 
	void m_DrawMouseMarker(sf::RenderWindow &window);

	// This will be used to check if the player wants to make a new cut. 
	void m_Cut(sf::RenderWindow &window);

	// This will be used to create a line between the two player defined points. 
	void m_CreateLine();

	// This will check to see if the line passed into the function intersects with the player defined line. 
	bool m_LineIntersect(sf::Vector2f p2, sf::Vector2f p3);
};
