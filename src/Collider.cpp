//
// Created by Jakub Kosmaty on 23/05/2020.
//

#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) : body(body) {

}

Collider::~Collider() {

}

bool Collider::checkCollision(Collider &other, float push) {
  sf::Vector2f otherPosition = other.getPosition();
  sf::Vector2f otherHalfSize = other.getPosition();
  sf::Vector2f thisPosition = this->getPosition();
  sf::Vector2f thisHalfSize = this->getHalfSize();

  float deltaX = otherPosition.x - thisPosition.x;
  float deltaY = otherPosition.y - thisPosition.y;

  float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
  float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

  if (intersectX < 0.0f && intersectY < 0.0f) {
    push = std::min(std::max(push, 0.0f), 1.0f);

    if (intersectX > intersectY) {
      if (deltaX > 0.0f) {
        this->move(intersectX * (1.0f - push), 0.0f);
        other.move(-intersectX * push, 0.0f);
      } else {
        this->move(-intersectX * (1.0f - push), 0.0f);
        other.move(intersectX * push, 0.0f);
      }
    } else {
      if (deltaY > 0.0f) {
        this->move(0.0f, intersectY * (1.0f - push));
        other.move(0.0f, -intersectY * push);
      } else {
        this->move(0.0f, -intersectY * (1.0f - push));
        other.move(0.0f, intersectY * push);
      }
    }

    return true;
  }

  return false;
}

sf::Vector2f Collider::getPosition() {
  return this->body.getPosition();
}

sf::Vector2f Collider::getHalfSize() {
  return this->body.getSize() / 2.0f;
}

void Collider::move(float dx, float dy) {
  this->body.move(dx, dy);
}
