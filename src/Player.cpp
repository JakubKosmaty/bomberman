//
// Created by Jakub Kosmaty on 21/05/2020.
//

#include "Player.h"

Player::Player(const std::string& texture, sf::Vector2f playerSize, sf::Vector2f playerPos, sf::Vector2u imageCount, float switchTime, float speed, Inputer* inputer) : animation(texture, imageCount, switchTime), inputer(inputer) {
  this->speed = speed;
  this->row = 0;

  this->direction = -1;
  this->isGoing = false;
  this->playerPos = this->body.getPosition();


  this->body.setSize(playerSize);
  this->body.setOrigin(playerSize.x / 2, playerSize.y > 64 ? 96 : 32);
  this->body.setPosition(playerPos);
  this->body.setTexture(&this->animation.getTexture());
  this->body.setTextureRect(this->animation.getUvRect());
}

Player::~Player() {
  delete this->inputer;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.texture = &this->animation.getTexture();
  target.draw(this->body, states);
}

sf::Vector2f Player::directionToStep(int dir) {
  if (dir == 0) {
    this->row = 2;
    this->faceRight = false;
    return {-this->speed, 0};
  } else if (dir == 1) {
    this->row = 2;
    this->faceRight = true;
    return {this->speed, 0};
  } else if (dir == 2) {
    this->row = 1;
    return {0, -this->speed};
  } else if (dir == 3) {
    this->row = 0;
    return {0, this->speed};
  }

  return {0, 0};
}

bool Player::checkCollision(const std::vector<int> map) const {
  int x = this->destination.x / 64;
  int y = this->destination.y / 64;
  int collision = map[x + y * 13];
  return collision == 0 || collision == 2 || collision == 3;
}

#include <iostream>

bool Player::checkIsDead(const std::vector<int> map) const {
  int x = this->body.getPosition().x / 64;
  int y = this->body.getPosition().y / 64;

  return map[x + y * 13] == 4;
}

void Player::update(float deltaTime, TileMap* tileMap) {
  this->bomb.check(tileMap);

  int input = this->inputer->getInput();

  if (input == 4 && !this->bomb.isUsed()) {
    sf::Vector2i bombPos;
    bombPos.x = this->body.getPosition().x / 64;
    bombPos.y = this->body.getPosition().y / 64;
    this->bomb.spawn(bombPos, tileMap);
  }

  if (this->checkIsDead(tileMap->layers[1]->getMapArray())) {
    this->dead = true;
    return;
  }

  if (this->isGoing) {
    if (checkCollision(tileMap->layers[0]->getMapArray())|| checkCollision(tileMap->layers[1]->getMapArray())) {
      this->isGoing = false;
      return;
    }

    if (this->body.getPosition() != this->destination) {
      sf::Vector2f step = directionToStep(this->direction);
      sf::Vector2f newStep = directionToStep(input);

      if (step == -newStep) {
        step = newStep;
        this->direction = input;
        this->destination = this->destination + (step / this->speed) * 64.f;
        return;
      }

      this->animation.update(this->row, deltaTime, this->faceRight);
      this->body.setTextureRect(this->animation.getUvRect());
      this->body.move(step);
      return;
    }

    this->isGoing = false;
  }

  if (input == -1) {
    return;
  }

  this->isGoing = true;
  this->direction = input;

  switch (input) {
    case 0: {
      this->destination.x = this->body.getPosition().x - 64;
      this->destination.y = this->body.getPosition().y;
      return;
    }
    case 1: {
      this->destination.x = this->body.getPosition().x + 64;
      this->destination.y = this->body.getPosition().y;
      return;
    }
    case 2: {
      this->destination.y = this->body.getPosition().y - 64;
      this->destination.x = this->body.getPosition().x;
      return;
    }
    case 3: {
      this->destination.y = this->body.getPosition().y + 64;
      this->destination.x = this->body.getPosition().x;
      return;
    }
  }
}

const sf::RectangleShape &Player::getBody() const {
  return body;
}

float Player::getSpeed() const {
  return speed;
}

bool Player::isDead() const {
  return dead;
}

