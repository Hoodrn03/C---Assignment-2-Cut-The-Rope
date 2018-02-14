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
/Param Four is the width of the button. 
/Param Five is the height of the button.
/Param Six is the is the possition for the button.
*/
int UserInterface::m_CreateExitButton(std::string filePath, sf::RenderWindow &thisWindow, std::function<int()> func, float fWidth, float fHeight, sf::Vector2f buttonPos)
{
	exitButton.m_SetButtonName("Exit", "Res/Fonts/Arial.ttf");

	exitButton.m_SetButtonSprite(filePath, fWidth, fHeight);
	
	exitButton.m_SetButtonPos(buttonPos.x, buttonPos.y);

	exitButton.m_SetFunction(func);

	a_listOfButtons.push_back(exitButton);

	return 0;
}

//! Create Level Select Button :- This will be used to create the Level Select button for the main menu. 
/*!
/Param One a texture which will give the button a shape and colour.
/Param Two is the game window which will be used to move the buttons and resize them.
/Param Three is a function the button will call when pressed.
/Param Four is the width of the button.
/Param Five is the height of the button.
*/
int UserInterface::m_CreateLevelSelectButton(std::string filePath, sf::RenderWindow & thisWindow, std::function<int()> func, float fWidth, float fHeight, sf::Vector2f buttonPos)
{
	levelSelectButton.m_SetButtonName("Level Select", "Res/Fonts/Arial.ttf");

	levelSelectButton.m_SetButtonSprite(filePath, fWidth, fHeight);

	levelSelectButton.m_SetButtonPos(buttonPos.x, buttonPos.y);

	levelSelectButton.m_SetFunction(func);

	a_listOfButtons.push_back(levelSelectButton);

	return 0;
}

//! Create Options Button :- This will be used to create the Level Select button for the main menu. 
/*!
/Param One a texture which will give the button a shape and colour.
/Param Two is the game window which will be used to move the buttons and resize them.
/Param Three is a function the button will call when pressed.
/Param Four is the width of the button.
/Param Five is the height of the button.
*/
int UserInterface::m_CreateOptionsButton(std::string filePath, sf::RenderWindow & thisWindow, std::function<int()> func, float fWidth, float fHeight, sf::Vector2f buttonPos)
{
	optionsButton.m_SetButtonName("Options", "Res/Fonts/Arial.ttf");

	optionsButton.m_SetButtonSprite(filePath, fWidth, fHeight);

	optionsButton.m_SetButtonPos(buttonPos.x, buttonPos.y);

	optionsButton.m_SetFunction(func);

	a_listOfButtons.push_back(optionsButton);

	return 0;
}


//! Create Fullscreen Toggle :- This will be used to create the fullscreen toggle for the options menu. 
/*!
/Param One a texture which will give the Toggle the on state of the button.
/Param Two a texture which will give the Toggle the off state of the button.
/Param Three is the width of the button.
/Param Four is the height of the button.
*/
int UserInterface::m_CreateFullScreenToggle(std::string filePathOn, std::string filePathOff, float fWidth, float fHeight, sf::Vector2f togglePos)
{
	fullScreenToggle.m_SetButtonSprits(filePathOn, filePathOff, fWidth, fHeight);

	fullScreenToggle.m_SetButtonName("FullScreen", "Res/Fonts/Arial.ttf");

	fullScreenToggle.m_SetTogglePos(togglePos);

	a_listOfToggles.push_back(fullScreenToggle);

	return 0;
}

//! Draw Buttons :- This will be used to draw all of the buttons. 
/*!
/Param One a render target, allowing for the buttons to be drwn. 
*/
int UserInterface::m_DrawButtons(sf::RenderWindow *currentDisplay)
{
	if (a_listOfButtons.size() > 0)
	{
		for (unsigned int i = 0; i < a_listOfButtons.size(); i++)
		{
			a_listOfButtons[i].m_DrawButton(currentDisplay);
		}
	}

	if (a_listOfToggles.size() > 0)
	{
		for (unsigned int i = 0; i < a_listOfToggles.size(); i++)
		{
			a_listOfToggles[i].m_DrawButton(currentDisplay);
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
	if (a_listOfButtons.size() > 0)
	{
		for (unsigned int i = 0; i < a_listOfButtons.size(); i++)
		{
			a_listOfButtons[i].m_CheckForPress(currentDisplay);
		}

		if (a_listOfToggles.size() > 0)
		{
			for (unsigned int i = 0; i < a_listOfToggles.size(); i++)
			{
				a_listOfToggles[i].m_CheckForPress(currentDisplay);
			}
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

	if (a_listOfButtons.size() > 0)
	{
		for (int i = a_listOfButtons.size(); i > 0; i--)
		{
			a_listOfButtons.pop_back();
		}
	}

	if (a_listOfToggles.size() > 0)
	{
		for (unsigned int i = a_listOfToggles.size(); i > 0 ; i--)
		{
			a_listOfToggles.pop_back();
		}
	}

	return 0;
}





