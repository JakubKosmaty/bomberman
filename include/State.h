//
// Created by Jakub Kosmaty on 17/05/2020.
//

#ifndef BOMBERMAN_STATE_H
#define BOMBERMAN_STATE_H


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#define XSTR(x) #x
#define STR(x) XSTR(x)

class State {

private:
    std::vector<sf::Texture> textures;

public:
    State();
    virtual ~State();

    virtual void update() = 0;
    virtual void render() = 0;
};


#endif //BOMBERMAN_STATE_H
