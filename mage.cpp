#include "mage.h"
#include <iostream>
#include <string>

using namespace std;


void mage::description()
{
	cout << "You have chosen the path of the mage!" << endl;
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
