//
// Created by Jakub Kosmaty on 21/05/2020.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "Animation.h"
#include "Inputer.h"
#include "Bomb.h"

class Player : public sf::Drawable {
private:
    sf::RectangleShape body;
    Animation animation;
    Inputer* inputer;

    unsigned row;
    float speed;

    int direction;
    sf::Vector2f playerPos;
    sf::Vector2f destination;
    bool isGoing;

    bool faceRight;

    sf::Vector2f directionToStep(int dir);

    bool checkCollision(const std::vector<int> map) const;

public:
    Player(const std::string& texture, sf::Vector2f playerSize, sf::Vector2f playerPos, sf::Vector2u imageCount, float switchTime, float speed, Inputer* inputer);
    virtual ~Player();

    void update(float deltaTime, const std::vector<int> map);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    float getSpeed() const;
    const sf::RectangleShape &getBody() const;
};


#endif //BOMBERMAN_PLAYER_H
