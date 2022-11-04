#pragma once
#include "character.h"
class mage :
	public character
{
public:
	mage();
	~mage();
	void setstat() override;
	void description() override;
};

