#include "Gout.h"

Gout::Gout(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds, int sizeGout, int lvl, Input* teclado, Timer* timerSpeed, float* inputSpeed) :Animation(ruta, boundWidth, boundHeight, widthTexture, heightTexture, delayMiliseconds) {


	for (int i = 0; i < 4; i++) {
		_lvl[i] = false;
	}

	_colorPressed = false;

	setLvl(lvl);





	_teclado = teclado;
	_timerSpeed = timerSpeed;
	_inputSpeed = inputSpeed;




	_sprites = new LinkedList <sf::Sprite>(sizeGout);

	helperChangePositionSprites();
}
Gout::~Gout() {
	delete _sprites;
	delete _angle;
	delete _positionX;
	delete _positionY;
}

void Gout::chanceFrame() {

	const double PI = 3.141592653589793238463;



	float temp_x = 10;
	float temp_y = 10;

	for (Iterator<sf::Sprite> i = _sprites->iterador(); i.hasNext(); i++) {
		if (_angle->getRandom()->getRandom() >= 0 && _angle->getRandom()->getRandom() < 90) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() >= 90 && _angle->getRandom()->getRandom() <= 180) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
		else if (_angle->getRandom()->getRandom() <= 0 && _angle->getRandom()->getRandom() <= -90) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() >= -90 && _angle->getRandom()->getRandom() <= -180) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
	}
	temp_x = -_boundWidth;
	temp_y = -_boundHeight;
	for (int i = 0; i < 1; i++) {
		_sprites->getElement(i)->_data->setPosition(_positionX->getRandom()->getRandom(), _positionY->getRandom()->getRandom());
		if (_angle->getRandom()->getRandom() >= 0 && _angle->getRandom()->getRandom() < 90) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() >= 90 && _angle->getRandom()->getRandom() <= 180) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
		else if (_angle->getRandom()->getRandom() < 0 && _angle->getRandom()->getRandom() <= -90) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() > -90 && _angle->getRandom()->getRandom() < -180) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
	}	
	
	int tempLvl = 1;
	if (_lvl[3]) {
		tempLvl = 4;
	}
	else if (_lvl[2]) {
		tempLvl = 3;

	}
	else  if (_lvl[1]) {

		tempLvl = 2;


	}
	else if (_lvl[0]) {
		tempLvl = 1;

	}

	if (_angle->getRandom()->getRandom() == 0 && _sprites->getElement(1)->_data->getPosition().y > 1080 ||
		_angle->getRandom()->getRandom() == -180 && _sprites->getElement(1)->_data->getPosition().y < 0||
		_angle->getRandom()->getRandom() == 90 && _sprites->getElement(1)->_data->getPosition().x < 0|| 
		_angle->getRandom()->getRandom() == -90 && _sprites->getElement(1)->_data->getPosition().x > 1600)
	{
			
		setLvl(tempLvl);
		helperChangePositionSprites();
	}

		
}
void Gout::helperChangePositionSprites() {

	const double PI = 3.141592653589793238463;



	float temp_x = _boundWidth;
	float temp_y = _boundHeight;

	for (Iterator<sf::Sprite> i = _sprites->iterador(); i.hasNext(); i++) {
		(*i)->_data->setTexture(*_textura);
		(*i)->_data->setTextureRect(_animation[0][0][0]);
		(*i)->_data->setRotation(_angle->getRandom()->getRandom());
		(*i)->_data->setPosition(_positionX->getRandom()->getRandom(), _positionY->getRandom()->getRandom());

		if (_angle->getRandom()->getRandom() >= 0 && _angle->getRandom()->getRandom() < 90) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() >= 90 && _angle->getRandom()->getRandom() <= 180) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
		else if (_angle->getRandom()->getRandom() <= 0 && _angle->getRandom()->getRandom() <= -90) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() >= -90 && _angle->getRandom()->getRandom() <= -180) {
			(*i)->_data->setPosition((*i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), (*i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
		temp_x += _boundWidth;
		temp_y += _boundHeight;
	}
	temp_x = -_boundWidth;
	temp_y = -_boundHeight;
	for (int i = 0; i < 1; i++) {
		_sprites->getElement(i)->_data->setPosition(_positionX->getRandom()->getRandom(), _positionY->getRandom()->getRandom());
		if (_angle->getRandom()->getRandom() >= 0 && _angle->getRandom()->getRandom() < 90) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() >= 90 && _angle->getRandom()->getRandom() <= 180) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
		else if (_angle->getRandom()->getRandom() < 0 && _angle->getRandom()->getRandom() <= -90) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x - temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y + temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}

		else if (_angle->getRandom()->getRandom() > -90 && _angle->getRandom()->getRandom() < -180) {
			_sprites->getElement(i)->_data->setPosition(_sprites->getElement(i)->_data->getPosition().x + temp_x * sin(_angle->getRandom()->getRandom() * PI / 180.0), _sprites->getElement(i)->_data->getPosition().y - temp_y * cos(_angle->getRandom()->getRandom() * PI / 180.0));
		}
	}


}
void Gout::setLvl(int  lvl){
	delete _angle;
	delete _positionX;
	delete _positionY;
	for (int i = 0; i < lvl; i++) {
		_lvl[i] = true;
	}
	if (_lvl[3]) {
		_angle = new RandomFactory(0, 360);
	}
	else if (_lvl[2]) {
		_angle = new RandomFactory();
		_angle->getRandom()->setRange(-90, 0);
		_angle->getRandom()->setRange(90, 0);
		_angle->getRandom()->setRange(-180, 0);
		_angle->getRandom()->setRange(0, 0);
		_angle->getRandom()->setRandom();

		if (_angle->getRandom()->getRandom() == 90) {
			_positionX = new RandomFactory(2400, 2400);
			_positionY = new RandomFactory(0, 1080);

		}
		else if(_angle->getRandom()->getRandom() == -90) {
			_positionX = new RandomFactory(-500, -500);
			_positionY = new RandomFactory(0, 1080);
		}
		else if (_angle->getRandom()->getRandom() == 0) {
		_positionX = new RandomFactory(0, 1810);
		_positionY = new RandomFactory(-500, -500);

		}
		else if (_angle->getRandom()->getRandom() == -180) {
			_positionX = new RandomFactory(0, 1920);
			_positionY = new RandomFactory(1600, 1600);

		}

	}
	else  if (_lvl[1]) {
		_angle = new RandomFactory();
		_angle->getRandom()->setRange(-90, 0);
		_angle->getRandom()->setRange(90, 0);

		_angle->getRandom()->setRandom();
		if (_angle->getRandom()->getRandom() == 90) {
			_positionX = new RandomFactory(2300, 2300);
			_positionY = new RandomFactory(0, 1080);

		}
		else {
			_positionX = new RandomFactory(-500, -500);
			_positionY = new RandomFactory(0, 1080);
		}


	}
	else if (_lvl[0]) {
		_angle = new RandomFactory(0,0);
		_positionX = new RandomFactory(0,1810);
		_positionY = new RandomFactory(-500,-500);
	}

}

