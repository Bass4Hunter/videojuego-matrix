#include "Rain.h"


Rain* Rain::instance = 0;


Rain::Rain(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds, float inputSpeed, Input* teclado, Timer* eventGames) :
	Animation(ruta, boundWidth, boundHeight, widthTexture, heightTexture, delayMiliseconds)
{
	tempRevisarTiempoCambio = 0;

	_randomSizeGout = new RandomFactory(5, 8);
	_eventGame = eventGames;

	_teclado = teclado;
	_inputSpeed = new float(inputSpeed);
	_timerSpeed = new Timer;
	_timerSpeed->init();

	_sprites = new LinkedList<Gout*>;
	addToRain(4, 1);

}
Rain* Rain::CreateRain(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds, float inputSpeed, Input* teclado, Timer* eventGames) {
	if (instance == 0) {
		instance = new Rain(ruta, boundWidth, boundHeight, widthTexture, heightTexture, delayMiliseconds, inputSpeed, teclado, eventGames);
	}
	return instance;
}
Rain::~Rain(){
	delete _inputSpeed;
	delete _timerSpeed;
	delete _sprites;
}
void Rain::addToRain(int add,int lvl) {

	for (int i = 0; i < add; i++) {
		_sprites->insertElement(_sprites->getTamano());
		*(_sprites->getElement(_sprites->getTamano()-1)->_data)= new Gout(_ruta,_boundWidth,_boundHeight,_widthTexture,_heightTexture,_delayMilisecondsAnimation,_randomSizeGout->getRandom()->getRandom(),lvl,_teclado,_timerSpeed,_inputSpeed);
		_randomSizeGout->getRandom()->setRandom();
	}

}
void Rain::chanceFrame() {

	for (Iterator<Gout*> i = _sprites->iterador(); i.hasNext(); i++) {
		(*((*i)->_data))->chanceFrame();
	}
	
}
LinkedList<Gout*>* Rain::getSprites() {
	return _sprites;
}

