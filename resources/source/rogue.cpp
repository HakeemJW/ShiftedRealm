#include "rogue.h"
#include <iostream>
#include <string>
#include <Log.h>

void rogue::setstat()
{
	health = 80;
	attack = 10;
	defense = 2;
	exp = 0;
}

void rogue::description()
{
	Print("You have chosen the path of the rogue!");
}


rogue::rogue()
{
}


rogue::~rogue()
{
}
