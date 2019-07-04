#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Character.h"
#include "Rain.h"
#include "Gout.h"
#include "Timer.h"
#include <thread>	 
#include <vector>
#include "Font.h"
#include "BestRecord.h"
class Game
{
public:
	
	Game(int resolucion_x, int resolucion_y, std::string titulo);
	~Game();
	void dibujar();
	void gameLoop();
	void procesar_eventos();
	void evento_ventana();
private:
	sf::RenderWindow* ventana1;
	int fps;
	sf::Event* _evento01;
	Input* _teclado;
	Character* _sakura;
	Timer* _timeGameStart;
	Rain* _rain;
	
	bool switch_1;
	bool switch_2;

	bool switch_lose;
	bool switch_start_game;
	std::vector<std::thread> _threads;
	Font* _text_start;
	Font* _text_record;
	Font* _text_best_record;
	BestRecord record;

};

