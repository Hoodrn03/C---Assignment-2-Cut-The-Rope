#include "FontManager.h"


//! Constructor :- This is the default constructor for this class 
/*!
/
*/
FontManager::FontManager()
{
}


//! Deconstructor :- This is the deconstructor for this class. 
/*!
/
*/
FontManager::~FontManager()
{
}


//! Add Font :- This will be used to add a new font into the font map. 
/*
/Param one is a string which will act as the name the font is accociated with.
/Param two is a file path of where to find the font.
*/
int FontManager::m_AddFont(std::string sFontName, std::string filePath)
{
	sf::Font fontToAdd;

	if (!fontToAdd.loadFromFile(filePath))
	{
		std::cout << "Error code 0001 :- Unable to find file" << std::endl;
	}
	else
	{
		std::cout << "Found and assigned Font." << std::endl;

		fontMap.insert(std::pair<std::string, sf::Font>(sFontName, fontToAdd));
	}


	return 0;
}

//! Get Font :- This will be used to get access to a font from within the map. 
/*
/Param one is a string, it will check the map for that string to find the correct font.
*/
sf::Font FontManager::m_GetFont(std::string sFontName)
{

	std::map<std::string, sf::Font>::iterator it;

	it = fontMap.find(sFontName);

	if (it != fontMap.end())
	{
		std::cout << "Font : " << sFontName << " Found." << std::endl;

		return fontMap.at(sFontName);;
	}
	else
	{
		std::cout << "Trying to use a file which has not yet been assigned." << std::endl;

		return sf::Font();
	}
}