/*!\file defs.h
*
* This file will contain all of the includes which will be used throughout the 
* project. 
*
* This will also contain all of the definitions for the game, some items which will be used 
* throughout the project. Items like the a simple def for PI. 
*
*/

#pragma once

// Printing to the Console.
#include <iostream>

// Game Window/Graphics.
#include <SFML\Graphics.hpp>

// Game Physics.
#include <Box2D\Box2D.h>

#ifndef HALF
// This will enable something to easily halfed (multiplyed by 0.5).
#define HALF 0.5f
#endif 

#ifndef PI
// This will create a definition for PI.
#define PI 3.14f
#endif

#ifndef RADTODEG
// This will allow for the easy conversion between radians to degrees; (Multiply origional value by this).
#define RADTODEG 180 / PI
#endif 

#ifndef DEGTORAD
// This will allow for the easy conversion between degrees to radians; (Multiply origional value by this). 
#define DEGTORAD PI / 180
#endif 

