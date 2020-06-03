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
  this->deltaTime = 0.0f;
}

void BombermanApplication::initMap() {
  this->map = new TileMap();

  this->map->layers.push_back(new Layer);
  this->map->layers.push_back(new Layer);
}

void BombermanApplication::initPlayers() {
  this->players.push_back(new Player(RESOURCE_PATH(player0.png), sf::Vector2f(64.0f, 128.0f), sf::Vector2f(11 * 64 + 32, 1 * 64 + 32), sf::Vector2u(8, 3), 0.1f, 4.0f, new Player1Inputer
  ));
  this->players.push_back(new Player(RESOURCE_PATH(player1.png), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1 * 64 + 32, 11 * 64 + 32), sf::Vector2u(6, 3), 0.1f, 4.0f, new Player2Inputer
  ));
}

BombermanApplication::BombermanApplication() {
  this->initWindow();
  this->initMap();
  this->initPlayers();

  //std::cout << *this;
}

BombermanApplication::~BombermanApplication() {
  delete this->window;
  delete this->map;

  for (int i = 0; i < players.size(); i++) {
    delete this->players[i];
  }
}

void BombermanApplication::run() {
  while (this->window->isOpen()) {
    this->deltaTime = this->clock.restart().asSeconds();
    this->update();
    this->render();
  }
}

void BombermanApplication::update() {
  sf::Event event;
  while (this->window->pollEvent(event)) {
    if (event.Event::type == sf::Event::Closed) {
      this->window->close();
    }
    if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape) {
      this->window->close();
    }
  }

  for (int i = 0; i < players.size(); i++) {
    this->players[i]->update(this->deltaTime, this->map);
  }
}

void BombermanApplication::render() {
  this->window->clear();

  this->window->draw(*this->map);

  for (int i = 0; i < players.size(); i++) {
    this->window->draw(*this->players[i]);
  }

  this->window->display();
}

std::ostream& operator<<(std::ostream& os, const BombermanApplication& application)
{
#ifdef DEBUG
  os << "Developer Mode ON!"
  << "\n";
#endif

  for (auto& p : application.players) {
    os
    << "-----------Player-----------\n"
    << "Speed: "
    << p->getSpeed()
    << "\n"
    << "Position: X: "
    << p->getBody().getPosition().x
    << " Y: "
    << p->getBody().getPosition().y
    << "\n";
  }

  return os;
}

