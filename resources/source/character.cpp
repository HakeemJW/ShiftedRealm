#include "character.h"
#include "warrior.h"
#include "rogue.h"
#include "mage.h"
#include <iostream>
#include <string>
#include "conio.h"
#include "combat.h"
#include <Log.h>
#include <chrono>
#include <thread>
#include <items.h>

/*	
	This is a large section of code that is used for controlling the character's actions.
	Currently needs to be further simplified.
*/

combat* com = nullptr;

character::character()
{
}


character::~character()
{
}

/**
 * Player class selection.
 *
 * @param Player object to be overwritten by subclass.
 * @return None.
 */
void character::pickclass(character*& c)
{
	int classChoice;
	Print("What class would you like to play?\n");
	Print("Warrior (1) \t Rogue (2) \t Mage (3)\n");
	std::cin >> classChoice;
	switch (classChoice)
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
	default:
	{
		Print("Not a supported answer");
		c->pickclass(c);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}


/**
 * Player names character.
 *
 * @param None.
 * @return None.
 */
void character::namechar()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string name;
	Print("What is your name?");
	std::getline(std::cin,name);
	Print("\n");
	Print2("Your name is ",name);
}


/**
 * Reads out character starting stats
 *
 * @param None.
 * @return None.
 */
void character::readstat()
{
	Print2("Your health is ", health);
	Print2("Your attack is ", attack);
	Print2("Your defense is ", defense);
}


/**
 * Prints Character Equipped Items
 *
 * @param None.
 * @return None.
 */
void character::print_equipped()
{
	Print2("Weapon Equipped: ", weapon_equipped);
	Print2("Armor Equipped: ",armor_equipped);
}


/**
 * Prints Characters Owned Items
 *
 * @param None.
 * @return None.
 */
void character::print_equipment_owned()
{
	Print("Slot \tWeapons Owned \t Armor Owned \t Equipment\n");
	for (int i = 0; i < 5; i++)
	{
		std::cout << "(" << i << ")" << "\t" << weapons_owned[i] << "\t" << armor_owned[i] << "\t" << equipment_owned[i] << std::endl;
	}
}

/**
 * Gives player the option to equip items.
 *
 * @param player object to be modified.
 * @return None.
 */
void character::equip()
{
	int equipChoice,equipSlot;
	char confirmEquip;
	Print("Would you like to eqip an item? (Y/N)\n");
	std::cin >> confirmEquip;
	if (confirmEquip == 'Y' || confirmEquip == 'y')
	{
		Print("What would you like to equip?\n");
		Print("Weapons (1) \t Armor(2)\n");
		std::cin >> equipChoice;
		switch (equipChoice)
		{
			case 1:
				for (int i = 0; i < 5; i++)
				{
					std::cout << "(" << i << ")" << "\t" << weapons_owned[i] << std::endl;
				}
				Print("Which slot?");
				std::cin >> equipSlot;
				weapon_equipped = weapons_owned[equipSlot];
				Print2(weapon_equipped," is now equipped.");
				break;
			case 2:
				for (int i = 0; i < 5; i++)
				{
					std::cout << "(" << i << ")" << "\t" << armor_owned[i] << std::endl;
				}
				Print("Which slot?");
				std::cin >> equipSlot;
				armor_equipped = armor_owned[equipSlot];
				Print2(armor_equipped," is now equipped.");
				break;
		}		
	}
}

/**
 * Opens menu with different action options.
 *
 * @param player object to be modified.
 * @return None.
 */
void character::action(character* c)
{

	//Defined ASCII key input
	#define KEY_ESC 27	///< Define ESC key
	#define KEY_A 97	///< Define 'A' key
	#define KEY_M 109	///< Define 'M' key
	
	int input;
	char key = _getch();
	int value = key;
	
	while (true)
	{
		while (value != KEY_ESC)
		{
			switch (_getch())
			{
			case KEY_M: //Opens Menu
				Print("What would you like to do\n");
				Print("Shop(1)  Travel(2)  Adventure(3)  Rest(4)  Check Stats(5)  Check Inventory(6)");
				std::cin >> input;
				switch (input)
				{
				case 1: //Shopping Options
					shop(c);
					break;
				case 2: //Alow player to move between locations
					changeLocation(c);
					break;
				case 3://Story Progression
					storyProgression(c);
					break;
				case 4:
					Rest();
					break;
				case 5://Allows player to check stats manually
					printStats(c);
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

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}


/**
 * Print player's location.
 *
 * @param player object.
 * @return None.
 */
void character::print_location(character* c)
{
	Print(c->currentLocation);
}


/**
 * Changes player's location.
 *
 * @param player object to be modified.
 * @return None.
 */
void character::changeLocation(character* c)
{
	int location_choice;
	int j = 0;
	Print2("You are currently located in ", c->currentLocation);
	Print("Where would you like to go?\n");
	for (int i = 0; i < 4; i++)
	{
		Print(location[i]);
		std::cout << " (" << j << ")\n\n";
		j++; 
	}
	j = 0;
	std::cin >> location_choice;
	c->currentLocation = location[location_choice];
	std::cout << "Your new location is " << c->currentLocation << "!\n\n";
}

/**
 * Prints player's stats.
 *
 * @param player object to be modified.
 * @return None.
 */
void character::printStats(character* c)
{
	Print2("Health: ", c->health);
	Print2("Attack: ", c->attack);
	Print2("Defense: ", c->defense);
	Print2("Experience: ", c->exp);
}


/**
 * Resets players HP and MP.
 *
 * @param player object to be modified.
 * @return None.
 */
void character::Rest()
{
	Print("You are fully rested\n");
}

/**
 * Opens generic shopping menu.
 *
 * @param player object to be modified.
 * @return None.
 */
void character::shop(character * c)
{
	std::cout << "You have " << c->gold << " gold\n\n";
	Print("What do you desire?\n");
	Print("Weapons (1) \t Armor(2) \t Equipment(3) \t Potions(4)\n");
	int f;
	std::cin >> f;
	switch (f) // Prints list of all available items for purchase
	{
	case 1:
		int p;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "(" << i << ")" << weapons[i];
			std::cout << " (" << cost[i] << ")\n";
		}
		//Making the item purchase
		Print("Which weapon would you like?");
		std::cin >> p;
		Print("Which weapon slot would you like to overwrite?");
		int n;
		std::cin >> n;
		weapons_owned[n] = weapons[p];
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			std::cout << "(" << i << ")" << armor[i];
			std::cout << " (" << cost[i] << ")\n";
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++)
		{
			std::cout << "(" << i << ")" << equipment[i];
			std::cout << " (" << cost[i] << ")\n";
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			Print(potions[i]);
			std::cout << " (" << cost[i] << ")\n";
		}
		break;
	default: break;
	}
}

/**
 * Story progression menu
 *
 * @param player object.
 * @return None.
 */
void character::storyProgression(character* c)
{
	Print("What type of adventure do you seek?\n");
	Print("Bounty(1) \t Dungeon Crawl(2)\n");
	int fp;
	std::cin >> fp;
	switch (fp)
	{
	case 1:
		Print("Here are the available bounties in this town.\n");
		com->fight(c);
		break;
	case 2:
		Print("Here is a list of nearby dungeons.\n");
		break;
	default: break;
	}
}

/**
 * Load new or existing character
 *
 * @param player object.
 * @return None.
 */
void character::loadCharacter(character* &c)
{
	c->pickclass(c);
	c->namechar();
	c->readstat();
	Print("Press M at any time to open the menu.\n");
}