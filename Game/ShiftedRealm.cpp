#include "character.h"
#include "story.h"
#include "combat.h"
#include <thread>


/*main code*/
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
	
	std::thread inputThread(&character::action,c,c);
	inputThread.join();
	
	return 0;
}