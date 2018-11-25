#pragma once
#include <string>
class character
{
public:
	character();
	~character();
	int health, attack, defense, exp;
	int clas = 0;
	int randnum = 0;
	void pickclass();
	void namechar();
	void readstat();
	void action();
	void print_location();
	virtual void setstat() = 0;
	virtual void description() = 0;
};

