#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <optional>

class State;

enum class StateAction { None, Push, Pop, Change };

struct StateTransition {
  StateAction action;
  std::unique_ptr<State> newState = nullptr;
};

class State {
public:
  virtual ~State() = default;

  // State lifecycle hooks
  virtual void onEnter() {}
  virtual void onExit() {}

  // Core state interface
  virtual void handleEvent(sf::RenderWindow &window,
                           const std::optional<sf::Event> &event) = 0;
  virtual void update(sf::RenderWindow &window, float dt) = 0;
  virtual void draw(sf::RenderWindow &window) = 0;

  virtual std::optional<StateTransition> getRequestedTransition() {
    return std::nullopt;
  }
  virtual void clearRequestedTransition() {}
};
