//
// Created by Jakub Kosmaty on 04/06/2020.
//

#include "Menu.h"


Menu::Menu() {
}

Menu::~Menu() {

}

#include <iostream>

void Menu::init(sf::Vector2u windowSize) {
  this->selectedItem = 0;
  this->backgroundTexture.loadFromFile(RESOURCE_PATH(backgroundTitle.jpg));
  this->background.setTexture(this->backgroundTexture);
  this->background.setScale((float)windowSize.x / this->backgroundTexture.getSize().x, (float)windowSize.y / this->backgroundTexture.getSize().y);

  this->font.loadFromFile(RESOURCE_PATH(ARCADECLASSIC.TTF));

  this->addButton("Play", 100, (float)windowSize.x / 2.f, (float)windowSize.y / 2.f + 50.f);
  this->addButton("Exit", 100, (float)windowSize.x / 2.f, (float)windowSize.y / 2.f + 150.f);
  this->addButton("GAME OVER", 100, (float)windowSize.x / 2.f, (float)windowSize.y / 2.f);

  this->buttons[this->selectedItem].setFillColor(sf::Color::Red);
}

void Menu::addButton(std::string name, unsigned int size, float posX, float posY) {
  sf::Text button;
  button.setFont(this->font);
  button.setString(name);
  button.setCharacterSize(size);
  button.setOrigin(button.getLocalBounds().left + button.getLocalBounds().width / 2.0f, button.getLocalBounds().top + button.getLocalBounds().height / 2.0f);
  button.setPosition(posX, posY);
  this->buttons.push_back(button);
}

void Menu::update(int key) {
  this->buttons[this->selectedItem].setFillColor(sf::Color::White);

  int buttonsSize = this->buttons.size() - 1;

  if (this->selectedItem - key >= buttonsSize) {
    this->selectedItem = 0;
  } else if(this->selectedItem - key < 0) {
    this->selectedItem = buttonsSize - 1;
  } else {
    this->selectedItem -= key;
  }

  this->buttons[this->selectedItem].setFillColor(sf::Color::Red);
}


void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(this->background);

  for (int i = 0; i < this->buttons.size() - 1; i++) {
    target.draw(this->buttons[i]);
  }
}

int Menu::getSelectedItem() const {
  return selectedItem;
}

void Menu::drawGameOver(sf::RenderTarget* target) {
  target->draw(this->buttons[2]);

}






