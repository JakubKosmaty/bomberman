//
// Created by Jakub Kosmaty on 21/05/2020.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Animation.h"

class Player : public sf::Drawable {
private:
    sf::RectangleShape body;

    Animation animation;

    unsigned row;
    float speed;

public:
    Player(const std::string& texture, sf::Vector2u imageCount, float switchTime, float speed);
    virtual ~Player();

    void update(float deltaTime);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif //BOMBERMAN_PLAYER_H
