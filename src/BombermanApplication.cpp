//
// Created by Jakub Kosmaty on 09/05/2020.
//

#include "BombermanApplication.h"

void BombermanApplication::initWindow() {
  std::ifstream configFile(RESOURCE_PATH(configFile.json));

  nlohmann::json j;
  configFile >> j;
  configFile.close();

  Config::init(j);

  const Config& config = Config::getConfig();

  const WindowConfig& windowConfig = config.getWindowConfig();
  sf::VideoMode windowBounds(windowConfig.getWidth(), windowConfig.getHeight());

  this->window = new sf::RenderWindow(windowBounds, windowConfig.getTitle());
  this->window->setFramerateLimit(windowConfig.getFrameLimit());
  this->window->setVerticalSyncEnabled(windowConfig.isVerticalSyncEnable());
}

void BombermanApplication::initMap() {
  this->map = new TileMap(sf::Vector2u(64, 64));
}

BombermanApplication::BombermanApplication() {
  this->initWindow();
  this->initMap();
}

BombermanApplication::~BombermanApplication() {
  delete this->window;
}

void BombermanApplication::run() {
  while (this->window->isOpen()) {
    this->update();
    this->render();
  }
}

void BombermanApplication::update() {
  sf::Event e;
  while (this->window->pollEvent(e)) {
    if (e.Event::type == sf::Event::Closed) {
      this->window->close();
    }
    if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
      this->window->close();
    }
  }
}

void BombermanApplication::render() {
  this->window->clear();
  this->window->draw(*this->map);

  this->window->display();
}

