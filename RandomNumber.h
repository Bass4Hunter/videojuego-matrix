#pragma once
#include<cstdlib>
#include<ctime>
#include <chrono>
#include <vector>
class RandomNumber
{
protected:
	int* _start;
	int* _random;
	int* _range;
	std::vector<int>* _vectorRandom;

public:


	virtual void setRandom() = 0;
	virtual void setRange(int start,int range) = 0;
	virtual int getRandom() = 0;

};

