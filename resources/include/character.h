#pragma once
#include <string>

class character
{
public:
	character();
	~character();
	void changeLocation(character* c);
	void printStats(character* c);
	void Rest();
	void shop();
	void storyProgression(character* c);
	void loadCharacter(character* &c);
	int health = 0, attack = 0, defense = 0, exp = 0;
	std::string weapon_equipped, armor_equipped;
	std::string weapons_owned[50], armor_owned[50], potions_owned[50], equipment_owned[50];
	std::string currentLocation;
	void pickclass(character* & c);	//Player Class Selection Menu
	void namechar();	
	void readstat();
	void equip();
	void print_equipped();
	void print_equipment_owned();
	void action(character* c);
	void print_location(character* c);
	virtual void setstat() = 0;
	virtual void description() = 0;
};

