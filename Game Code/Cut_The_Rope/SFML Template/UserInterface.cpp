/*!\file Level.cpp
*
* This will house all of the function declarations for the class Level.
*
*/

#include "UserInterface.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
UserInterface::UserInterface()
{

	// Load Fonts 

	m_TextureLoader.m_LoadFontToMap("res/Fonts/Fudged.ttf", "Fudged");
	m_TextureLoader.m_LoadFontToMap("res/Fonts/Fudged-Italic.ttf", "Fudged_I");

	m_TextureLoader.m_LoadFontToMap("res/Fonts/Pentay-Sans-Regular.ttf", "Pentay_Sans");

	m_TextureLoader.m_LoadFontToMap("res/Fonts/Arial.ttf", "Arial");
}

//-------------------------------------------------------------

/*! Constructor
\
*/
UserInterface::~UserInterface()
{
}

void UserInterface::m_MainMenuInterface()
{


}

void UserInterface::m_GameInterface()
{
}

void UserInterface::m_AddButton(float newX, float newY, float width, float height, std::string text)
{
	Button * temp = new Button(width, height, newX, newY, text, m_TextureLoader.m_GetFontFromMap("Arial")); 

	std::cout << text; 

	v_Buttons.push_back(*temp);

	delete temp; 
}

void UserInterface::m_DrawButtons(sf::RenderWindow & window)
{
	if (v_Buttons.size() > 0)
	{
		for (unsigned int i = 0; i < v_Buttons.size(); i++)
		{
			v_Buttons.at(i).m_DrawButton(window);
		}
	}
}

std::string UserInterface::m_CheckButtons(float mouseX, float mouseY)
{

	if (v_Buttons.size() > 0)
	{
		for (unsigned int i = 0; i < v_Buttons.size(); i++)
		{
			if (v_Buttons.at(i).m_CheckButton(mouseX, mouseY))
			{
				return v_Buttons.at(i).m_GetButonName();
			}
		}
	}


	return "Nope";
}
