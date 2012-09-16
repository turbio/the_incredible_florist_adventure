#include "LogicHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define TITLE "The Incredible Florist Adventure"

sf::Sprite titleScreenBg, yamster;
sf::RectangleShape shape;

InfinitePan clouds, ground;

//CONSTRUCTOR
LogicHandler::LogicHandler(void){
	titleScreen = true;
	elapsedTime = 1;

	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);

	shape.setSize(sf::Vector2f(10.0f, 10.0f));
	if(!LogicHandler::loadTextures("res/")){
		shape.setFillColor(sf::Color::Red);
	}else{
		shape.setFillColor(sf::Color::Green);
	}

	titleScreenBg.setTexture(*textureList.at(1));
	titleScreenBg.setPosition(0, 0);

	sf::Sprite *cloudSprite = new sf::Sprite();
	cloudSprite->setTexture(*textureList.at(2));
	spriteList.push_back(cloudSprite);
	spriteList.push_back(clouds.setSprite(cloudSprite, WIDTH, -0.0001f, 0.0f));

	sf::Sprite *groundSprite = new sf::Sprite();
	groundSprite->setTexture(*textureList.at(3));
	spriteList.push_back(groundSprite);
	spriteList.push_back(ground.setSprite(groundSprite, WIDTH, -0.001f, 350.0f));

	yamster.setTexture(*textureList.at(4));
	spriteList.push_back(&yamster);
	yamster.scale(0.25, 0.25);
	yamster.setOrigin(167, 340);
	yamster.setPosition(50, 300);

	window->setFramerateLimit(0);
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

		window->clear(sf::Color(20, 180, 255));

		//render
		if(titleScreen){
			window->draw(titleScreenBg);
		}else{
			for(int i = 0; i < spriteList.size(); i++){
				window->draw(*spriteList.at(i));
			}
		}

		window->draw(shape);
		shape.move(1, 0);
		
		deltaTime = (double)clock.getElapsedTime().asMicroseconds();

		window->display();
    }
}

void LogicHandler::update(double delta){
	elapsedTime += (delta * 0.0001);
	if(!titleScreen){
		clouds.update(delta);
		ground.update(delta);
		yamster.setRotation(sin(elapsedTime * 0.15) * 10);
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
			
			std::cout << "res: " << line;

			sf::Texture *tex;
			tex = new sf::Texture;
			if(!tex->loadFromFile( dir + line)){
				return false;
			}
			textures.push_back(tex);
			
			std::cout << " loaded" << std::endl;
		}
		file.close();
	}else{
		return false;
	}

	textureList = textures;
	return true;
}