void Gout::operator() (int lvl){
	delete _angle;
	delete _positionX;
	delete _positionY;
	for (int i = 0; i < lvl; i++) {
		_lvl[i] = true;
	}
	if (_lvl[3]) {
		_angle = new RandomFactory(0, 360);
	}
	else if (_lvl[2]) {
		_angle = new RandomFactory();
		_angle->getRandom()->setRange(-90, 0);
		_angle->getRandom()->setRange(90, 0);
		_angle->getRandom()->setRange(-180, 0);
		_angle->getRandom()->setRange(0, 0);
		_angle->getRandom()->setRandom();

		if (_angle->getRandom()->getRandom() == 90) {
			_positionX = new RandomFactory(2400, 2400);
			_positionY = new RandomFactory(0, 1080);

		}
		else if (_angle->getRandom()->getRandom() == -90) {
			_positionX = new RandomFactory(-500, -500);
			_positionY = new RandomFactory(0, 1080);
		}
		else if (_angle->getRandom()->getRandom() == 0) {
			_positionX = new RandomFactory(0, 1810);
			_positionY = new RandomFactory(-500, -500);

		}
		else if (_angle->getRandom()->getRandom() == -180) {
			_positionX = new RandomFactory(0, 1920);
			_positionY = new RandomFactory(1600, 1600);

		}

	}
	else  if (_lvl[1]) {
		_angle = new RandomFactory();
		_angle->getRandom()->setRange(-90, 0);
		_angle->getRandom()->setRange(90, 0);

		_angle->getRandom()->setRandom();
		if (_angle->getRandom()->getRandom() == 90) {
			_positionX = new RandomFactory(2300, 2300);
			_positionY = new RandomFactory(0, 1080);

		}
		else {
			_positionX = new RandomFactory(-500, -500);
			_positionY = new RandomFactory(0, 1080);
		}


	}
	else if (_lvl[0]) {
		_angle = new RandomFactory(0, 0);
		_positionX = new RandomFactory(0, 1810);
		_positionY = new RandomFactory(-500, -500);
	}
}

std::thread Gout::doChangeFrameInOtherThread() {
	return std::thread([=] { chanceFrame(); });
}
