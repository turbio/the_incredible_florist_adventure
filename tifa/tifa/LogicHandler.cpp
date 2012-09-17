#include "LogicHandler.h"

#define WIDTH 640
#define HEIGHT 480
#define TITLE "The Incredible Florist Adventure"

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

	setupSprites();

	window->setFramerateLimit(0);
}

void LogicHandler::setupSprites(void){
	//setup panning clouds
	sf::Sprite *cloudSprite = new sf::Sprite();
	cloudSprite->setTexture(*textureList.at(2));
	spriteList.push_back(cloudSprite);
	spriteList.push_back(clouds.setSprite(cloudSprite, WIDTH, -0.0001f, 0.0f));

	//setup panning ground
	sf::Sprite *groundSprite = new sf::Sprite();
	groundSprite->setTexture(*textureList.at(3));
	spriteList.push_back(groundSprite);
	spriteList.push_back(ground.setSprite(groundSprite, WIDTH, -0.001f, 350.0f));

	//crate player
	//leg
	sf::Sprite *playerSprite = new sf::Sprite(*textureList.at(7));
	playerSprite->scale(0.30, 0.30);
	playerSprite->setOrigin(25, 0);
	playerSprite->move(125, 280);
	spriteList.push_back(player.addSprite(playerSprite));

	//body
	playerSprite = new sf::Sprite(*textureList.at(6));
	playerSprite->scale(0.30, 0.30);
	playerSprite->move(100, 190);
	spriteList.push_back(player.addSprite(playerSprite));

	//head
	playerSprite = new sf::Sprite(*textureList.at(4));
	playerSprite->scale(0.30, 0.30);
	playerSprite->setOrigin(167.5, 340);
	playerSprite->move(100, 200);
	spriteList.push_back(player.addSprite(playerSprite));
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
	elapsedTime += (delta * 0.00001);

	//move joints
	player.getSprite(0)->setRotation(elapsedTime);
	player.getSprite(2)->setRotation(elapsedTime);

	if(!titleScreen){
		clouds.update(delta);
		ground.update(delta);
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
