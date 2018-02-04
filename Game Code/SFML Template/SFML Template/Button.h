#pragma once

/*!\file Button.h
*
*This is a template for a button. It will be used to easily make buttons 
*within an SFML game. 
*
*/

//! This will allow accessto vital includes which will be used throughout the project. 
#include "defs.h"

template <class G>
class Button
{
	// Constructor 

public:

	//! This is the default constructor for the button.
	Button();

	//! This is an overloaded Constructor.
	/*
	/This takes a string and will be used to set the text which will be displayed on the button. 
	*/
	Button(std::string sNewText);



	// Deconstructor 

public: 

	//! This is the default deconstructor for the button.
	~Button();

	// Data Members 

private:

	std::string sButtonWriting;

	// Member Functions 

public:

};


//! This is the default constructor for the button
template<class G>
inline Button<G>::Button()
{

}

//! This is an overloaded Constructor
/*
/This takes a string and will be used to set the text which will be displayed on the button.
*/
template<class G>
inline Button<G>::Button(std::string sNewText)
{

}

//! This is the default deconstructor for the button.
template<class G>
inline Button<G>::~Button()
{
}
