#pragma once

/*!\file ToggleButton.h
*
*This will be used as a template for all of the toggle buttons within the game.
*A toggle button will act like any other buttons but with a key difference it will
*display weather the option is turned on or off, a example of this could be a toggle 
*for fullscreen; it is either on or off. 
*
*/

#include "defs.h"

template <class G>
class ToggleButton
{
	// Data Members 

private:

	//! This will load the texture of the button for displaying.
	sf::Texture toggleOnTexture;

	//! This will hold the button's appearance when the button is on.
	sf::Sprite toggleSpriteOn;

	//! This will load the texture of the button for displaying.
	sf::Texture toggleOffTexture;

	//! This will hold the button's appearance when the button is off.
	sf::Sprite toggleSpriteOff;

	//! This will hold the button's font (the appearance of the text). 
	sf::Font buttonFont;

	// This will be used to display writing on the button. 
	sf::Text buttonText;

	//! This will be the string the button's text will display. 
	std::string sButtonWriting;

	//! This will determine whether the button has been toggled or not? 
	bool bButtonToggle = false; 

	//! This will be the possition of the button in the game window. 
	sf::Vector2f buttonPos;

	//! This will hold the function which will be called when the button is pressed. 
	std::function<int(bool)> func;

	// Member Functions

public:

	//! Set Button Sprites :- This will be used to assign both the sprites for this button.
	/*!
	/Param One a texture representing the sprite when it has been toggled on. 
	/Param Two a texture representing the sprite when it has been toggled off. 
	/Param Three a float for the button's width.
	/Param Four a float for the button's height.
	*/
	int m_SetButtonSprits(std::string buttonOnFilePath, std::string buttonOffFilePath, float fNewWidth, float fNewHeight)
	{
		if (!toggleOnTexture.loadFromFile(buttonOnFilePath))
		{
			std::cout << "Error Code 0001 :- Unable to find file" << std::endl;
		}
		else
		{

			if (!toggleOffTexture.loadFromFile(buttonOffFilePath))
			{
				std::cout << "Error Code 0001 :- Unable to find file" << std::endl;
			}
			else
			{
				toggleSpriteOn.setTexture(toggleOnTexture);

				toggleSpriteOff.setTexture(toggleOffTexture);

				toggleSpriteOn.setScale(fNewWidth, fNewHeight);

				toggleSpriteOff.setScale(fNewWidth, fNewHeight);
			}
		}

		return 0;
	}

	//! Set Toggle Pos :- This will be used to set the current possition of the toggle.
	/*!
	/Param One a vector2f repersenting the possition within the game world. 
	*/
	int m_SetTogglePos(sf::Vector2f newPos)
	{

		toggleSpriteOn.setPosition(newPos.x, newPos.y);

		toggleSpriteOff.setPosition(newPos.x, newPos.y);

		buttonText.setPosition(newPos.x, newPos.y);

		return 0;

	}

	//! Set Toggle State :- This will be used to set the current state of the of the toggle.
	/*!
	/Param One a bool for whether the button is true or false. 
	*/
	int m_SetToggleState(bool bCurrentState)
	{
		bButtonToggle = bCurrentState;

		return 0;
	}

	/*! Set Button Name :- This will be used to set the writing on the button.
	/Param One is a string which will be the name of the button as well as the writing displayed on it.
	/Param Two is a font which will dictate the style of the writing on the button.
	*/
	int m_SetButtonName(std::string newName, std::string filePath)
	{

		if (!buttonFont.loadFromFile(filePath))
		{
			std::cout << "Error Code 0001 :- Unable to find file" << std::endl;

			return 1;
		}

		else
		{
			buttonText.setFont(buttonFont);

			sButtonWriting = newName;

			buttonText.setString(sButtonWriting);

			buttonText.setFillColor(sf::Color::Blue);

		}

		return 0;
	}

	//! Set Toggle Function :- This will be used to assign a function to the toggle. 
	/*!
	/Param One a function which will be activated when the toggle is pressed. 
	*/
	int m_SetToggleFunction(std::function<int(bool)> newFunc)
	{
		func = newFunc;

		return 0;
	}

	//! Draw Button :- This will be used to draw the button on the current game window. 
	/*!
	/Param One a render target which the button and text will be drawn onto.
	*/
	int m_DrawButton(sf::RenderWindow *currentDisplay)
	{

		if (toggleSpriteOn.getTexture() != NULL && toggleSpriteOff.getTexture() != NULL  && buttonText.getFont() != NULL)
		{
			if (bButtonToggle == true)
			{		
				currentDisplay->draw(toggleSpriteOn);	
			}
			else if (bButtonToggle == false)
			{
				currentDisplay->draw(toggleSpriteOff);
			}

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
		if (sf::Mouse().getPosition(*window).x > toggleSpriteOn.getPosition().x && sf::Mouse().getPosition(*window).x < (toggleSpriteOn.getPosition().x + toggleSpriteOn.getGlobalBounds().width))
		{
			if (sf::Mouse().getPosition(*window).y > toggleSpriteOn.getPosition().y && sf::Mouse().getPosition(*window).y < (toggleSpriteOn.getPosition().y + toggleSpriteOn.getGlobalBounds().height))
			{
				if (sf::Mouse().isButtonPressed(sf::Mouse().Left))
				{
					if (func != nullptr)
					{
						if (bButtonToggle == true)
						{
							func(true);

							bButtonToggle = !bButtonToggle;
						}
						else
						{
							func(false);

							bButtonToggle = !bButtonToggle;
						}
					}
					else
					{
						std::cout << "Error Code 0002 :- No Function Assigned" << std::endl;

						return 1;
					}
				}
			}
		}

		return 0;
	}

};
