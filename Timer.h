#pragma once
#include <SFML/Graphics.hpp>
class Timer
{
public:
	Timer();
	~Timer();

	void init();
	void reset();
	float getMiliseconds();
	int getSeconds();
private:
	
	float _seconds;
	sf::Clock* _reloj;
	sf::Time* _tiempo;
};

