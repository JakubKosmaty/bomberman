//
// Created by Jakub Kosmaty on 21 /05/2020.
//

#include "Player.h"

Player::Player(const std::string& texture, sf::Vector2f playerSize, float posX, float posY, sf::Vector2u imageCount, float switchTime, float speed, Inputer* inputer) : animation(texture, imageCount, switchTime), inputer(inputer) {
  this->speed = speed;
  this->row = 0;

  this->body.setSize(playerSize);
  this->body.setPosition(posX, posY);
  this->body.setTexture(&this->animation.texture);
}

Player::~Player() {
  delete this->inputer;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.texture = &this->animation.texture;
  target.draw(this->body, states);
}

void Player::update(float deltaTime) {
  sf::Vector2f movement(0.00f, 0.00f);

  bool faceRight = true;

  int input = this->inputer->getInput();

  if (input == 0) {
    movement.x -= this->speed * deltaTime;
    this->row = 2;
    faceRight = false;
  }

  if (input == 1) {
    movement.x += this->speed * deltaTime;
    this->row = 2;
    faceRight = true;
  }

  if (input == 2) {
    movement.y -= this->speed * deltaTime;
    this->row = 1;
  }

  if (input == 3) {
    movement.y += this->speed * deltaTime;
    this->row = 0;
  }

  this->animation.update(this->row, deltaTime, faceRight);
  this->body.setTextureRect(this->animation.uvRect);
  this->body.move(movement);
}

sf::Vector2f Player::getPosition() {
  return this->body.getPosition();
}

Collider Player::getCollider() {
  return Collider(this->body);
}
