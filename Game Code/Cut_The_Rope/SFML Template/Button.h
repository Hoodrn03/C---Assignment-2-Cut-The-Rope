/*!\file Button.h
*
* This will be used to create a basic button for the game. 
*
*/

#pragma once

#include "defs.h"

class Button
{
	// Constructor

public:

	Button();

	Button(float width, float height, float xPos, float yPos, std::string text, sf::Font *font);

	// Deconstructor 

public:

	~Button();

	// Data Members 

private:

	sf::RectangleShape m_buttonBody; 

	sf::Text m_ButtonText; 


	// Member Functions

public:

	void m_DrawButton(sf::RenderWindow &window); 

	bool m_CheckButton(float mouseX, float mouseY);

	std::string m_GetButonName();

};
