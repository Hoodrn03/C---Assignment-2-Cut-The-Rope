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
/Param One a texture which will give the button a shape and colour.
/Param Two is the game window which will be used to move the buttons and resize them. 
/Param Three is a function the button will call when pressed. 
*/
int UserInterface::m_CreateExitButton(sf::Texture newTexture, sf::RenderWindow &thisWindow, std::function<int()> func)
{
	exitButton.m_SetButtonName("Exit", "Res/Fonts/Arial.ttf");

	exitButton.m_SetButtonSprite(newTexture, 10, 4);
	
	exitButton.m_SetButtonPos(thisWindow.getSize().x * 0.26f, thisWindow.getSize().y * 0.33f);

	exitButton.m_SetFunction(func);

	listOfButtons.push_back(exitButton);

	return 0;
}

//! Create Level Select Button :- This will be used to create the Level Select button for the main menu. 
/*!
/Param One a texture which will give the button a shape and colour.
/Param Two is the game window which will be used to move the buttons and resize them.
/Param Three is a function the button will call when pressed.
*/
int UserInterface::m_CreateLevelSelectButton(sf::Texture newTexture, sf::RenderWindow & thisWindow, std::function<int()> func)
{
	levelSelectButton.m_SetButtonName("Level Select", "Res/Fonts/Arial.ttf");

	levelSelectButton.m_SetButtonSprite(newTexture, 10, 4);

	levelSelectButton.m_SetButtonPos(thisWindow.getSize().x * 0.26f, thisWindow.getSize().y * 0.46f);

	levelSelectButton.m_SetFunction(func);

	listOfButtons.push_back(levelSelectButton);

	return 0;
}

int UserInterface::m_CreateOptionsButton(sf::Texture newTexture, sf::RenderWindow & thisWindow, std::function<int()> func)
{
	optionsButton.m_SetButtonName("Options", "Res/Fonts/Arial.ttf");

	optionsButton.m_SetButtonSprite(newTexture, 10, 4);

	optionsButton.m_SetButtonPos(thisWindow.getSize().x * 0.26f, thisWindow.getSize().y * 0.59f);

	optionsButton.m_SetFunction(func);

	listOfButtons.push_back(optionsButton);

	return 0;
}



//! Draw Buttons :- This will be used to draw all of the buttons. 
/*!
/Param One a render target, allowing for the buttons to be drwn. 
*/
int UserInterface::m_DrawButtons(sf::RenderWindow *currentDisplay)
{
	if (listOfButtons.size() > 0)
	{
		for (unsigned int i = 0; i < listOfButtons.size(); i++)
		{
			listOfButtons[i].m_DrawButton(currentDisplay);
		}
	}

	return 0;
}

//! Check Buttons :- This will be used to check if the button has been pressed. 
/*!
/Param One a render window to ensure that the button is getting checked within the game window.
*/
int UserInterface::m_CheckButtons(sf::RenderWindow *currentDisplay)
{
	if (listOfButtons.size() > 0)
	{
		for (unsigned int i = 0; i < listOfButtons.size(); i++)
		{
			listOfButtons[i].m_CheckForPress(currentDisplay);
		}
	}

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





