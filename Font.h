#pragma once
#include "FontMemoryShared.h"
class Font 
{
private:
	FontMemoryShared* memory;
	int _position_x;
	int _position_y;
	std::string _words;
public:	
	
	Font(std::string words,int position_x,int position_y,int scale,std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds);
	
	std::vector<sf::Sprite*>* _SpriteWords;
	~Font();
};

