#include <iostream>
#include "combat.h"
#include "character.h"
#include "enemy.h"
#include "goblin.h"
#include <Log.h>

/*This is a theoretical section of code that determines the flow of combat.*/
enemy* e;

void combat::fight(character* c)
{
	
	goblin* g = new goblin();
	e = g;
	e->e_setstat();
	int b;
	while (e->e_health > 0)
	{
		Print("Do you attack the enemy?\n");
		Print("Yes(1) \t No(2)\n");
		std::cin >> b;
		if (b == 1)
		{
			e->e_health = (e->e_health - c->attack);
		}
		Print2("Health remaining: ",e->e_health);
		c->exp += e->e_exp;
	}
}

combat::combat()
{
}


combat::~combat()
{
}
