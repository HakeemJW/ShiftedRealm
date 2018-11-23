#pragma once
#include <string>
class character
{
public:
	character();
	~character();
	int health, attack, defense;
	int gold = 100;
	int clas = 0;
	int exp;
	int randnum = 0;
	void pickclass();
	void namechar();
	void readstat();
	void action();
	virtual void setstat() = 0;
	virtual void description() = 0;
};

