#include "Game.h"
Game::Game(int resolucion_x, int resolucion_y, std::string titulo) {
	
	std::string ruta_font = "../texture/font.png";
	
	std::string letter_1 = "BEST RECORD: " + std::to_string(record.getRecord()) ;
	_text_best_record = new Font(letter_1, 500, 200, 10, ruta_font, 8, 8, 256, 32, 1);

	std::string letters = "START";
	_text_start = new Font(letters, 750, 400, 10, ruta_font, 8, 8, 256, 32, 1);

	switch_lose = false;

	switch_1 = true;
	switch_2 = true;

	switch_start_game = false;

	_timeGameStart = new Timer;
	_timeGameStart->init();

	fps = 60;
	_evento01 = new sf::Event;

	ventana1 = new sf::RenderWindow(sf::VideoMode(resolucion_x, resolucion_y), titulo, sf::Style::Fullscreen);
	ventana1->setFramerateLimit(fps);

	_teclado = new Input(ventana1, _evento01);

	std::string ruta_character_sakura = "../texture/personaje.png";
	std::string ruta_rain = "../texture/Rain.png ";

	_sakura = new Character(ruta_character_sakura, 32, 32, 192, 192, 150, 1, _teclado);
	_rain = Rain::CreateRain(ruta_rain, 63.90, 64.6, 2045, 1551, 150, 25, _teclado, _timeGameStart);

	gameLoop();
}
Game::~Game() {
	delete _timeGameStart;
	delete _evento01;
	delete ventana1;
	delete _teclado;
	delete _sakura;
	delete _text_start;
	delete _text_record;
}
void Game::dibujar() {

	ventana1->clear();
	if (switch_lose) {
		for (auto i = _text_record->_SpriteWords->begin(); i != _text_record->_SpriteWords->end(); i++) {
			ventana1->draw(*(*i));
		}
		for (auto i = _text_best_record->_SpriteWords->begin(); i != _text_best_record->_SpriteWords->end(); i++) {
			ventana1->draw(*(*i));
		}
	}
	else if (!switch_start_game) {
		for (auto i = _text_start->_SpriteWords->begin(); i != _text_start->_SpriteWords->end(); i++) {
			ventana1->draw(*(*i));
		}
	}
	else {
		ventana1->draw(_sakura->getSprite());

		if (_timeGameStart->getSeconds() > 10 && switch_1) {
			for (int j = 0; j < _rain->getSprites()->getTamano(); j++) {
				(*(_rain->getSprites()->getElement(j)->_data))->setLvl(2);
			}
			_rain->addToRain(4, 2);
			switch_1 = false;
		}

		if (_timeGameStart->getSeconds() > 20 && switch_2) {
			for (int j = 0; j < _rain->getSprites()->getTamano(); j++) {
				(*(_rain->getSprites()->getElement(j)->_data))->setLvl(3);
			}
			switch_2 = false;
		}

		for (int j = 0; j < _rain->getSprites()->getTamano(); j++) {
			_threads.push_back((*(_rain->getSprites()->getElement(j)->_data))->doChangeFrameInOtherThread());
			for (unsigned int i = 0; i < _threads.size(); ++i)
			{
				if (_threads[i].joinable())
					_threads.at(i).join();
			}
			for (Iterator<sf::Sprite> i = (*(_rain->getSprites()->getElement(j)->_data))->_sprites->iterador(); i.hasNext(); i++) {
				ventana1->draw(*((*i)->_data));
			}
		}
		for (int j = 0; j < _rain->getSprites()->getTamano(); j++) {
			(*(_rain->getSprites()->getElement(j)->_data))->chanceFrame();
			for (Iterator<sf::Sprite> i = (*(_rain->getSprites()->getElement(j)->_data))->_sprites->iterador(); i.hasNext(); i++) {
				if ((*i)->_data->getGlobalBounds().intersects(_sakura->getSprite().getGlobalBounds())) {
					int yourTime = _timeGameStart->getSeconds();
					switch_lose = true;
					std::string ruta_font = "../texture/font.png";
					std::string letters = "RECORD: "+std::to_string(yourTime);
					_text_record = new Font(letters, 500, 400, 10, ruta_font, 8, 8, 256, 32, 1);
					record.setRecord(yourTime);
				}
			}
		}
	}
		ventana1->display();

}
void Game::gameLoop() {
	while (ventana1->isOpen()) {
		procesar_eventos();
		dibujar();
		_teclado->reiniciar();
	}
}
void Game::procesar_eventos() {
		evento_ventana();
		if (switch_lose) {
		}
		else if(switch_start_game) {
			_sakura->chanceFrame();
		}
}
void Game::evento_ventana() {
	while (ventana1->pollEvent(*_evento01)) {
		if (_evento01->type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				exit(1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				switch_start_game = true;
			}
		}
	}
}