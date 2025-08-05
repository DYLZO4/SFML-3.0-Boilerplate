#include "ExampleState.hpp"
#include "MenuState.hpp"
#include "StateManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

// Main Entry Point
int main() {

  unsigned int windowWidth = 800;
  unsigned int windowHeight = 800;
  unsigned int frameRate = 60;

  sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}),
                          "SFML Boilerplate");
  window.setFramerateLimit(60);

  StateManager stateManager;
  stateManager.pushState(std::make_unique<MenuState>(windowWidth, windowHeight));

  sf::Clock frameClock;

  while (window.isOpen()) {

    // State Management
    State *currentState = stateManager.getCurrentState();
    if (!currentState)
      break;

    if (auto transition = currentState->getRequestedTransition()) {
      switch (transition->action) {
      case StateAction::Push:
        stateManager.pushState(std::move(transition->newState));
        currentState->clearRequestedTransition();
        break;
      case StateAction::Pop:
        stateManager.popState();
        currentState->clearRequestedTransition();
        break;
      case StateAction::Change:
        stateManager.changeState(std::move(transition->newState));
        break;
      case StateAction::None:
        break;
      default:
        break;
      }
      continue; // skip update/draw when frame is changed
    }

    // Event Handling
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      currentState->handleEvent(window, event);
    }

    // Updating
    float dt = frameClock.restart().asSeconds();
    currentState->update(window, dt);

    // Drawing
    window.clear();
    currentState->draw(window);
    window.display();
  }

  return 0;
}
