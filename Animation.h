#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Timer.h"
class Animation
{
protected :
	
	sf::Texture* _textura;
	sf::IntRect*** _animation;
	std::string _ruta;
	int _boundWidth, _boundHeight, _widthTexture, _heightTexture;
	Timer* _timerDelayAnimation;
	float _delayMilisecondsAnimation;

public:
	Animation(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture,float delayMiliseconds);
	~Animation();
};

