//
// Created by Jakub Kosmaty on 28/05/2020.
//

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include <SFML/Graphics.hpp>
#include "TileMap.h"

class Bomb {
private:

    int radius;



public:
    sf::Clock bombClock;
    sf::Clock fireClock;

    bool clean;
    bool used;
    sf::Vector2i bombPos;

    Bomb(int radius = 4);
    virtual ~Bomb();

    void spawn(sf::Vector2i bombPos, TileMap* tileMap);
    void check(TileMap* tileMap);
    void cleanFire(TileMap* tileMap);

};


#endif //BOMBERMAN_BOMB_H
