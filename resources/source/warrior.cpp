#include "warrior.h"
#include <iostream>
#include <string>
#include <Log.h>

/*This is where the stats and description for the warrior class lives.*/
void warrior::description()
{
	/*Print("You have chosen the path of the warrior!");
	Print("The warrior is strong, brave, and prefers close quarters combat.");*/
}

void warrior::setstat()
{
	/*health = 100;
	attack = 10;
	defense = 0;
	exp = 0;*/
}


warrior::warrior()
{
	Print("You have chosen the path of the warrior!");
	Print("The warrior is strong, brave, and prefers close quarters combat.");
	
	health = 100;
	attack = 10;
	defense = 0;
	exp = 0;
}


warrior::~warrior()
{
}
