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

	char key = _getch();
	int value = key;

	while (value != KEY_ESC)
	{
		switch (_getch())
		{
		case KEY_A:
			cout << "What would you like to do\n\n";
			cin >> x;
			switch (x)
			{
				case 1:
					cout << "Where would you like to travel\n\n";
					break;
			}

			
		}
	}

	cin >> x;
	return 0;

	


}