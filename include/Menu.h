//
// Created by Jakub Kosmaty on 04/06/2020.
//

#ifndef BOMBERMAN_MENU_H
#define BOMBERMAN_MENU_H

#include <SFML/Graphics.hpp>
#include "Config.h"

class Menu : public sf::Drawable {
private:
    std::vector<sf::Text> buttons;
    sf::Font font;

    sf::Texture backgroundTexture;

private:
    sf::Sprite background;

    int selectedItem;

public:
    Menu();
    virtual ~Menu();

    int getSelectedItem() const;

    void init(sf::Vector2u windowSize);
    void addButton(const std::string name, unsigned size, float posX, float posY);
    void update(int key);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawGameOver(sf::RenderTarget* target);
};


#endif //BOMBERMAN_MENU_H
