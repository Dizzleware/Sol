#ifndef PLANET_HPP
#define PLANET_HPP 

#include <SFML/Graphics.hpp>

class Planet : public sf::CircleShape{
private:

public:
	float radius, mass;
	

	Planet(sf::Color color, float radius){
		setFillColor(color);
		setOrigin(radius, radius);
		setPosition(sf::Vector2f(800, 600 - radius));
		setRadius(radius);	
		mass = 600;
	}

	Planet(sf::Color color, float radius, float Mass, sf::Vector2f position){
		setFillColor(color);
		setOrigin(radius, radius);
		setPosition(position);
		setRadius(radius);	
		mass = Mass;
	}
};

#endif