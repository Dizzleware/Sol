#include <SFML/Graphics.hpp>
#include "Ship.hpp"

sf::Vector2f Ship::updateVector(float rotation, float speed, sf::Vector2f vector){

    vector.x += sin(degToRad(rotation)) * speed;
    vector.y -= cos(degToRad(rotation)) * speed;
    return vector;
}

sf::Vector2f Ship::updateVector(){
    velocity.x += sin(degToRad(getRotation())) * acceleration;
    velocity.y -= cos(degToRad(getRotation())) * acceleration;
    return velocity;
}

sf::Vector2f Ship::updateVector_Radian(float rotation, float speed, sf::Vector2f vector){

    vector.x += sin(rotation) * speed;
    vector.y -= cos(rotation) * speed;
    return vector;
}

void Ship::calculateGravityAcceleration(Planet * planet){
    /*
        BUG!! I fixed it temp with if glue. Basically, once it crosses an axis, it will multiply the vector by -1 or something, really strange, exhibits hyperbolic behavior
    */
    float distance = findDistance(planet -> getPosition());
    float mass = planet -> mass;
    sf::Vector2f v;

    float accel = mass / pow(distance, 2);
    if(accel <= 0){accel *= -1;}

    float dy = planet -> getPosition().y - getPosition().y;
    float dx = planet -> getPosition().x - getPosition().x;
    float rotation = atan2(dy , dx); // Converts to radians in the update vector function

    v = updateVector_Radian(rotation, accel, v);

    //FIx it glue
    if(getPosition().x >= planet -> getPosition().x && getPosition().y <= planet -> getPosition().y){
        v.x *= -1;
        v.y *= -1;
    }

    if(getPosition().x <= planet -> getPosition().x && getPosition().y >= planet -> getPosition().y){
        v.x *= -1;
        v.y *= -1;
    }

    velocity.x += v.x;
    velocity.y -= v.y; 
}

void Ship::checkPlanetCollision(const Planet* planet){
    
}


float Ship::degToRad(float degrees){
    float rad;

    rad = degrees * (3.14259 / 180.0);
    return rad;
}

float Ship::findDistance(sf::Vector2f targetPosition){
    sf::Vector2f position = getPosition();
    return sqrt( pow((position.x - targetPosition.x), 2)  +  pow(position.y - targetPosition.y, 2));
}

void Ship::processEvent(sf::Event event){
    resetEventState();
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Left)){
        leftPressed = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        rightPressed = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        spacePressed = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        setPosition(50,50);
        setRotation(0);
        velocity.x = 0;
        velocity.y = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){setFillColor(sf::Color::Green);}else{setFillColor(sf::Color::Red);}
}
void Ship::resetEventState(){
    leftPressed = false;
    rightPressed = false;
    spacePressed = false;
}

void Ship::updateState(){
    
    if(leftPressed){
        rotate(-rotSpeed);
    }

    if(rightPressed){
        rotate(rotSpeed);
    }

    if(spacePressed){
        updateVector();
    }

    move(velocity);
    

}