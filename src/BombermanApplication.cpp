//
// Created by Jakub Kosmaty on 09/05/2020.
//

#include "BombermanApplication.h"

void BombermanApplication::initWindow() {
  this->gameState = MENU;

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
  this->players.push_back(new Player(RESOURCE_PATH(player0.png), sf::Vector2f(64.0f, 128.0f), sf::Vector2f(11 * 64 + 32, 1 * 64 + 32), sf::Vector2u(8, 3), 0.1f, 4.0f, new Player1Inputer, 4));
  this->players.push_back(new Player(RESOURCE_PATH(player1.png), sf::Vector2f(64.0f, 64.0f), sf::Vector2f(1 * 64 + 32, 11 * 64 + 32), sf::Vector2u(6, 3), 0.1f, 4.0f, new Player2Inputer, 4));
}

void BombermanApplication::initMenu() {
  this->menu.init(this->window->getSize());
}

BombermanApplication::BombermanApplication() {
  this->initWindow();
  this->initMap();
  this->initPlayers();
  this->initMenu();

  std::cout << *this;
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
    } else if (event.type == event.Event::KeyPressed && (this->gameState == MENU || this->gameState == GAME_OVER)) {
      switch (event.key.code) {
        case sf::Keyboard::Escape:
          this->window->close();
          break;
        case sf::Keyboard::Up:
          this->menu.update(1);
          break;
        case sf::Keyboard::Down:
          this->menu.update(-1);
          break;
        case sf::Keyboard::Enter:
          if (this->gameState == GAME_OVER) {
            this->gameState = MENU;
            this->restart();
          } else if (this->menu.getSelectedItem() == 0) {
            this->gameState = RUN;
          } else if (this->menu.getSelectedItem() == 1) {
            this->window->close();
          }
          break;
        default: break;
      }
    }
  }

  if (this->gameState == RUN) {
    for (int i = 0; i < players.size(); i++) {
      this->players[i]->update(this->deltaTime, this->map);

      if (this->players[i]->isDead()) {
        this->gameState = GAME_OVER;
        break;
      }
    }
  }
}

void BombermanApplication::restart() {
  delete this->map;

  for (int i = 0; i < players.size(); i++) {
    delete this->players[i];
  }

  this->players.clear();

  this->initMap();
  this->initPlayers();

  this->menu.resetSelectedItem();
}

void BombermanApplication::render() {
  this->window->clear();

  if (this->gameState == MENU) {
    this->window->draw(this->menu);
  } else if (this->gameState == RUN || this->gameState == GAME_OVER) {
    this->window->draw(*this->map);
    for (auto& p : this->players) {
      this->window->draw(*p);
    }

    if (this->gameState == GAME_OVER) {
      this->menu.drawGameOver(this->window);
    }
  }

  this->window->display();
}

std::ostream& operator<<(std::ostream& os, const BombermanApplication& application)
{
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
