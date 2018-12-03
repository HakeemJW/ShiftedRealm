#pragma once
#include "enemy.h"
class goblin :
	public enemy
{
public:
	goblin();
	~goblin();
	void e_setstat() override;
	void e_description() override;
};

