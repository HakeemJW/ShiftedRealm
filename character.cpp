#include "character.h"
#include <iostream>
#include <string>
#include "conio.h"
#include "combat.h"

/*	
	This is a large section of code that is used for controlling the character's actions.
	Currently needs to be further simplified.
*/

using namespace std;
int gold = 100;
string location[4] = { "Dornin", "Fanrir", "Jagel", "Winona" };
string current_location = location[0];
string weapons[4] = { "Sword", "Axe", "Daggar", "Mace" };
string cost[4] = { "10", "15", "20", "25" };
string armor[4] = {"Chain Mail", "Plate Mail", "Full Plate", "Robes"};
string equipment[4] = { "Rope", "Torch", "Pole", "Hooks" };
string potions[4] = { "Healing", "Fire Breathing", "Stealth", "Strength" };
combat* com = nullptr;

//Player class selection
void character::pickclass()
{
	cout << "What class would you like to play?" << endl;
	cout << endl;
	cout << "Warrior (1) \t Rogue (2) \t Mage (3)" << endl;
}

//Player names character
void character::namechar()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	cout << endl;
	cout << "Your name is " << name << endl;
}

//Reads out character starting stats
void character::readstat()
{
	cout << "Your health is " << health << endl;
	cout << "Your attack is " << attack << endl;
	cout << "Your defense is " << defense << endl;
}

//Prints Character Equipped Items
void character::print_equipped()
{
	cout << "Weapon Equipped: " << weapon_equipped << endl;
	cout << "Armor Equipped: " << armor_equipped << endl;
}

//PRints Characters Owned Items
void character::print_equipment_owned()
{
	cout << "Slot \tWeapons Owned \t Armor Owned \t Equipment\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "(" << i << ")" << "\t" << weapons_owned[i] << "\t" << armor_owned[i] << "\t" << equipment_owned[i] << endl;
	}
}

void character::equip()
{
	int x,y;
	char e;
	cout << "Would you like to eqip an item? (Y/N)\n";
	cin >> e;
	if (e == 'Y' || e == 'y')
	{
		cout << "What would you like to equip?\n";
		cout << "Weapons (1) \t Armor(2)\n";
		cin >> x;
		switch (x)
		{
			case 1:
				for (int i = 0; i < 5; i++)
				{
					cout << "(" << i << ")" << "\t" << weapons_owned[i] << endl;
				}
				cout << "Which slot?\n";
				cin >> y;
				weapon_equipped = weapons_owned[y];
				cout << weapon_equipped << " is now equipped.\n";
				break;
			case 2:
				for (int i = 0; i < 5; i++)
				{
					cout << "(" << i << ")" << "\t" << armor_owned[i] << endl;
				}
				cout << "Which slot?\n";
				cin >> y;
				armor_equipped = armor_owned[y];
				cout << armor_equipped << " is now equipped.\n";
				break;
		}
				
	}
}

//The Main UI
void character::action(character* c)
{
	//Defined ASCII key input
	#define KEY_ESC 27
	#define KEY_A 97
	#define KEY_M 109
	int x;
	int j = 0;
	char key = _getch();
	int value = key;

	while (value != KEY_ESC)
	{
		switch (_getch())
		{
		case KEY_M: //Opens Menu
			cout << "What would you like to do\n\n";
			cout << "Shop(1)  Travel(2)  Adventure(3)  Rest(4)  Check Stats(5)  Check Inventory(6)" << endl;
			cin >> x;
			switch (x)
			{
			case 1: //Shopping Options
				cout << "You have " << gold << " gold\n\n";
				cout << "What do you desire?\n\n";
				cout << "Weapons (1) \t Armor(2) \t Equipment(3) \t Potions(4)\n\n";
				int f;
				cin >> f;
				switch (f) // Prints list of all available items for purchase
				{
				case 1:
					int p;
					for (int i = 0; i < 4; i++)
					{
						cout << "(" << i << ")" << weapons[i];
						cout << " (" << cost[i] << ")\n";
					}
					//Making the item purchase
					cout << "Which weapon would you like?\n";
					cin >> p;
					cout << "Which weapon slot would you like to overwrite?" << endl;
					int n;
					cin >> n;
					weapons_owned[n] = weapons[p];
					break;
				case 2:
					for (int i = 0; i < 4; i++)
					{
						cout << "(" << i << ")" << armor[i];
						cout << " (" << cost[i] << ")\n";
					}
					break;
				case 3:
					for (int i = 0; i < 4; i++)
					{
						cout << "(" << i << ")" << equipment[i];
						cout << " (" << cost[i] << ")\n";
					}
					break;
				case 4:
					for (int i = 0; i < 4; i++)
					{
						cout << potions[i];
						cout << " (" << cost[i] << ")\n";
					}
					break;
				default: break;
				}
				break;
			case 2: //Alow player to move between locations
				int location_choice;
				cout << "You are currently located in " << current_location << ".\n\n";
				cout << "Where would you like to go?\n\n";
				for (int i = 0; i < 4; i++)
				{
					cout << location[i];
					cout << " (" << j << ")\n\n";
					j++;
				}
				j = 0;
				cin >> location_choice;
				current_location = location[location_choice];
				cout << "Your new location is " << current_location << "!\n\n";
				break;
			case 3://Story Progression
				cout << "What type of adventure do you seek?\n\n";
				cout << "Bounty(1) \t Dungeon Crawl(2)\n\n";
				int fp; 
				cin >> fp;
				switch (fp)
				{
				case 1:
					cout << "Here are the available bounties in this town.\n\n";
					com->fight(c);
					break;
				case 2:
					cout << "Here is a list of nearby dungeons.\n\n";
					break;
				default: break;
				}
				break;
			case 4:
				cout << "You are fully rested\n\n";
				break;
			case 5://Allows player to check stats manually
				cout << "Health: " << c->health << endl;
				cout << "Attack: " << c->attack << endl;
				cout << "Defense: " << c->defense << endl;
				cout << "Experience: " << c->exp << endl;
				break;
			case 6://Allows Players to view and equip items
				print_equipped();
				print_equipment_owned();
				equip();
			default: break;
			}
		}
	}
	key = _getch();
	value = key;
}

void character::print_location()
{
	cout << current_location << endl;
}

character::character()
{
}


character::~character()
{
}
