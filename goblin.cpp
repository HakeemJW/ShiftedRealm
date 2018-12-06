#include "goblin.h"
#include <iostream>
#include <string>

using namespace std;


goblin::goblin()
{
}


goblin::~goblin()
{
}

void goblin::e_description()
{
	cout << "A goblin appears" << endl;
}

void goblin::e_setstat()
{
	e_health = 20;
	e_attack = 14;
	e_defense = 0;
	e_exp = 10;
}