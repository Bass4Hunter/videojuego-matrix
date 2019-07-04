#pragma once
#include "RandomNumber.h"
class Random :
	public RandomNumber
{
public:
	Random(int start,int range);
	~Random();
	void setRandom();
	void setRange(int start, int range);
	int getRandom();
};

