//
// Created by Jakub Kosmaty on 21/05/2020.
//

#ifndef BOMBERMAN_TILEMAP_H
#define BOMBERMAN_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Config.h"
#include "Layer.h"

class TileMap : public sf::Drawable {
private:


public:
    std::vector<Layer*> layers;

    TileMap();
    virtual ~TileMap();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //BOMBERMAN_TILEMAP_H
