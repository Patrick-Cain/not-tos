#pragma once
#include"SFML\Graphics.hpp"
#include <iostream>
class Runestone
{
private:
	


public:
	int col, row, xcoordinate, ycoordinate, kind;
	int alpha = 255;
	int match = 0;

	Runestone();
	virtual ~Runestone();
	void setKind(int);
	int getKind();
};

