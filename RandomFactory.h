#pragma once
#include <string>
#include "RandomNumber.h"
#include "RandomVector.h"
#include "Random.h"
class RandomFactory
{
public:
	RandomFactory() {
		_random = new RandomVector();
	}
	
	RandomFactory(int a,int b) {
		_random = new Random(a, b);
	}
	~RandomFactory() {
		if (_random)
		{
			delete _random;
		}
	}

	RandomNumber* getRandom() {
		return _random;
	}
private:
	RandomNumber* _random;
};

