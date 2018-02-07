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

	// Member Functions 

public:

	/*! Set Button Name :- This will be used to set the writing on the button. 
	/Param One is a string which will be the name of the button as well as the writing displayed on it. 
	/Param Two is a font which will dictate the style of the writing on the button. 
	*/
	int m_SetButtonName(std::string newName, sf::Font newFont)
	{
		sButtonName = newName;

		buttonText.setFont(newFont);

		buttonText.setString(sButtonName);

		return 0;
	}

	/*! Set Button Sprite :- This will be used to set the button's sprite. 
	/Param One is a texture which will be used to assign the appearance of the button. 
	*/
	int m_SetButtonSprite(sf::Texture newTexture)
	{
		buttonSprite.setTexture(newTexture);

		return 0;
	}
	
	//! Draw Button :- This will be used to draw the button on the current game window. 
	/*!
	/Param One a render target which the button and text will be drawn onto. 
	*/
	int m_DrawButton(sf::View currentDisplay)
	{
		currentDisplay.draw(buttonSprite);
		currentDisplay.draw(buttonText);
		
		return 0;
	}

};
