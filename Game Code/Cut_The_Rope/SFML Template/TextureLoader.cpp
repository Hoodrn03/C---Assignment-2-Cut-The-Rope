/*!\file TextureLoader.cpp
*
* This will house all of the function declarations for the class TextureLoader.
*
*/

#include "TextureLoader.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
TextureLoader::TextureLoader()
{
}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
TextureLoader::~TextureLoader()
{
}

//-------------------------------------------------------------

/*! Load Texture to Map : This will be used to easily add a new texture to the map with an index to find it with.  
\Param One - string : The file path of where to find the texture. 
\Param Two - string : The index to find the texture with later. 
*/
void TextureLoader::m_LoadTextureToMap(std::string filePath, std::string index)
{
	sf::Texture temp; 

	if (!temp.loadFromFile(filePath))
	{
		std::cout << "Error Code 0004 - Error Loading texture from file : " << filePath << std::endl;
	}

	else
	{
		std::pair<std::string, sf::Texture> myPair (index, temp);

		std::cout << "Texture Indexed to : " << index << std::endl;

		m_TextureMap.insert(myPair); 
	}

}

//-------------------------------------------------------------

/*! Get Texture From Map : This will be used to get a refernce to a texture from the map. 
\{Param One - string : The index of what texture you are looking for.
*/
sf::Texture *TextureLoader::m_GetTextureFromMap(std::string mapIndex)
{
	sf::Texture retTexture; 

	std::map<std::string, sf::Texture>::iterator it; 

	it = m_TextureMap.find(mapIndex); 

	if (it != m_TextureMap.end())
	{
		return &m_TextureMap.find(mapIndex)->second;
	}
	else
	{
		std::cout << "Error Code 0005 - Unable to find item in texture map : " << mapIndex << std::endl; 
	}

	return &retTexture;
}
