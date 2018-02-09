#pragma once


/*!\file FontManager.h
*
*This will be used to manage all of the Fonts which will be used with in the game.
*
*/

//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

class FontManager
{
	// Constructor

public:

	//! This is the default constructor for this class.
	FontManager();



	// Deconstructor

public:

	//! This is the default deconstructor for this class.
	~FontManager();



	// Data Members 

private:

	//! This will be used to hold all of the different fonts within the game. 
	std::map<std::string, sf::Font> fontMap;

	// Member Functions

public:

	//! This will be used to add a new font into the font map.
	int m_AddFont(std::string sFontName, std::string filePath);

	//! This will be used to get a font from within the font map. 
	sf::Font m_GetFont(std::string sFontName);

};