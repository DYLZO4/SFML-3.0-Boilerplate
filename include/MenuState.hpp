#pragma once
#include "State.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class MenuState : public State {
private:
  std::optional<StateTransition> requested;
  float spacing = 60;
  sf::Font font;
  sf::Text text;
  std::vector<std::string> options = {"Option 1","Option 2","Option 3"};
  std::vector<sf::Text> menuItems;
  int selectedItem = 0;
  unsigned int windowWidth;
  unsigned int windowHeight;
public:
  MenuState(unsigned int windowWidth, unsigned int windowHeight);
  void handleEvent(sf::RenderWindow &window,
                   const std::optional<sf::Event> &event) override;
  void update(sf::RenderWindow &window, float dt) override;
  void draw(sf::RenderWindow &window) override;
  std::optional<StateTransition> getRequestedTransition() override;
  void clearRequestedTransition() override;
};
