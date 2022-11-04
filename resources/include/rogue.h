#pragma once
#include "character.h"
class rogue :
	public character
{
public:
	rogue();
	~rogue();
	void setstat() override;
	void description() override;
};

