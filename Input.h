#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Input
{
public:

	Input(sf::RenderWindow* window, sf::Event* evento);
	~Input();
	void reiniciar();
	void detectEventKeyboard();

	bool* getVolumen();
	bool* getMovimiento();
	bool* getColors();

private:
	sf::RenderWindow* _window;
	sf::Event* _keyboard;
	bool* _volumen;
	bool* _movimiento;
	bool* _colors;
};

