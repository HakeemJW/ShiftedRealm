#include "character.h"
#include <iostream>
#include <string>

using namespace std;

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

character::character()
{
}


character::~character()
{
}
