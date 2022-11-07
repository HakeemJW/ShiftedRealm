#include "character.h"
#include "story.h"
#include <thread>

/*main code*/
int main()
{
	story* s = nullptr;
	character* player = nullptr;
	
	s->intro();
	player->pickclass(player);
	player->description();
	player->namechar();
	player->setstat();
	player->readstat();
	s->keycommands();
	
	std::thread inputThread(&character::action, player, player);
	inputThread.join();
	
	return 0;
}