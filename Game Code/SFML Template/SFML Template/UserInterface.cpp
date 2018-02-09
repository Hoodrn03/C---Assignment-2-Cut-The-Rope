#include "UserInterface.h"

//! Constructor :- This is the default constructor for this class 
/*!
/
*/
UserInterface::UserInterface()
{
}

//! Deconstructor :- This is the deconstructor for this class. 
/*!
/
*/
UserInterface::~UserInterface()
{
}


//! Create Exit Button :- This will be used to create the exit button for the main menu. 
/*!
/Param One a font which will be used to give the button's text an appearance. 
/Param Two a texture which will give the button a shape and colour. 
*/
int UserInterface::m_CreateExitButton(sf::Font newFont, sf::Texture newTexture)
{
	exitButton.m_SetButtonName("Exit", newFont);

	exitButton.m_SetButtonSprite(newTexture);
	
	listOfButtons.push_back(exitButton);

	return 0;
}

//! Draw Buttons :- This will be used to draw all of the buttons. 
/*!
/Param One a render target, allowing for the buttons to be drwn. 
*/
int UserInterface::m_DrawButtons(sf::RenderWindow *currentDisplay)
{
	exitButton.m_DrawButton(currentDisplay);

	return 0;
}

//! This will be used to empty the vector at the start of each game state. 
/*!
/
*/
int UserInterface::m_ResetButtons()
{

	if (listOfButtons.size() > 0)
	{
		for (int i = listOfButtons.size(); i > 0; i--)
		{
			listOfButtons.pop_back();
		}
	}

	return 0;
}





