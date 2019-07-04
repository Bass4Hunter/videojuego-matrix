#pragma once
#include "RandomNumber.h"
#include <algorithm>
#include <random>   
#include<chrono>
class RandomVector :
	public RandomNumber
{
public:

	RandomVector();
	~RandomVector();
	void setRandom() ;
	void setRange(int newNumber,int position);
 	int getRandom() ;

};

