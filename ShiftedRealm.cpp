#include <iostream>
#include "character.h"
#include "warrior.h"
#include "rogue.h"
#include "mage.h"
#include "story.h"
#include "Windows.h"
#include "conio.h"
#include "combat.h"
#include "goblin.h"

/*main code*/

using namespace std;
int clas;
int x;

int main()
{
	story* s = nullptr;
	character* c = nullptr;
	combat* com = nullptr;
	s->intro();
	c->pickclass();
	cin >> clas;
	switch (clas)
	{
		case 1:
		{
			warrior* w = new warrior();
			c = w;
		}
			break;
		case 2:
		{
			rogue* r = new rogue();
			c = r;
		}
			break;
		case 3:
		{
			mage* m = new mage();
			c = m;
		}
			break;
			default: return 0;
		}
	c->description();		
	c->namechar();		
	c->setstat();
	c->readstat();
	s->keycommands();
	com->fight();
	//c->action();
	cin >> x;
	return 0;
}