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

	m_TextureLoader.m_LoadFontToMap("res/Fonts/Fudged", "Fudged");
	m_TextureLoader.m_LoadFontToMap("res/Fonts/Fudged-Italic", "Fudged_I");

	m_TextureLoader.m_LoadFontToMap("res/Fonts/Pentay-Sans-Regular", "Pentay_Sans");
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
