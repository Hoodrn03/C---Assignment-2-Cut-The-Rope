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
		std::cout << "Found and assigned." << std::endl;

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

