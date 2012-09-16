#include <SFML/Graphics.hpp>
#include "LogicHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define TITLE "The Incredible Florist Adventure"

int main(){
	//crate window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);

	LogicHandler logic;	//crate logic handler to handle basicly everything

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}