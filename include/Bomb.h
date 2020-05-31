//
// Created by Jakub Kosmaty on 28/05/2020.
//

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include <SFML/Graphics.hpp>

class Bomb : public sf::Drawable {
private:
    sf::RectangleShape body;
    int radius;


public:
    Bomb();
    virtual ~Bomb();

    void spawn(sf::Vector2f playerPos);
};


#endif //BOMBERMAN_BOMB_H
