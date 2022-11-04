#include "mage.h"
#include <iostream>
#include <string>
#include <Log.h>

void mage::description()
{
	Print("You have chosen the path of the mage!");
}

void mage::setstat()
{
	health = 60;
	attack = 14;
	defense = 0;
	exp = 0;
}


mage::mage()
{
}


mage::~mage()
{
}
