//
// Created by Jakub Kosmaty on 23/05/2020.
//

#ifndef BOMBERMAN_COLLIDER_H
#define BOMBERMAN_COLLIDER_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Collider {

private:

    sf::RectangleShape& body;

public:
    Collider(sf::RectangleShape& body);
    virtual ~Collider();

    void move(float dx, float dy);

    bool checkCollision(Collider &other, float push);
    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize();



};


#endif //BOMBERMAN_COLLIDER_H
