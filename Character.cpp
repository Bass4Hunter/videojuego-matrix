#include "Character.h"
Character::Character(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture,float delayMiliseconds, float inputSpeed, Input* teclado):Animation(ruta, boundWidth, boundHeight, widthTexture, heightTexture,delayMiliseconds) {
	
	_sprite = new sf::Sprite(*_textura);
	_sprite->setTextureRect(_animation[0][0][0]);
	_sprite->setScale(_sprite->getScale().x * 3, _sprite->getScale().y * 3);
	_sprite->setPosition(905, 485);


	_teclado = teclado;
	_inputSpeed = inputSpeed;
	_timerSpeed = new Timer;
	_timerSpeed->init();
	
}
Character::~Character() {
	delete _timerSpeed;
	delete _sprite;
}

void Character::chanceFrame() {
	_teclado->detectEventKeyboard();

	float x = _sprite->getPosition().x;
	float y = _sprite->getPosition().y;

	if(_timerSpeed->getMiliseconds() > _inputSpeed ){
		if ((_teclado->getMovimiento())[0] && (_teclado->getMovimiento())[2] && x > 10 && y>10) {
			_sprite->setPosition(x - 17.0180704907,y -17.0180704907);
		}
		else if ((_teclado->getMovimiento())[0] && (_teclado->getMovimiento())[3] && x > 10 && y< 970) {
			_sprite->setPosition(x - 17.0180704907,y + 17.0180704907);

		}
		else if ((_teclado->getMovimiento())[1] && (_teclado->getMovimiento())[2] && x<1810 && y >10) {
			_sprite->setPosition(_sprite->getPosition().x + 17.0180704907, _sprite->getPosition().y - 17.0180704907);

		}
		else if ((_teclado->getMovimiento())[1] && (_teclado->getMovimiento())[3] && x<1810 && y<970) {
			_sprite->setPosition(_sprite->getPosition().x + 17.0180704907, _sprite->getPosition().y + 17.0180704907);
		}
		//lefth
		else if ((_teclado->getMovimiento())[0] && x > 10) {
			_sprite->setPosition(_sprite->getPosition().x - 20, _sprite->getPosition().y);
		}
		//right
		else if ((_teclado->getMovimiento())[1] && x < 1810) {
			_sprite->setPosition(_sprite->getPosition().x + 20, _sprite->getPosition().y);
		}
		//up
		else if ((_teclado->getMovimiento())[2] && y > 10) {
			_sprite->setPosition(_sprite->getPosition().x, _sprite->getPosition().y - 20);
		}
		//down
		else if ((_teclado->getMovimiento())[3] && y < 970){
			_sprite->setPosition(_sprite->getPosition().x, _sprite->getPosition().y + 20);
		}
		_timerSpeed->reset();
	}

	if (_timerDelayAnimation->getMiliseconds() > _delayMilisecondsAnimation) {
		if ((_teclado->getMovimiento())[0] && (_teclado->getMovimiento())[2]) {
			if (_sprite->getTextureRect() == _animation[4][3][0]) {
				_sprite->setTextureRect(_animation[4][2][0]);
			}
			else {
				_sprite->setTextureRect(_animation[4][3][0]);
			}
		}
		else if ((_teclado->getMovimiento())[0] && (_teclado->getMovimiento())[3]) {
			if (_sprite->getTextureRect() == _animation[1][0][0]) {
				_sprite->setTextureRect(_animation[0][5][0]);
			}
			else {
				_sprite->setTextureRect(_animation[1][0][0]);
			}
		}
		else if ((_teclado->getMovimiento())[1] && (_teclado->getMovimiento())[2]) {
			if (_sprite->getTextureRect() == _animation[5][0][0]) {
				_sprite->setTextureRect(_animation[4][4][0]);
			}
			else {
				_sprite->setTextureRect(_animation[5][0][0]);
			}
		}
		else if ((_teclado->getMovimiento())[1] && (_teclado->getMovimiento())[3]) {
			if (_sprite->getTextureRect() == _animation[1][2][0]) {
				_sprite->setTextureRect(_animation[1][1][0]);
			}
			else {
				_sprite->setTextureRect(_animation[1][2][0]);
			}
		}
		else if ((_teclado->getMovimiento())[0]) {
			if (_sprite->getTextureRect() == _animation[2][1][0]) {
				_sprite->setTextureRect(_animation[2][0][0]);
			}
			else {
				_sprite->setTextureRect(_animation[2][1][0]);
			}
		}
		else if ((_teclado->getMovimiento())[1]) {
			if (_sprite->getTextureRect() == _animation[3][1][0]) {
				_sprite->setTextureRect(_animation[3][0][0]);
			}
			else {
				_sprite->setTextureRect(_animation[3][1][0]);
			}
		}
		else if ((_teclado->getMovimiento())[2]) {
			if (_sprite->getTextureRect() == _animation[4][1][0]) {
				_sprite->setTextureRect(_animation[4][0][0]);
			}
			else {
				_sprite->setTextureRect(_animation[4][1][0]);
			}
		}
		else if ((_teclado->getMovimiento())[3]) {
			if (_sprite->getTextureRect() == _animation[0][1][0]) {
				_sprite->setTextureRect(_animation[0][2][0]);
			}
			else {
				_sprite->setTextureRect(_animation[0][1][0]);
			}
		}
		else {
			if (_sprite->getTextureRect() == _animation[0][4][0]) {
				_sprite->setTextureRect(_animation[0][3][0]);
			}
			else {
				_sprite->setTextureRect(_animation[0][4][0]);
			}
		}
		_timerDelayAnimation->reset();
	}
}

sf::Sprite Character::getSprite() {
	return *_sprite;
}