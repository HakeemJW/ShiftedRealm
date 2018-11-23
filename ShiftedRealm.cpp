#include <iostream>
#include "character.h"
#include "warrior.h"
#include "rogue.h"
#include "mage.h"
#include "story.h"
#include "Windows.h"
#include "conio.h"



using namespace std;
int clas = 0;
int x;

int main()
{
	story* s = nullptr;
	character* c = nullptr;
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
	c->action();
	cin >> x;
	return 0;
}