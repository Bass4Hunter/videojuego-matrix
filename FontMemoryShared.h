#pragma once
#include "Animation.h"
#include <map>
class FontMemoryShared : public Animation
{
private:
	static FontMemoryShared* instance;

	std::map<int, sf::IntRect*> rects;

	FontMemoryShared(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds);
public:
	static FontMemoryShared* createInstaceFontMemoryShared(std::string ruta, int boundWidth, int boundHeight, int widthTexture, int heightTexture, float delayMiliseconds);
	sf::IntRect* getIntRect(int index);
	sf::Texture* getTexture() {
		return _textura;
	}
};

