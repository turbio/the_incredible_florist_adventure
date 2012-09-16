#pragma once
#include <SFML\Graphics.hpp>	//uses graphics cuz itz a game dur

class LogicHandler{

public:
	LogicHandler(void);	//CONSTRUCTOR
	~LogicHandler(void);	//DESTRUCTOR
	void update(void);	//update game stuff
	void run(void);	//main game loop

private:
	void handleEvent(sf::Event theEventToBeHandled);	//handles any and all events
	sf::RenderWindow *window;	//the main window (probobaly the only)
};