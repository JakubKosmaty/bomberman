//
// Created by Jakub Kosmaty on 09/05/2020.
//

#ifndef BOMBERMAN_BOMBERMANAPPLICATION_H
#define BOMBERMAN_BOMBERMANAPPLICATION_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <Config.h>

#include "TileMap.h"


class BombermanApplication {
private:
    sf::RenderWindow* window;

    TileMap* map;

    void initWindow();
    void initMap();

public:
    BombermanApplication();
    virtual ~BombermanApplication();

    void run();
    void update();
    void render();
};


#endif //BOMBERMAN_BOMBERMANAPPLICATION_H
