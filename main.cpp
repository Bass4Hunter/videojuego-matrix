#include "Game.h"
int main() {
	Game* partida01;
	std::string nombre = "MATRIX";
	partida01 = new Game(1920, 1080, nombre);
	delete partida01;

}