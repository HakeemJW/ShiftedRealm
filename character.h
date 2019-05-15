#pragma once
#include <string>
using namespace std;
class character
{
public:
	character();
	~character();
	int health, attack, defense, exp;
	string weapon_equipped, armor_equipped;
	string weapons_owned[50], armor_owned[50], potions_owned[50], equipment_owned[50];
	int clas = 0;
	int randnum = 0;
	void pickclass();	//Player Class Selection Menu
	void namechar();	
	void readstat();
	void print_equipped();
	void print_equipment_owned();
	void action(character* c);
	void print_location();
	virtual void setstat() = 0;
	virtual void description() = 0;
};

