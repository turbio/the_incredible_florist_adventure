#include "MultiSprite.h"


MultiSprite::MultiSprite(void){

}

MultiSprite::~MultiSprite(void){

}

sf::Sprite* MultiSprite::addSprite(sf::Sprite *sprite){
	sprites.push_back(sprite);
	return sprite;
}

void MultiSprite::move(float x, float y){

}

sf::Sprite* MultiSprite::getSprite(int i){
	return sprites.at(i);
}