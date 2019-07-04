#include "Timer.h"
Timer::Timer() {
	_seconds = 0;
	_reloj = nullptr;
	_tiempo = nullptr;
}
Timer::~Timer() {
	_reloj = new sf::Clock;
	_tiempo = new sf::Time;
}

void Timer::init() {
	_reloj = new sf::Clock();
	_tiempo = new sf::Time();
}
void Timer::reset() {
	_reloj->restart();
}
float Timer::getMiliseconds() {
	*_tiempo = _reloj->getElapsedTime();
	_seconds = _tiempo->asMilliseconds();
	return _seconds;
}

int Timer::getSeconds() {
	*_tiempo = _reloj->getElapsedTime();
	_seconds = _tiempo->asSeconds();
	return _seconds;
}