#include "Font.h"
Font::Font(std::string words, int position_x, int position_y,int scale,std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds) {
	memory = FontMemoryShared::createInstaceFontMemoryShared(ruta, boundWidth, boundHeight, widthTexture, heightTexture, delayMiliseconds);
	
	_position_x = position_x;
	_position_y = position_y;
	_words = words;
	_SpriteWords = new std::vector<sf::Sprite*>;


	int index;
	sf::Sprite* ptr_temp;

	int temp_postion_x = 0;

	for (std::string::iterator it = _words.begin(); it != _words.end(); ++it) {
		
		index = *it;
		
		ptr_temp = new sf::Sprite(*(memory->getTexture()));
		ptr_temp->setTextureRect(*(memory->getIntRect(index)));
		ptr_temp->setPosition(_position_x, _position_y);

		ptr_temp->setScale(ptr_temp->getScale().x * scale, ptr_temp->getScale().y * scale);
		

		ptr_temp->setPosition(_position_x+temp_postion_x, _position_y);


		_SpriteWords->push_back(ptr_temp);
		
		temp_postion_x += boundWidth*scale;
	}

}

Font::~Font() {

	delete _SpriteWords;
}