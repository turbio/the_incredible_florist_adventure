#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

class MultiSprite{

public:
	MultiSprite(void);
	~MultiSprite(void);

private:
	std::vector<sf::Sprite*> sprites;
	float xPos, Ypos;
};

