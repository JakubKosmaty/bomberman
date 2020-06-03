//
// Created by Jakub Kosmaty on 28/05/2020.
//

#include "Bomb.h"

Bomb::Bomb(int radius) {
  this->radius = radius;
  this->used = false;
  this->clean = false;
}

Bomb::~Bomb() {

}

void Bomb::check(TileMap *tileMap) {
  if (this->used && !this->clean && this->bombClock.getElapsedTime().asSeconds() >= 2) {
    this->setFire(tileMap);
  }

  if (this->clean && this->fireClock.getElapsedTime().asSeconds() >= 2) {
    this->cleanFire(tileMap);
  }
}

void Bomb::spawn(sf::Vector2i bombPos, TileMap* tileMap) {
  this->bombClock.restart();

  this->bombPos = bombPos;

  tileMap->layers[1]->mapArray[bombPos.x + bombPos.y * 13] = 3;
  tileMap->layers[1]->update();

  this->used = true;
}

void Bomb::setFire(TileMap* tileMap) {
  if (this->bombClock.getElapsedTime().asSeconds() >= 2) {

    for (int i = 0; i < this->radius; i++) {
      if (tileMap->layers[1]->mapArray[bombPos.x + i + bombPos.y * 13] == 0) {
        break;
      }

      if (tileMap->layers[0]->mapArray[bombPos.x + i + bombPos.y * 13] == 2) {
        tileMap->layers[0]->mapArray[bombPos.x + i + bombPos.y * 13] = 1;
      }

      tileMap->layers[1]->mapArray[bombPos.x + i + bombPos.y * 13] = 4;
    }

    for (int i = 0; i < this->radius; i++) {
      if (tileMap->layers[1]->mapArray[bombPos.x - i + bombPos.y * 13] == 0) {
        break;
      }

      if (tileMap->layers[0]->mapArray[bombPos.x - i + bombPos.y * 13] == 2) {
        tileMap->layers[0]->mapArray[bombPos.x - i + bombPos.y * 13] = 1;
      }

      tileMap->layers[1]->mapArray[bombPos.x - i + bombPos.y * 13] = 4;
    }

    for (int i = 0; i < this->radius; i++) {
      if (tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y + i) * 13] == 0) {
        break;
      }

      if (tileMap->layers[0]->mapArray[bombPos.x + (bombPos.y + i) * 13] == 2) {
        tileMap->layers[0]->mapArray[bombPos.x + (bombPos.y + i) * 13] = 1;
      }

      tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y + i) * 13] = 4;
    }


    for (int i = 0; i < this->radius; i++) {
      if (tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y - i) * 13] == 0) {
        break;
      }

      if (tileMap->layers[0]->mapArray[bombPos.x + (bombPos.y - i) * 13] == 2) {
        tileMap->layers[0]->mapArray[bombPos.x + (bombPos.y - i) * 13] = 1;
      }

      tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y - i) * 13] = 4;
    }


    tileMap->layers[0]->update();
    tileMap->layers[1]->update();

    fireClock.restart();
    this->clean = true;
  }
}

void Bomb::cleanFire(TileMap* tileMap) {
  for (int i = 0; i < this->radius; i++) {
    if (tileMap->layers[1]->mapArray[bombPos.x + i + bombPos.y * 13] == 0) {
      break;
    }

    tileMap->layers[1]->mapArray[bombPos.x + i + bombPos.y * 13] = 1;
  }

  for (int i = 0; i < this->radius; i++) {
    if (tileMap->layers[1]->mapArray[bombPos.x - i + bombPos.y * 13] == 0) {
      break;
    }

    tileMap->layers[1]->mapArray[bombPos.x - i + bombPos.y * 13] = 1;
  }

  for (int i = 0; i < this->radius; i++) {
    if (tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y + i) * 13] == 0) {
      break;
    }

    tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y + i) * 13] = 1;
  }


  for (int i = 0; i < this->radius; i++) {
    if (tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y - i) * 13] == 0) {
      break;
    }

    tileMap->layers[1]->mapArray[bombPos.x + (bombPos.y - i) * 13] = 1;
  }

  tileMap->layers[1]->update();

  this->clean = false;
  this->used = false;

}

bool Bomb::isUsed() const {
  return used;
}



