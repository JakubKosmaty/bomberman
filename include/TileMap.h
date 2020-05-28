//
// Created by Jakub Kosmaty on 21/05/2020.
//

#ifndef BOMBERMAN_TILEMAP_H
#define BOMBERMAN_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Config.h"

class TileMap : public sf::Drawable {
private:
    sf::Texture tileSet;
    sf::VertexArray* vertexArray;

    std::vector<int> mapArray;
    unsigned mapWidth;
    unsigned mapHeight;

public:
    TileMap(sf::Vector2u tileSize);
    virtual ~TileMap();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const std::vector<int> &getMapArray() const;
    unsigned getMapWidth() const;
    unsigned getMapHeight() const;
};


#endif //BOMBERMAN_TILEMAP_H
