#include "character.h"
#include <iostream>
#include <string>
#include "conio.h"

using namespace std;
int gold = 100;

void character::pickclass()
{
	cout << "What class would you like to play?" << endl;
	cout << endl;
	cout << "Warrior (1) \t Rogue (2) \t Mage (3)" << endl;
}


void character::namechar()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	cout << endl;
	cout << "Your name is " << name << endl;
}

void character::readstat()
{
	cout << "Your health is " << health << endl;
	cout << "Your attack is " << attack << endl;
	cout << "Your defense is " << defense << endl;
}

void character::action()
{
	#define KEY_ESC 27
	#define KEY_A 97
	#define KEY_M 109
	int x;
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
				cout << "You have " << gold << " gold\n\n";
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
}

character::character()
{
}


character::~character()
{
}
