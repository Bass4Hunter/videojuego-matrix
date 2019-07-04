#include "Animation.h"

Animation::Animation(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture,float delayMiliseconds) {
	
	_timerDelayAnimation = new Timer;
	_timerDelayAnimation->init();


	_delayMilisecondsAnimation = delayMiliseconds;


	_ruta = ruta;
	_boundWidth = boundWidth;
	_boundHeight = boundHeight;
	_widthTexture = widthTexture;
	_heightTexture = heightTexture;

	_textura = new sf::Texture;
	_textura->loadFromFile(ruta);

	int r = _heightTexture / _boundHeight;
	int c = _widthTexture / _boundWidth;

	_animation = new sf::IntRect * *[r];

	for (int i = 0; i < r; i++) {
		_animation[i] = new sf::IntRect * [c];
	}

	for (int i = 0, x = 0; x < r; i += _boundHeight, x++) {
		for (int j = 0, y = 0; y < c; j += _boundWidth, y++) {
			_animation[x][y] = new sf::IntRect(j, i, _boundWidth, _boundHeight);
		}
	}

	

}

Animation::~Animation() {
	int r = _heightTexture / _boundHeight;
	int c = _widthTexture / _boundWidth;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			delete _animation[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		delete[] _animation[i];
	}

	delete[] _animation;
	delete[] _timerDelayAnimation;

}
