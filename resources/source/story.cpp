#include "story.h"
#include <iostream>
#include <Log.h>

/*This code is where the general opening text lives.*/

void story::intro()
{
	Print("Welcome to Shifted Realms!");
	Print("This is a game about adventure and dungeon crawl.");
	Print("Beware for this adventure is not for the faint of heart.");
	Print("Now then, let's begin!\n");
	
}

void story::keycommands()
{
	Print("Press M at any time to open the menu.\n");
}

story::story()
{
}


story::~story()
{
}
