#include <SFML/Graphics.hpp>
#include <iostream>
#include "Planet.hpp"
#include "Ship.hpp"

int main(){
	sf::RenderWindow window(sf::VideoMode(1600,1200), "Sol");
	sf::View view;
	//Create Game Objects Here
	Planet planet(sf::Color::Blue, 100);

	Ship ship(sf::Vector2f(0,0), sf::Vector2f(50,50), sf::Color::Red, 15.0, 25.0);

	//Modify Game Objects
	
	while(window.isOpen()){

		sf::Event event;
		while(window.pollEvent(event)){
			
			if(event.type == sf::Event::Closed){
				window.close();
			}
			//send events to objects here
			ship.processEvent(event);
			view.setCenter(ship.getPosition());
		}
		//update object state here

		ship.updateState();
		ship.calculateGravityAcceleration(&planet);
		window.clear(sf::Color::Black);
		//draw stuff
		window.draw(planet);
		window.draw(ship);

		window.display();
	}
}