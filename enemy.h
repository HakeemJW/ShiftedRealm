#pragma once
class enemy
{
public:
	int e_health, e_attack, e_defense, e_exp;
	virtual void e_setstat() = 0;
	virtual void e_description() = 0;
	void printstats();
};

