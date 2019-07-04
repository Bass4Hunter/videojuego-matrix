#include "Random.h"
Random::Random(int start,int range) {
	_random = new int;
	_range = new int;
	_start = new int;
	_vectorRandom = NULL;

	*_range = range;
	*_start = start;
	
	unsigned seed =
		std::chrono::system_clock::now().time_since_epoch().count();
	srand(seed);

	*_random = *_start+rand() % (*_range+1-*_start);


}

Random::~Random() {
	delete _random;
	delete _range;
}

void Random::setRandom() {
	unsigned seed =
		std::chrono::system_clock::now().time_since_epoch().count();
	srand(seed);
	*_random = *_start + rand() % (*_range + 1 - *_start);
}

void Random::setRange(int start,int range) {
	*_range = range;
	*_start = start;
}

int Random::getRandom() {
	return *_random;
}
