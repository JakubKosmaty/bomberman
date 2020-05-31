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
  this->map->update(sf::Vector2u(64, 64));
}

void BombermanApplication::initPlayers() {
  this->player[0] = new Player(RESOURCE_PATH(player1.png), sf::Vector2f(64.0f, 128.0f), sf::Vector2f(11 * 64 + 32, 1 * 64 + 32), sf::Vector2u(8, 3), 0.1f, 4.0f, new Player1Inputer);
  this->player[1] = new Player(RESOURCE_PATH(player2.png), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1 * 64 + 32, 11 * 64 + 32), sf::Vector2u(6, 3), 0.1f, 4.0f, new Player2Inputer);
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
  sf::Event event;
  while (this->window->pollEvent(event)) {
    if (event.Event::type == sf::Event::Closed) {
      this->window->close();
    }
    if(event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape) {
      this->window->close();
    }
  }

  this->player[0]->update(this->deltaTime, this->map->getMapArray());
  this->player[1]->update(this->deltaTime, this->map->getMapArray());

#ifdef DEBUG
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    std::cout << "X: " << e.mouseButton.x << " | Y: " << e.mouseButton.y << std::endl;
  }
#endif
}

void BombermanApplication::render() {
  this->window->clear();

  this->window->draw(*this->map);
  this->window->draw(*this->player[0]);
  this->window->draw(*this->player[1]);

  this->window->display();
}

std::ostream& operator<<(std::ostream& os, const BombermanApplication& application)
{
#ifdef DEBUG
  os << "Developer Mode ON!"
  << "\n";
#endif

  for (auto& p : application.player) {
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

  os
  << "-----------Map-----------\nSize: \nWidth: "
  << application.map->getMapWidth()
  << "\nHeight: "
  << application.map->getMapHeight()
  << "\n"
  << "Tile Map\n";

  const std::vector<int> map = application.map->getMapArray();

  for (int x = 0; x < application.map->getMapWidth(); x++) {
    for (int y = 0; y < application.map->getMapHeight(); y++) {
      os << map[x * application.map->getMapWidth() + y] << " ";
    }
    os << "\n";
  }
  return os;
}

