#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

class MultiSprite{

public:
	MultiSprite(void);
	~MultiSprite(void);
	sf::Sprite* addSprite(sf::Sprite*);
	void move(float x, float y);
	sf::Sprite* getSprite(int);

private:
	std::vector<sf::Sprite*> sprites;
	float xPos, Ypos;
};

