#include "ExampleState.hpp"

ExampleState::ExampleState() {}

void ExampleState::handleEvent(sf::RenderWindow &window,
                               const std::optional<sf::Event> &event) {
  if (!event.has_value())
    return;
  const sf::Event &e = *event;

  if (e.is<sf::Event::Closed>())
    window.close();
  
  // Registering Inputs
  if (auto *key = event->getIf<sf::Event::KeyPressed>()) {
    if (key->scancode == sf::Keyboard::Scancode::Space) {

      // Example of Changing State
      requested = StateTransition{.action = StateAction::Change,
                                  .newState = std::make_unique<ExampleState>()};

    }
  }
}

void ExampleState::update(sf::RenderWindow &window, float dt) {}

void ExampleState::draw(sf::RenderWindow &window) {}

std::optional<StateTransition> ExampleState::getRequestedTransition() {
  return std::move(requested);
}

void ExampleState::clearRequestedTransition() {
  if (requested.has_value()) {
    requested.reset();
  }
}
