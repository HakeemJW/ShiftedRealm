#include "warrior.h"
#include <iostream>
#include <string>

/*This is where the stats and description for the warrior class lives.*/

using namespace std;

void warrior::description()
{
	cout << "You have chosen the path of the warrior!" << endl;
	cout << "The warrior is strong, brave, and prefers close quarters combat." << endl;
}

void warrior::setstat()
{
	health = 100;
	attack = 10;
	defense = 0;
	exp = 0;
}


warrior::warrior()
{
}


warrior::~warrior()
{
}
