
/*!\mainpage Ball Fall (Object Oriented Design and Development Assignment 2)
*
*This program will contain the completed game will full functionality. The game must be 
*include both SFML and a physics system within the game, I will use the library Box2D 
*for the physics within my game. 
*
*My game will be based off of the already exsisting game Cut the rope, and will feature 
*similar mechanics. The player will have to cut ropes within the game using their mouve to
*make their ball fall into the end point, whilst attempting to solve puzzles and avoiding 
*obsticals. 
*
*/


//! This will be used to gain access to all of the linked libraries which will be used everywhere in the program. 
#include "defs.h" 

//! This will allow for the game to be run. 
#include "GameLoop.h"

//! main : The entry point for the program.  
int main()
{
	Gameloop clGameLoop;

	clGameLoop.m_MainMenu();

	return 0;
}