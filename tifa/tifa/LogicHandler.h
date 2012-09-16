#pragma once
#include <SFML\Graphics.hpp>	//uses graphics cuz itz a game dur
#include <fstream>
#include <string>
#include <vector>

class LogicHandler{

public:
	LogicHandler(void);	//CONSTRUCTOR
	~LogicHandler(void);	//DESTRUCTOR
	void update(double delta_time);	//update game stuff
	void run(void);	//main game loop

private:
	void handleEvent(sf::Event theEventToBeHandled);	//handles any and all events
	bool loadTextures(std::string directory);
	sf::RenderWindow *window;	//the main window (probobaly the only)
	std::vector<sf::Texture*> textureList;
};