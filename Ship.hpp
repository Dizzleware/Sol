

#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Planet.hpp"


class Ship : public sf::ConvexShape{
private:
	sf::Vector2f updateVector();
	float width, height;
public:

	

	sf::Vector2f updateVector(float rotation, float speed, sf::Vector2f vector);
	sf::Vector2f updateVector_Radian(float rotation, float speed, sf::Vector2f vector);
	//Mathematical Utility Classes
	float degToRad(float degrees);
	float findDistance(sf::Vector2f targetPosition);
	//State Classes
	void processEvent(sf::Event event);
	void resetEventState();
	void updateState();
	void calculateGravityAcceleration(Planet * planet);
	void checkPlanetCollision(const Planet* planet);
	//Object Properties
	sf::Vector2f velocity;
	float acceleration, rotSpeed;
	//State properties
	bool leftPressed, rightPressed, spacePressed;

	Ship(sf::Vector2f Velocity, sf::Vector2f position, sf::Color color, float width = 5, float height = 10){
		velocity = Velocity;
		setPosition(position);
		setFillColor(color);
		
		setPointCount(3);
		setPoint(0, position);
		setPoint(1, sf::Vector2f( (position.x - width / 2), (position.y + height)));
		setPoint(2, sf::Vector2f( (position.x + width / 2), (position.y + height)));

		setOrigin(position.x, position.y + height/2);
		acceleration = .1;
		rotSpeed = 10;

	}

	Ship(){
		
	}
};

#endif