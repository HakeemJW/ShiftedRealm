#include <iostream>
#include "character.h"
#include "story.h"
#include "Windows.h"
#include "conio.h"
#include "combat.h"


/*main code*/

int x;

int main()
{
	story* s = nullptr;
	character* c = nullptr;
	combat* com = nullptr;
	s->intro();
	c->pickclass(c);
	c->description();
	c->namechar();
	c->setstat();
	c->readstat();
	s->keycommands();
	c->action(c);
	std::cin >> x;
	return 0;
}