//
// Created by Jakub Kosmaty on 28/05/2020.
//

#include "Player2Inputer.h"

int Player2Inputer::getInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    return 0;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    return 1;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    return 2;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    return 3;
  }

  return -1;
}
