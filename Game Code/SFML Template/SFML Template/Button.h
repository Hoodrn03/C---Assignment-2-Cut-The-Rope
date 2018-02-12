#pragma once

/*!\file Button.h
*
*This will be used as a template for all of the buttons within the game. 
*The Buttons will have some text written upon them with a sprite, they will have a 
*possition in the game world and a function to call once the button has been pressed. 
*
*/

#include "defs.h"

template <class G>
class Button{

	// Data Members 

private:

	//! This will be used for the writing on the button. 
	std::string sButtonName;

	//! This will be used to display the writing on the button.
	sf::Text buttonText;

	//! This will be the visual representation of the button.
	sf::Sprite buttonSprite;

	//! This will be used to hold the font for the text. 
	sf::Font font;

	//! This will be used to hold the constant size of the text. 
	const unsigned int textSize = 30;

	//! This will hold the buttons current possition. 
	sf::Vector2f buttonPos; 

	//! This will hold the button's function, It will be called when the button is pressed. 
	std::function<int()> funcToCall;

	//! This will hold the button's function, It will be called when the button is pressed (Overloaded Version). 
	std::function<int(int)> funcToCallInt;

	int funcParam; 

	// Member Functions 

public:

	/*! Set Button Name :- This will be used to set the writing on the button. 
	/Param One is a string which will be the name of the button as well as the writing displayed on it. 
	/Param Two is a font which will dictate the style of the writing on the button. 
	*/
	int m_SetButtonName(std::string newName, std::string filePath)
	{

		if (!font.loadFromFile(filePath))
		{
			std::cout << "Error code 0001 :- Unable to find file" << std::endl;
		}

		else
		{
			std::cout << "Found and assigned Font at : " << filePath << "." << std::endl;

			buttonText.setFont(font);

			buttonText.setCharacterSize(textSize);

			sButtonName = newName;

			buttonText.setString(sButtonName);

			buttonText.setFillColor(sf::Color::Blue);
		}

		return 0;
	}

	/*! Set Function :- This will be used to set the button's function.
	/Param One is a function which will be saved locally.
	*/
	int m_SetFunction(std::function<int()> func)
	{
		funcToCall = func;

		return 0;
	}

	/*! Set Function (Overload) :- This will be used to set the button's function with an aditional parameter inside the function.
	/Param One is a function which will be saved locally.
	*/
	int m_SetFunction(std::function<int(int)> func, int whatParam)
	{
		funcToCallInt = func;

		funcParam = whatParam;

		return 0;
	}

	/*! Set Button Sprite :- This will be used to set the button's sprite. 
	/Param One is a texture which will be used to assign the appearance of the button. 
	/Param Two a float for the new width of the button.
	/Param three a float for the new height of the button.
	*/
	int m_SetButtonSprite(sf::Texture newTexture, float fNewWidth, float fNewHeight) 
	{
		buttonSprite.setTexture(newTexture);

		buttonSprite.setScale(fNewWidth, fNewHeight);

		return 0;
	}

	//! Set Button Pos :- This will be used to specify a location in the game world to be placed.
	/*!
	/Param One an unsinged float for the new X possition.
	/Param Two an unsinged float for the new Y possition.
	*/
	int m_SetButtonPos(float newXPos, float newYPos)
	{
		buttonPos.x = newXPos;
		buttonPos.y = newYPos;

		buttonSprite.setPosition(buttonPos);

		buttonText.setPosition(buttonPos.x + (buttonSprite.getGlobalBounds().width * 0.33f), buttonPos.y + (buttonSprite.getGlobalBounds().height * 0.1f));


		return 0;
	}
	

	//! Draw Button :- This will be used to draw the button on the current game window. 
	/*!
	/Param One a render target which the button and text will be drawn onto. 
	*/
	int m_DrawButton(sf::RenderWindow *currentDisplay)
	{

		if (buttonSprite.getTexture() != NULL && buttonText.getFont() != NULL)
		{
			currentDisplay->draw(buttonSprite);

			currentDisplay->draw(buttonText);

		}

		return 0;
	}


	//! Check For Press :- This will be used to check if the button has been pressed. 
	/*!
	/Param One a render widnow to constrain the mouse's possition to inside the window. 
	*/
	int m_CheckForPress(sf::RenderWindow * window)
	{
		if (sf::Mouse().getPosition(*window).x > buttonSprite.getPosition().x && sf::Mouse().getPosition(*window).x < (buttonSprite.getPosition().x + buttonSprite.getGlobalBounds().width))
		{
			if (sf::Mouse().getPosition(*window).y > buttonSprite.getPosition().y && sf::Mouse().getPosition(*window).y < (buttonSprite.getPosition().y + buttonSprite.getGlobalBounds().height))
			{
				if (sf::Mouse().isButtonPressed(sf::Mouse().Left))
				{
					std::cout << "Button Pressed" << std::endl;

					if (funcToCall != nullptr)
					{
						funcToCall();
					}
					else
					{
						funcToCallInt(funcParam);
					}
				}
			}
		}

		return 0;
	}

};
