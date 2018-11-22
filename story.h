#pragma once
#include "character.h"
#include <string>

using namespace std;

class story :
	public character
{
public:
	story();
	~story();
	void intro();
	void keycommands();
};

