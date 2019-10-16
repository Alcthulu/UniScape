#ifndef __TEXTCONF_H
#define __TEXTCONF_H


#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

// COLOR CODES:

#define	BLACK			0
#define	BLUE			1//TITLES/LOOSE
#define	GREEN			2//OBJECTS AND OTHERS IN ROOM DESCRIPTION/WIN
#define CYAN			3
#define	RED				4
#define	MAGENTA			5
#define	BROWN			6
#define	LIGHTGRAY		7
#define DARKGRAY		8//GUARD/KNIGHT
#define	LIGHTBLUE		9
#define	LIGHTGREEN		10
#define	LIGHTCYAN		11//PRINCE
#define	LIGHTRED		12
#define	LIGHTMAGENTA	13
#define YELLOW			14//PLAYER
#define	WHITE			15//NARRATOR

// TEXT SPEED

#define DESCRIPTIONS	10
#define CHARACTERS		30


// FUNCTIONS:

//
// Set the colour of the letters or the background on the console.
//
void SetColor(int textC, int backC = 0);

//
// Prints the string toPrint character by character at the desired speed
//
void slowPrint(string toPrint, int speed);

#endif // !__TEXTCONF_H