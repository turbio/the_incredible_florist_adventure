#include "LogicHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define TITLE "The Incredible Florist Adventure"


sf::Sprite titleScreenBg, cloud1, cloud2;
sf::RectangleShape shape;

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	titleScreen = true;

	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);

	shape.setSize(sf::Vector2f(10.0f, 10.0f));
	if(!LogicHandler::loadTextures("res/")){
		shape.setFillColor(sf::Color::Red);
	}else{
		shape.setFillColor(sf::Color::Green);
	}

	titleScreenBg.setTexture(*textureList.at(1));
	titleScreenBg.setPosition(0, 0);

	cloud1.setTexture(*textureList.at(2));
	cloud2.setTexture(*textureList.at(2));
}

//DESTRUCTOR
LogicHandler::~LogicHandler(void){

}

void LogicHandler::run(void){

	float deltaTime = 0;
	sf::Clock clock;
	while (window->isOpen()){
		sf::Event event;
		while (window->pollEvent(event)){
			handleEvent(event);
        }
		
		clock.restart();
		LogicHandler::update(deltaTime);

		window->clear(sf::Color(20, 180, 255));

		//render
		if(titleScreen){
			window->draw(titleScreenBg);
		}else{
			window->draw(cloud1);
			window->draw(cloud2);
		}

		window->draw(shape);
		shape.move(1, 0);

		deltaTime = clock.getElapsedTime().asMilliseconds();

		window->display();
    }
}

void LogicHandler::update(float delta){
	if(!titleScreen){
		cloud1.move(-0.01f * delta, 0.0f);
		cloud2.setPosition(WIDTH + cloud1.getPosition().x, 0);
	}
}

void LogicHandler::handleEvent(sf::Event evt){
	if (evt.type == sf::Event::Closed){
		window->close();
	}else if((evt.type == sf::Event::KeyPressed ||
		evt.type == sf::Event::MouseButtonPressed) && titleScreen){
			titleScreen = false;
	}
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
