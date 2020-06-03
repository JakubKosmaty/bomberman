//
// Created by Jakub Kosmaty on 27/05/2020.
//

#ifndef BOMBERMAN_INPUTER_H
#define BOMBERMAN_INPUTER_H

#include <SFML/Graphics.hpp>

class Inputer {
public:
    virtual ~Inputer() {}
    virtual int getInput() = 0;
};


#endif //BOMBERMAN_INPUTER_H
