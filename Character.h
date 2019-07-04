#pragma once
#include "Animation.h"
#include "Input.h"
class Character :
	public Animation
{
private:
	Input* _teclado;
	Timer* _timerSpeed;
	sf::Sprite* _sprite;
	float _inputSpeed;
public:
	
	Character(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture,float delayMiliseconds,float inputSpeed,Input* teclado);
	~Character();
	void chanceFrame();
	sf::Sprite getSprite();
};

