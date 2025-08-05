#pragma once
#include "State.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class ExampleState : public State {
private:
  std::optional<StateTransition> requested;
public:
  ExampleState();
  void handleEvent(sf::RenderWindow &window,
                   const std::optional<sf::Event> &event) override;
  void update(sf::RenderWindow &window, float dt) override;
  void draw(sf::RenderWindow &window) override;
  std::optional<StateTransition> getRequestedTransition() override;
  void clearRequestedTransition() override;
};
