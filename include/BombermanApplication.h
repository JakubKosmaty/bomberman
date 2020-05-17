//
// Created by Jakub Kosmaty on 09/05/2020.
//

#ifndef BOMBERMAN_BOMBERMANAPPLICATION_H
#define BOMBERMAN_BOMBERMANAPPLICATION_H

#include "State.h"

class BombermanApplication {

private:
    sf::RenderWindow *window{};
    sf::Event sfEvent{};

    sf::Clock dtClock;
    float dt{};
    void initWindow();

public:
    BombermanApplication();

    virtual ~BombermanApplication();


    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};


#endif //BOMBERMAN_BOMBERMANAPPLICATION_H
