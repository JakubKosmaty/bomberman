//
// Created by Jakub Kosmaty on 09/05/2020.
//

#include "BombermanApplication.h"
#include "Player1Inputer.h"
#include "Player2Inputer.h"

#include <iostream>

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
  this->deltaTime = 0.0f;
}

void BombermanApplication::initMap() {
  this->map = new TileMap(sf::Vector2u(64, 64));
}

void BombermanApplication::initPlayer() {
  this->player[0] = new Player(RESOURCE_PATH(player1.png), sf::Vector2f(64.0f, 128.0f), 704.0f, 0.0f, sf::Vector2u(8, 3), 0.1f, 256.0f, new Player1Inputer);
  this->player[1] = new Player(RESOURCE_PATH(player2.png), sf::Vector2f(64.0f, 64.0f), 64.0f, 640.0f, sf::Vector2u(6, 3), 0.1f, 256.0f, new Player2Inputer);
}

BombermanApplication::BombermanApplication() {
  this->initWindow();
  this->initMap();
  this->initPlayer();
}

BombermanApplication::~BombermanApplication() {
  delete this->window;
  delete this->map;
  delete this->player[0];
  delete this->player[1];
}

void BombermanApplication::run() {
  while (this->window->isOpen()) {
    this->deltaTime = this->clock.restart().asSeconds();
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

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    std::cout << "X: " << e.mouseButton.x << " | Y: " << e.mouseButton.y << std::endl;
  }

  this->player[0]->update(this->deltaTime);
  this->player[1]->update(this->deltaTime);
}

void BombermanApplication::render() {
  this->window->clear();

  this->window->draw(*this->map);
  this->window->draw(*this->player[0]);
  this->window->draw(*this->player[1]);

  this->window->display();
}


