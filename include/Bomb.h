//
// Created by Jakub Kosmaty on 28/05/2020.
//

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include <SFML/Graphics.hpp>
#include "TileMap.h"

class Bomb {
private:
    sf::Vector2i bombPos;
    sf::Clock bombClock;
    sf::Clock fireClock;

    int radius;
    bool clean;
    bool used;

    void setFire(TileMap* tileMap);
    void cleanFire(TileMap* tileMap);

public:
    Bomb(int radius);

    void spawn(sf::Vector2i bombPos, TileMap* tileMap);
    void check(TileMap* tileMap);

    bool isUsed() const;
};


#endif //BOMBERMAN_BOMB_H
