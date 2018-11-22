#include <iostream>
#include "character.h"
#include "warrior.h"
#include "rogue.h"
#include "mage.h"
#include "story.h"
#include "Windows.h"
#include "conio.h"



using namespace std;

#define KEY_ESC 27
#define KEY_A 97
#define KEY_M 109

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

	char key = _getch();
	int value = key;

	while (value != KEY_ESC)
	{
		switch (_getch())
		{
		case KEY_M:
			cout << "What would you like to do\n\n";
			cout << "Shop(1) \t Travel(2) \t Adventure(3) \t Rest(4)" << endl;
			cin >> x;
			switch (x)
			{
				case 1:
					cout << "You have gold\n\n";
					break;
				case 2:
					cout << "Where would you like to go?\n\n";
					break;
				case 3: 
					cout << "What type of adventure do you seek?\n\n";
					break;
				case 4:
					cout << "You are fully rested\n\n";
					break;
				default: break;
			}
		}
	}

	key = _getch();
	value = key;

	cin >> x;
	return 0;

	


}