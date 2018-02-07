#include "TextureManager.h"

//! Constructor :- This is the default constructor for this class 
/*!
/
*/
TextureManager::TextureManager()
{

}

//! Deconstructor :- This is the deconstructor for this class. 
/*!
/
*/
TextureManager::~TextureManager()
{
}


//! Add Texture :- This will be used to add a texture into the texture map.
/*
/Param one is a string which will be used as a name the texture will be associated with. 
/Param two is the file path of where to find the texture. 
*/
int TextureManager::m_AddTexture(std::string sTextureName, std::string filePath)
{
	sf::Texture textureToAdd; 

	if (!textureToAdd.loadFromFile(filePath))
	{
		std::cout << "Error code 0001 :- Unable to find file" << std::endl;
	}
	else
	{
		std::cout << "Found and assigned Texture." << std::endl;

		textureMap.insert(std::pair<std::string, sf::Texture>(sTextureName, textureToAdd));
	}

	return 0;
}

//! Get Texture :- This is used to get access to a texture from within the texture map.
/*
/Param one a string which will be used to find the corrosponding texture. 
*/

sf::Texture TextureManager::m_GetTexture(std::string sTextureName)
{
	std::map<std::string, sf::Texture>::iterator it; 

	it = textureMap.find(sTextureName);

	if (it != textureMap.end())
	{
		std::cout << "Texture : " << sTextureName << " Found." << std::endl;

		return textureMap[sTextureName];
	}
	else
	{
		std::cout << "Trying to use a file which has not yet been assigned." << std::endl;

		return sf::Texture();
	}
}


//! Add Font :- This will be used to add a new font into the font map. 
/*
/Param one is a string which will act as the name the font is accociated with. 
/Param two is a file path of where to find the font.
*/
int TextureManager::m_AddFont(std::string sFontName, std::string filePath)
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
sf::Font TextureManager::m_GetFont(std::string sFontName)
{

	std::map<std::string, sf::Font>::iterator it;

	it = fontMap.find(sFontName);

	if (it != fontMap.end())
	{
		std::cout << "Font : " << sFontName << " Found." << std::endl;

		return fontMap[sFontName];
	}
	else
	{
		std::cout << "Trying to use a file which has not yet been assigned." << std::endl;

		return sf::Font();
	}
}

