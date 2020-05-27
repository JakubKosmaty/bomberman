//
// Created by Jakub Kosmaty on 21/05/2020.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Animation.h"
#include "Collider.h"
#include "Inputer.h"

class Player : public sf::Drawable {
private:
    sf::RectangleShape body;

    Animation animation;
    Inputer* inputer;

    unsigned row;
    float speed;

public:
    Player(const std::string& texture, sf::Vector2f playerSize, float posX, float posY, sf::Vector2u imageCount, float switchTime, float speed, Inputer* inputer);
    virtual ~Player();

    void update(float deltaTime);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Vector2f getPosition();
    Collider getCollider();
};


#endif //BOMBERMAN_PLAYER_H
