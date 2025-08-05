#include "MenuState.hpp"
#include "ExampleState.hpp"
#include <iostream>

MenuState::MenuState(unsigned int windowWidth, unsigned int windowHeight)
    : text(font), windowWidth(windowWidth), windowHeight(windowHeight) {

  if (!font.openFromFile("assets/fonts/PressStart2P-Regular.ttf")) {
    std::cerr << "Error loading font\n"; // Make sure the font file exists
  }
  for (size_t i = 0; i < options.size(); i++) {
    text.setFont(font);
    text.setString(options[i]);
    text.setCharacterSize(36);
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    text.setPosition({windowWidth / 2.f,
                      (bounds.size.y / 2.f) +
                          ((windowHeight - (bounds.size.y * options.size() +
                                            (options.size() - 1) * spacing)) /
                           2) +
                          i * spacing});
    menuItems.push_back(text);
  }
}

void MenuState::handleEvent(sf::RenderWindow &window,
                            const std::optional<sf::Event> &event) {
  if (!event.has_value())
    return;
  const sf::Event &e = *event;

  if (e.is<sf::Event::Closed>())
    window.close();

  // Registering Inputs
  if (auto *key = event->getIf<sf::Event::KeyPressed>()) {
    if (key->scancode == sf::Keyboard::Scancode::W) {
      selectedItem = (selectedItem - 1 + menuItems.size()) % menuItems.size();
    }
    if (key->scancode == sf::Keyboard::Scancode::S) {
      selectedItem = (selectedItem + 1 + menuItems.size()) % menuItems.size();
    }
    if (key->scancode == sf::Keyboard::Scancode::Space) {
      switch (selectedItem) {
      case 0:
        requested =
            StateTransition{.action = StateAction::Change,
                            .newState = std::make_unique<ExampleState>()};
        break;
      case 1:
        break;
      case 2:
        break;
      default:
        break;
      }
    }
  }
}

void MenuState::update(sf::RenderWindow &window, float dt) {
  for (size_t i = 0; i < menuItems.size(); ++i) {
    if (i == selectedItem) {
      menuItems[i].setFillColor(sf::Color::Red);
      menuItems[i].setCharacterSize(40);
    } else {
      menuItems[i].setFillColor(sf::Color::White);
      menuItems[i].setCharacterSize(36);
    }
    sf::FloatRect bounds = menuItems[i].getLocalBounds();
    menuItems[i].setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    menuItems[i].setPosition({windowWidth / 2.f,
                      (bounds.size.y / 2.f) +
                          ((windowHeight - (bounds.size.y * options.size() +
                                            (options.size() - 1) * spacing)) /
                           2) +
                          i * spacing});

  }
}

void MenuState::draw(sf::RenderWindow &window) {
  for (auto &item : menuItems) {
    window.draw(item);
  }
}

std::optional<StateTransition> MenuState::getRequestedTransition() {
  return std::move(requested);
}

void MenuState::clearRequestedTransition() {
  if (requested.has_value()) {
    requested.reset();
  }
}
