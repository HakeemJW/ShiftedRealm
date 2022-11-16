#pragma once
#include <string>

class character
{
public:
	
	int health = 0, attack = 0, defense = 0, exp = 0, gold = 100;
	std::string weapon_equipped, armor_equipped;
	std::string weapons_owned[50], armor_owned[50], potions_owned[50], equipment_owned[50];
	std::string currentLocation;
	
	character();
	~character();
	
	/**
	* Changes player's location.
	*
	* @param player object to be modified.
	* @return None.
	*/
	void changeLocation(character* c);
	
	/**
	* Prints player's stats.
	*
	* @param player object to be modified.
	* @return None.
	*/
	void printStats(character* c);
	
	/**
	* Resets players HP and MP.
	*
	* @param player object to be modified.
	* @return None.
	*/
	void Rest();
	
	/**
	* Opens generic shopping menu.
	*
	* @param player object to be modified.
	* @return None.
	*/
	void shop(character* c);
	

	/**
	 * Story progression menu
	 *
	 * @param player object.
	 * @return None.
	 */
	void storyProgression(character* c);
	
	/**
	 * Load new or existing character
	 *
	 * @param player object.
	 * @return None.
	 */
	void loadCharacter(character* &c);
	
	/**
	* Player class selection.
	*
	* @param Player object to be overwritten by subclass.
	* @return None.
	*/
	void pickclass(character* & c);	//Player Class Selection Menu
	
	/**
	* Player names character.
	*
	* @param None.
	* @return None.
	*/
	void namechar();	
	
	/**
	* Reads out character starting stats
	*
	* @param None.
	* @return None.
	*/
	void readstat();
	
	/**
	* Gives player the option to equip items.
	*
	* @param player object to be modified.
	* @return None.
	*/
	void equip();
	
	/**
	* Prints Character Equipped Items
	*
	* @param None.
	* @return None.
	*/
	void print_equipped();
	
	/**
	* Prints Characters Owned Items
	*
	* @param None.
	* @return None.
	*/
	void print_equipment_owned();
	
	/**
	* Opens menu with different action options.
	*
	* @param player object to be modified.
	* @return None.
	*/
	void action(character* c);
	
	/**
	* Print player's location.
	*
	* @param player object.
	* @return None.
	*/
	void print_location(character* c);
	
	virtual void setstat() = 0;
	virtual void description() = 0;
};

