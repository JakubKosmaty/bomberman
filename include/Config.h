//
// Created by Jakub Kosmaty on 19/05/2020.
//

#ifndef BOMBERMAN_CONFIG_H
#define BOMBERMAN_CONFIG_H

#include <nlohmann/json.hpp>

#define RESOURCE_PATH(x)  "resource/" # x

class WindowConfig;
class Config;

void from_json(const nlohmann::json& j, WindowConfig& wp);
void from_json(const nlohmann::json& j, Config& config);

class WindowConfig {
private:
    std::string title;
    unsigned width;
    unsigned height;
    unsigned frameLimit;
    bool verticalSyncEnable;

public:
    const std::string &getTitle() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getFrameLimit() const;
    bool isVerticalSyncEnable() const;

    friend void from_json(const nlohmann::json& j, WindowConfig &wp);
};

class MapConfig {
private:
    std::vector<int> data;
    unsigned width;
    unsigned height;
    unsigned tileSize;

public:
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getTileSize() const;
    const std::vector<int> &getData() const;

    friend void from_json(const nlohmann::json& j, MapConfig &map);
};

class Config {
private:
    WindowConfig windowConfig;
    MapConfig map;

    Config();
    Config(const Config&) = delete;
    Config(Config&&) = delete;

    static Config instance;

public:
    static const Config& getConfig();
    static void init(nlohmann::json& j);
    const WindowConfig &getWindowConfig() const;
    const MapConfig &getMap() const;

    friend void from_json(const nlohmann::json& j, Config &config);
};

#endif //BOMBERMAN_CONFIG_H
