//
// Created by Jakub Kosmaty on 21/05/2020.
//

#include "TileMap.h"

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.texture = &this->tileSet;
  target.draw(*this->vertexArray, states);
}

TileMap::TileMap(sf::Vector2u tileSize) {
  this->vertexArray = new sf::VertexArray();

  const Map &map = Config::getConfig().getMap();
  this->mapArray = map.getData();

  this->tileSet.loadFromFile(RESOURCE_PATH(mapTile.png));

  this->vertexArray->setPrimitiveType(sf::Quads);
  this->vertexArray->resize(map.getWidth() * map.getHeight() * 4);


  for (unsigned int i = 0; i < map.getWidth(); i++) {
    for (unsigned int j = 0; j < map.getHeight(); j++) {

      int tileNumber = this->mapArray[i + j * map.getWidth()];

      int tu = tileNumber % (this->tileSet.getSize().x / tileSize.x);
      int tv = tileNumber / (this->tileSet.getSize().x / tileSize.x);

      sf::Vertex *quad = &((*this->vertexArray)[(i + j * map.getWidth() ) * 4]);

      quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
      quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
      quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
      quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

      quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
      quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
      quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
      quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

    }
  }
}

TileMap::~TileMap() {
  delete this->vertexArray;
}


