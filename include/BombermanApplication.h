//
// Created by Jakub Kosmaty on 09/05/2020.
//

#ifndef BOMBERMAN_BOMBERMANAPPLICATION_H
#define BOMBERMAN_BOMBERMANAPPLICATION_H

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "Config.h"
#include "TileMap.h"
#include "Player.h"
#include "Player1Inputer.h"
#include "Player2Inputer.h"
#include "Menu.h"

enum GAME_STATE {
    MENU = 0,
    RUN,
    GAME_OVER
};

class BombermanApplication {
private:
    sf::RenderWindow* window;
    Menu menu;
    TileMap* map;
    std::vector<Player*> players;

    GAME_STATE gameState;

    float deltaTime;
    sf::Clock clock;

    void initWindow();
    void initMap();
    void initPlayers();
    void initMenu();

    void update();
    void render();
    void restart();

    friend std::ostream& operator<<(std::ostream& os, const BombermanApplication& application);

public:
    BombermanApplication();
    virtual ~BombermanApplication();

    void run();
};


#endif //BOMBERMAN_BOMBERMANAPPLICATION_H
