#include "RandomVector.h"
#include <iostream> 
RandomVector::RandomVector() {
	_random = new int;
	_start = NULL;
	_range = NULL;
	_vectorRandom = new std::vector<int>;
}

RandomVector::~RandomVector() {
	delete _vectorRandom;
	delete _random;
}

void RandomVector::setRandom() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	std::shuffle(_vectorRandom->begin(), _vectorRandom->end(), e);
	
	*_random = (*_vectorRandom).at(0);
}

void RandomVector::setRange(int newNumber,int position) {
	_vectorRandom->push_back(newNumber);
}

int RandomVector::getRandom() {
	return *_random;
}
