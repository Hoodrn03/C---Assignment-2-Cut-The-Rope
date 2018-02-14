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
	std::map<std::string, std::string> textureMap;

	// Member Functions

public:

	//! This will be used to add a new texture into the map.
	int m_AddTexture(std::string sTextureName, std::string filePath);

	//! This will be used to get access to a texture from within the map. 
	std::string *m_GetTexture(std::string sTextureName);

};