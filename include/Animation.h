//
// Created by Jakub Kosmaty on 22/05/2020.
//

#ifndef BOMBERMAN_ANIMATION_H
#define BOMBERMAN_ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation {
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    sf::Texture texture;
    sf::IntRect uvRect;

    float totalTime;
    float switchTime;

public:
    Animation(const std::string& texture, sf::Vector2u imageCount, float switchTime);

    const sf::Texture &getTexture() const;
    const sf::IntRect &getUvRect() const;

    void update(int row, float deltaTime, bool faceRight);
};


#endif //BOMBERMAN_ANIMATION_H
