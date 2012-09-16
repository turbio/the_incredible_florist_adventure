#pragma once
#include <SFML\Graphics.hpp>	//uses graphics cuz itz a game dur
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class LogicHandler{

public:
	LogicHandler(void);	//CONSTRUCTOR
	~LogicHandler(void);	//DESTRUCTOR
	void update(float delta_time);	//update game stuff
	void run(void);	//main game loop

private:
	void handleEvent(sf::Event theEventToBeHandled);	//handles any and all events
	bool loadTextures(std::string directory);
	sf::RenderWindow *window;	//the main window (probobaly the only)
	std::vector<sf::Texture*> textureList;	//list of all textures currently loaded
	std::vector<sf::Sprite*> spriteList;	//list of all active sprites
	bool titleScreen;	//if the game is at the title screen
};