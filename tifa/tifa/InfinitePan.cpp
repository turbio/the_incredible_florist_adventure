#include "InfinitePan.h"


InfinitePan::InfinitePan(void){

}


InfinitePan::~InfinitePan(void){

}

sf::Sprite* InfinitePan::setSprite(sf::Sprite *spr, float with, float ve, float y){
	sprite = spr;
	sprite1 = new sf::Sprite(*spr);

	sprite->setPosition(0, y);
	sprite1->setPosition(with, y);

	width = with;
	InfinitePan::vel = ve;
	InfinitePan::yPos = y;

	return sprite1;
}

void InfinitePan::update(double delta){
	sprite->move(vel * delta, yPos);
	sprite1->move(vel * delta, yPos);

	if(sprite->getPosition().x < -width){
		sprite->setPosition(width, yPos);
	}
	if(sprite1->getPosition().x < -width){
		sprite1->setPosition(width, yPos);
	}

}