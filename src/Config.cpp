//
// Created by Jakub Kosmaty on 19/05/2020.
//

#include "Config.h"

void from_json(const nlohmann::json &j, WindowConfig &wp) {
  j.at("title").get_to(wp.title);
  j.at("width").get_to(wp.width);
  j.at("height").get_to(wp.height);
  j.at("frameLimit").get_to(wp.frameLimit);
  j.at("verticalSyncEnable").get_to(wp.verticalSyncEnable);
}

void from_json(const nlohmann::json &j, MapConfig &map) {
  j.at("data").get_to(map.data);
  j.at("width").get_to(map.width);
  j.at("height").get_to(map.height);
  j.at("tileSize").get_to(map.tileSize);
}

void from_json(const nlohmann::json &j, PlayersConfig &players) {
  j.at("texture").get_to(players.texture);
  j.at("width").get_to(players.width);
  j.at("height").get_to(players.height);
  j.at("spawnX").get_to(players.spawnX);
  j.at("spawnY").get_to(players.spawnY);
  j.at("animationX").get_to(players.animationX);
  j.at("animationY").get_to(players.animationY);
  j.at("switchTime").get_to(players.switchTime);
  j.at("speed").get_to(players.speed);
}

const std::string &PlayersConfig::getTexture() const {
  return texture;
}

float PlayersConfig::getWidth() const {
  return width;
}

float PlayersConfig::getHeight() const {
  return height;
}

int PlayersConfig::getSpawnX() const {
  return spawnX;
}

int PlayersConfig::getSpawnY() const {
  return spawnY;
}

int PlayersConfig::getAnimationX() const {
  return animationX;
}

int PlayersConfig::getAnimationY() const {
  return animationY;
}

float PlayersConfig::getSwitchTime() const {
  return switchTime;
}

float PlayersConfig::getSpeed() const {
  return speed;
}

const std::vector<int> &MapConfig::getData() const {
  return data;
}

unsigned int MapConfig::getWidth() const {
  return width;
}

unsigned int MapConfig::getHeight() const {
  return height;
}

unsigned int MapConfig::getTileSize() const {
  return tileSize;
}

const std::string &MapConfig::getTexture() const {
  return texture;
}

void from_json(const nlohmann::json &j, Config &config) {
  j.at("window").get_to(config.windowConfig);
  j.at("map").get_to(config.map);
}

const WindowConfig &Config::getWindowConfig() const {
  return windowConfig;
}

const MapConfig &Config::getMap() const {
  return map;
}

Config Config::instance{};

const Config &Config::getConfig() {
  return Config::instance;
}

void Config::init(nlohmann::json &j) {
  from_json(j, instance);
}

Config::Config() {}

const std::string &WindowConfig::getTitle() const {
  return title;
}

unsigned int WindowConfig::getWidth() const {
  return width;
}

unsigned int WindowConfig::getHeight() const {
  return height;
}

unsigned int WindowConfig::getFrameLimit() const {
  return frameLimit;
}

bool WindowConfig::isVerticalSyncEnable() const {
  return verticalSyncEnable;
}
