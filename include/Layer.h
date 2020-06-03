//
// Created by Jakub Kosmaty on 02/06/2020.
//

#ifndef BOMBERMAN_LAYER_H
#define BOMBERMAN_LAYER_H

#include <SFML/Graphics.hpp>
#include <Config.h>

class Layer : public sf::Drawable {

private:
    sf::Texture tileSet;
    sf::VertexArray* vertexArray;

    unsigned mapWidth;
    unsigned mapHeight;
    unsigned tileSize;

public:
    std::vector<int> mapArray;
    const std::vector<int> &getMapArray() const;

    Layer();
    virtual ~Layer();

    void update();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //BOMBERMAN_LAYER_H
