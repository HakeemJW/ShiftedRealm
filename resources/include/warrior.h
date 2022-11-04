#pragma once
#include "character.h"
class warrior :
	public character
{
public:
	warrior();
	~warrior();
	void setstat() override;
	void description() override;
};

