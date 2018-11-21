#pragma once
class character
{
public:
	character();
	~character();
	int health, attack, defense;
	int gold = 100;
	int clas = 0;
	int exp;
	void pickclass();
	void namechar();
	void readstat();
	virtual void setstat() = 0;
	virtual void description() = 0;
};

