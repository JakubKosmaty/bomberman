//
// Created by Jakub Kosmaty on 21/05/2020.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <SFML/Graphics.hpp>

#include "Animation.h"
#include "Inputer.h"
#include "Bomb.h"
#include "TileMap.h"

class Player : public sf::Drawable {
private:
    sf::RectangleShape body;
    Animation animation;
    Inputer* inputer;
    Bomb bomb;

    sf::Vector2f playerPos;
    sf::Vector2f destination;

    int direction;
    unsigned row;

    float speed;

    bool isGoing;
    bool faceRight;
    bool dead;

    sf::Vector2f directionToStep(int dir);

    const bool checkCollision(const std::vector<int>& map) const;
    const bool checkIsDead(const std::vector<int>& map) const;

public:
    Player(const std::string& texture, sf::Vector2f playerSize, sf::Vector2f playerPos, sf::Vector2u imageCount, float switchTime, float speed, Inputer* inputer, int radius);
    virtual ~Player();

    void update(float deltaTime, TileMap* tileMap);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const float getSpeed() const;
    const sf::RectangleShape &getBody() const;
    const bool isDead() const;
};

#endif //BOMBERMAN_PLAYER_H
