//
// Created by Jakub Kosmaty on 22/05/2020.
//

#include "Animation.h"

Animation::Animation(const std::string& texture, sf::Vector2u imageCount, float switchTime) {
  this->texture.loadFromFile(texture);

  this->imageCount = imageCount;
  this->switchTime = switchTime;
  this->totalTime = 0.0f;
  this->currentImage.x = 0;

  this->uvRect.width = this->texture.getSize().x / float(imageCount.x);
  this->uvRect.height = this->texture.getSize().y / float(imageCount.y);
}

void Animation::update(int row, float deltaTime, bool faceRight) {
  this->currentImage.y = row;
  this->totalTime += deltaTime;

  if (this->totalTime >= this->switchTime) {
    this->totalTime -= this->switchTime;
    this->currentImage.x++;

    if (this->currentImage.x >= this->imageCount.x) {
      this->currentImage.x = 0;
    }
  }

  this->uvRect.top = this->currentImage.y * this->uvRect.height;

  if (row == 2 && !faceRight) {
    this->uvRect.left = (this->currentImage.x + 1) * abs(this->uvRect.width);
    this->uvRect.width = -abs(this->uvRect.width);
  } else {
    this->uvRect.left = this->currentImage.x * abs(this->uvRect.width);
    this->uvRect.width = abs(this->uvRect.width);
  }
}

const sf::Texture &Animation::getTexture() const {
  return texture;
}

const sf::IntRect &Animation::getUvRect() const {
  return uvRect;
}

