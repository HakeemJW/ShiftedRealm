#include <iostream>
#include "combat.h"
#include "character.h"
#include "enemy.h"
#include <math.h>
#include "goblin.h"
using namespace std;
/*This is a theoretical section of code that determines the flow of combat.*/
enemy* e;
character* c;

void combat::fight()
{
	goblin* g = new goblin();
	e = g;
	e->e_setstat();
	int b;
	while (e->e_health > 0)
	{
		cout << "Do you attack the enemy?\n";
		cout << "Yes(1) \t No(2)\n";
		cin >> b;
		if (b == 1)
			e->e_health = e->e_health - c->attack;
		
	}
}

combat::combat()
{
}


combat::~combat()
{
}
