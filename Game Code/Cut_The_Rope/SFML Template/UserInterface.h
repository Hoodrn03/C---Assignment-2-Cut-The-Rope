/*!\file UserInterface.h
*
* This will be used to hold and load all of the user inter face items within the levels and the menus 
* this class will also hold the functionality to detect if a button. 
*
*/

#pragma once

#include "defs.h"

#include "TextureLoader.h"
#include "Button.h"

class UserInterface
{
	// Constructor

public:

	UserInterface();

	// Deconstructor 

public:

	~UserInterface();

	// Data Members 

private:

	TextureLoader m_TextureLoader;

	std::vector<Button> v_Buttons; 

	// Member Functions 

public:

	void m_MainMenuInterface();

	void m_GameInterface();



};