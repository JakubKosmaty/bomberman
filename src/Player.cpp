//
// Created by Jakub Kosmaty on 21 /05/2020.
//

#include "Player.h"

Player::Player(const std::string& texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime) {
  this->speed = speed;
  this->row = 0;

  this->body.setSize(sf::Vector2f(64.0f, 128.0f));
  this->body.setPosition(64.0f, 128.0f);
  this->body.setTexture(&this->animation.texture);
}

Player::~Player() {
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.texture = &this->animation.texture;
  target.draw(this->body, states);
}

void Player::update(float deltaTime) {
  sf::Vector2f movement(0.00f, 0.00f);

  bool faceRight = true;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    movement.x -= this->speed * deltaTime;
    this->row = 2;
    faceRight = false;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    movement.x += this->speed * deltaTime;
    this->row = 2;
    faceRight = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    movement.y -= this->speed * deltaTime;
    this->row = 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    movement.y += this->speed * deltaTime;
    this->row = 0;
  }

  this->animation.update(this->row, deltaTime, faceRight);
  this->body.setTextureRect(this->animation.uvRect);
  this->body.move(movement);
}