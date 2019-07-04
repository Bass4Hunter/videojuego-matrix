#pragma once
#include <typeinfo>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "Animation.h"
#include "Input.h"
#include "LinkedList.h"
#include "Gout.h"
#include "RandomFactory.h"
#include <SFML/Graphics.hpp>
#include <string> 
class Rain :
	public Animation
{
private:
	static Rain* instance;
	Input* _teclado;
	Timer* _timerSpeed;
	Timer* _eventGame;
	float* _inputSpeed;
	LinkedList<Gout*>* _sprites;
	RandomFactory* _randomSizeGout;
	int tempRevisarTiempoCambio;
	Rain(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds, float inputSpeed, Input* teclado, Timer* eventGame);

public:
	void addToRain(int add, int lvl);
	static Rain* CreateRain(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds, float inputSpeed, Input* teclado, Timer* eventGames	);
	~Rain();
	void chanceFrame();
	LinkedList<Gout*>* getSprites();
};

