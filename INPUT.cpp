#include "Input.h"
Input::Input(sf::RenderWindow* window, sf::Event* evento)
{
	_window = window;
	_keyboard = evento;
	_volumen = new bool[2];
	_movimiento = new bool[4];
	_colors = new bool[4];
}
Input :: ~Input()
{
	delete[] _volumen;
	delete[] _movimiento;
	delete[] _colors;
}
void Input::reiniciar() {
	for (int i = 0; i < 4; i++) {
		_movimiento[i] = false;
		_colors[i] = false;
	}
	for (int i = 0; i < 2; i++) {
		_volumen[i] = false;
	}
}

void Input::detectEventKeyboard() {
  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_movimiento[0] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_movimiento[1] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_movimiento[2] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		_movimiento[3] = true;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		_colors[0] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		_colors[1] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		_colors[2] = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		_colors[3] = true;
	}
}

bool* Input::getVolumen() {
	return _volumen;
}
bool* Input::getMovimiento() {
	return _movimiento;
}
bool* Input::getColors() {
	return _colors;
}