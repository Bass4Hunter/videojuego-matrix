#pragma once

#include "Animation.h"
#include "LinkedList.h"
#include "Input.h"
#include "Timer.h"
#include "RandomNumber.h"
#include "RandomFactory.h"
#include <math.h>
#include <thread>
class Gout :
	public Animation
{
private:

	Input* _teclado;
	Timer* _timerSpeed;
	float* _inputSpeed;
	
	bool _colorPressed;
	bool _lvl[4];
	RandomFactory* _angle;
	RandomFactory* _positionX;
	RandomFactory* _positionY;

	void helperChangePositionSprites();

public:
	void operator () (int lvl);
	LinkedList<sf::Sprite>* _sprites;
	Gout(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds,int size, int lvl, Input* teclado, Timer* timerSpeed, float* _inputSpeed);
	~Gout();
	void chanceFrame();
	void setSize(int size);
	void setLvl(int lvl);
	void setQuadrant(int cuadrante);
	std::thread doChangeFrameInOtherThread();
};

