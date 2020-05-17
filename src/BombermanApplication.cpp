//
// Created by Jakub Kosmaty on 09/05/2020.
//

#include "BombermanApplication.h"

void BombermanApplication::initWindow() {

  std::ifstream configFile(windowConfig.ini"));

  std::string title = "None";
  sf::VideoMode windowBounds(800, 600);
  unsigned frameLimit = 120;
  bool verticalSyncEnable = false;

  if (configFile.is_open()) {
    std::getline(configFile, title);
    configFile >> windowBounds.width >> windowBounds.height;
    configFile >> frameLimit;
    configFile >> verticalSyncEnable;
  }

  configFile.close();

  this->window = new sf::RenderWindow(windowBounds, title);
  this->window->setFramerateLimit(frameLimit);
  this->window->setVerticalSyncEnabled(verticalSyncEnable);
}

BombermanApplication::BombermanApplication() {
  this->initWindow();
}

BombermanApplication::~BombermanApplication() {
  delete this->window;
}

void BombermanApplication::updateDt() {
  this->dt = this->dtClock.restart().asSeconds();
  //std::cout << this->dt << "\n";
}

void BombermanApplication::updateSFMLEvents() {
  while (this->window->pollEvent(this->sfEvent)) {
    if (this->sfEvent.type == sf::Event::Closed) {
      this->window->close();
    }
  }
}

void BombermanApplication::update() {
  this->updateSFMLEvents();
}

void BombermanApplication::render() {
  this->window->clear();


  this->window->display();
}

void BombermanApplication::run() {
  while (this->window->isOpen()) {
    this->updateDt();
    this->update();
    this->render();
  }
}

