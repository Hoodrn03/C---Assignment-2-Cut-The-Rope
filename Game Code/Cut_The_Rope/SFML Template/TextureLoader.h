/*!\file TextureLoader.h
*
* This class will be used to load and store all of the textures in one place allowing for 
* easy access to the data, without needing to load from the file multiple times. 
*
*/

#pragma once

#include "defs.h"

class TextureLoader
{
	// Constructor 

public:

	TextureLoader();

	// Deconstructor 

public:

	~TextureLoader();

	// Data Members 

private:

	std::map<std::string, sf::Texture> m_TextureMap; 

	// Member Functions

public:

	void m_LoadTextureToMap(std::string filePath, std::string index);

	sf::Texture *m_GetTextureFromMap(std::string mapIndex); 

};