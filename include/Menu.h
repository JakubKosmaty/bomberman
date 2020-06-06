//
// Created by Jakub Kosmaty on 04/06/2020.
//

#ifndef BOMBERMAN_MENU_H
#define BOMBERMAN_MENU_H

#include <SFML/Graphics.hpp>
#include "Config.h"

class Menu : public sf::Drawable {
private:
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    std::vector<sf::Text> buttons;
    int selectedItem;

    void addButton(const std::string name, unsigned size, float posX, float posY);

public:
    void init(sf::Vector2u windowSize);
    void update(int key);
    void resetSelectedItem();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void drawGameOver(sf::RenderTarget* target);

    const int getSelectedItem() const;
};


#endif //BOMBERMAN_MENU_H
