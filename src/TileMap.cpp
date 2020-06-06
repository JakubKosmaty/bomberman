//
// Created by Jakub Kosmaty on 21/05/2020.
//

#include "TileMap.h"

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  for (int i = 0; i < this->layers.size(); i++) {
    this->layers[i]->draw(target, states);
  }
}

TileMap::~TileMap() {
  for (int i = 0; i < this->layers.size(); i++) {
    delete this->layers[i];
  }
}
