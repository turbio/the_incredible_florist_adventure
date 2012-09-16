#include "LogicHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define TITLE "The Incredible Florist Adventure"

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE);
}

//DESTRUCTOR
LogicHandler::~LogicHandler(void){

}

void LogicHandler::run(void){
	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
			handleEvent(event);
        }
		window->clear(sf::Color(255, 0, 255));
		window->display();
    }
}

void LogicHandler::update(void){

}

void LogicHandler::handleEvent(sf::Event evt){
	if (evt.type == sf::Event::Closed)
				window->close();
}
