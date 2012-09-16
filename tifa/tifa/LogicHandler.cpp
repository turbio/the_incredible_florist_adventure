#include "LogicHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define TITLE "The Incredible Florist Adventure"


sf::Sprite sprite;
sf::RectangleShape shape;

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);

	shape.setSize(sf::Vector2f(10.0f, 10.0f));
	if(!LogicHandler::loadTextures("res/")){
		shape.setFillColor(sf::Color::Red);
	}else{
		shape.setFillColor(sf::Color::Green);
	}

	sprite.setTexture(*textureList.at(1));
	//sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
	sprite.setPosition(0, 0);
}

//DESTRUCTOR
LogicHandler::~LogicHandler(void){

}

void LogicHandler::run(void){

	double deltaTime = 0;
	sf::Clock clock;
	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
			handleEvent(event);
        }
		
		clock.restart();
		LogicHandler::update(deltaTime);

		window->clear(sf::Color(255, 0, 255));

		//render
		window->draw(sprite);
		window->draw(shape);

		deltaTime = clock.getElapsedTime().asMilliseconds();

		window->display();
    }
}

void LogicHandler::update(double delta){

}

void LogicHandler::handleEvent(sf::Event evt){
	if (evt.type == sf::Event::Closed)
		window->close();
}

bool LogicHandler::loadTextures(std::string dir){
	std::string line;
	std::vector<sf::Texture*> textures;

	std::ifstream file(dir + "res.txt");

	if(file.is_open()){
		while(file.good()){
			std::getline(file, line);

			sf::Texture *tex;
			tex = new sf::Texture;
			if(!tex->loadFromFile( dir + line)){
				return false;
			}
			textures.push_back(tex);
			
		}
		file.close();
	}else{
		return false;
	}

	textureList = textures;
	return true;
}
