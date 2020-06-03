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

void from_json(const nlohmann::json &j, Map &map) {
  j.at("data").get_to(map.data);
  j.at("width").get_to(map.width);
  j.at("height").get_to(map.height);
  j.at("tileSize").get_to(map.tileSize);
}

const std::vector<int> &Map::getData() const {
  return data;
}

unsigned int Map::getWidth() const {
  return width;
}

unsigned int Map::getHeight() const {
  return height;
}

unsigned int Map::getTileSize() const {
  return tileSize;
}

const std::string &Map::getTexture() const {
  return texture;
}

void from_json(const nlohmann::json &j, Config &config) {
  j.at("window").get_to(config.windowConfig);
  j.at("map").get_to(config.map);
}

const WindowConfig &Config::getWindowConfig() const {
  return windowConfig;
}

const Map &Config::getMap() const {
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
