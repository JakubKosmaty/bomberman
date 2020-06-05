//
// Created by Jakub Kosmaty on 02/06/2020.
//

#include "Layer.h"

Layer::Layer() {

  const MapConfig &map = Config::getConfig().getMap();
  this->mapArray = map.getData();
  this->mapWidth = map.getWidth();
  this->mapHeight = map.getHeight();
  this->tileSize = map.getTileSize();

  this->tileSet.loadFromFile(RESOURCE_PATH(mapTile.png));

  this->vertexArray.setPrimitiveType(sf::Quads);
  this->vertexArray.resize(map.getWidth() * map.getHeight() * 4);
  this->update();
}

void Layer::update() {
  for (int i = 0; i < this->mapWidth; i++) {
    for (int j = 0; j < this->mapHeight; j++) {

      int tileNumber = this->mapArray[i + j * this->mapWidth];

      int tu = tileNumber % (this->tileSet.getSize().x / this->tileSize);
      int tv = tileNumber / (this->tileSet.getSize().x / this->tileSize);

      sf::Vertex *quad = &(this->vertexArray)[(i + j * this->mapWidth) * 4];

      quad[0].position = sf::Vector2f(i * this->tileSize, j * this->tileSize);
      quad[1].position = sf::Vector2f((i + 1) * this->tileSize, j * this->tileSize);
      quad[2].position = sf::Vector2f((i + 1) * this->tileSize, (j + 1) * this->tileSize);
      quad[3].position = sf::Vector2f(i * this->tileSize, (j + 1) * this->tileSize);

      quad[0].texCoords = sf::Vector2f(tu * this->tileSize, tv * this->tileSize);
      quad[1].texCoords = sf::Vector2f((tu + 1) * this->tileSize, tv * this->tileSize);
      quad[2].texCoords = sf::Vector2f((tu + 1) * this->tileSize, (tv + 1) * this->tileSize);
      quad[3].texCoords = sf::Vector2f(tu * this->tileSize, (tv + 1) * this->tileSize);
    }
  }
}

void Layer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.texture = &this->tileSet;
  target.draw(this->vertexArray, states);
}

const std::vector<int> &Layer::getMapArray() const {
  return mapArray;
}

