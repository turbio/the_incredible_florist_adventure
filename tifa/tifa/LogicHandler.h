#pragma once
#include <SFML\Window.hpp>
#include <string>

class LogicHandler{

public:
	LogicHandler(void);
	~LogicHandler(void);
	void keyEvent(sf::Event keyboard_event);
	void update(void);
};