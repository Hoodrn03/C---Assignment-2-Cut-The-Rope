#pragma once

/*!\file TextureManager.h
*
*This will be used to manage all of the textures which will be used with in the game. 
*
*/

//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

class TextureManager
{
	// Constructor

public:

	//! This is the default constructor for this class.
	TextureManager();



	// Deconstructor
	
public:

	//! This is the default deconstructor for this class.
	~TextureManager();



	// Data Members 

private:

	//! This will be used to hold references to all of the textures which will be used in the game. 
	std::map<std::string, sf::Texture> textureMap;

	//! This will be used to hold all of the different fonts within the game. 
	std::map<std::string, sf::Font> fontMap;

	// Member Functions

public:

	//! This will be used to add a new texture into the map.
	int m_AddTexture(std::string sTextureName, std::string filePath);

	//! This will be used to get access to a texture from within the map. 
	sf::Texture m_GetTexture(std::string sTextureName);

	//! This will be used to add a new font into the font map.
	int m_AddFont(std::string sFontName, std::string filePath);

	//! This will be used to get a font from within the font map. 
	sf::Font m_GetFont(std::string sFontName);

};