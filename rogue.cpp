#include "rogue.h"
#include <iostream>
#include <string>

using namespace std;


void rogue::setstat()
{
	health = 80;
	attack = 10;
	defense = 2;
	exp = 0;
}

void rogue::description()
{
	cout << "You have chosen the path of the rogue!" << endl;
}


rogue::rogue()
{
}


rogue::~rogue()
{
}
