#include "story.h"
#include <iostream>

/*This code is where the general opening text lives.*/

using namespace std;

void story::intro()
{
	cout << "Welcome to Shifted Realms!" << endl;
	cout << "This is a game about adventure and dungeon crawl." << endl;
	cout << "Beware for this adventure is not for the faint of heart." << endl;
	cout << "Now then, let's begin!" << endl;
	cout << endl;
}

void story::keycommands()
{
	cout << "Press" << " M " << "at any time to open the menu.\n\n";
}

story::story()
{
}


story::~story()
{
}
