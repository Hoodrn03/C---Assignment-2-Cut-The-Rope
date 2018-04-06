/*!\file Cut The Rope
*
* This project is for my C++ assignemnt wherein I need to create a 2D puzzler,
* from the breif I decided to choose an exsisting game to base my project on. 
* The game Cut the Rope seemed like a good choice, it encompaces the entirety of 
* what needs to be done but also poses a decent amount of chalange to make. 
* 
*
*/


#include "defs.h"

#include "GameLoop.h"

int main()
{
	GameLoop m_GameLoop;

	// Begin the game. 
	m_GameLoop.m_MainGameLoop();

	return 0;
}