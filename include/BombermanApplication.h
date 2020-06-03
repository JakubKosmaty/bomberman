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
#include "Player.h"
#include "Player1Inputer.h"
#include "Player2Inputer.h"

//#define DEBUG

class BombermanApplication {
private:
    sf::RenderWindow* window;

    TileMap* map;
    std::vector<Player*> players;

    float deltaTime;
    sf::Clock clock;

    void initWindow();
    void initMap();
    void initPlayers();

    void update();
    void render();

    friend std::ostream& operator<<(std::ostream& os, const BombermanApplication& application);

public:
    BombermanApplication();
    virtual ~BombermanApplication();

    void run();
};


#endif //BOMBERMAN_BOMBERMANAPPLICATION_H
