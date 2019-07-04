#include "FontMemoryShared.h"
FontMemoryShared* FontMemoryShared::instance = 0;

FontMemoryShared::FontMemoryShared(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds) :Animation(ruta, boundWidth, boundHeight, widthTexture, heightTexture, delayMiliseconds) {
	int r = _heightTexture / _boundHeight;
	int c = _widthTexture / _boundWidth;
	
	int index = 32;
	for (int i = 0;i<r;i++) {
		for (int j = 0;j<c;j++) {
			rects.insert(std::pair<int,sf::IntRect*>(index,_animation[i][j]));
			index++;
		}
	}

}


FontMemoryShared* FontMemoryShared::createInstaceFontMemoryShared(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds)
{
	if (instance == 0)
	{
		instance = new FontMemoryShared(ruta, boundWidth,boundHeight,widthTexture,heightTexture,delayMiliseconds);
	}

	return instance;
}

sf::IntRect*  FontMemoryShared::getIntRect(int index) {
	return rects[index];
}
