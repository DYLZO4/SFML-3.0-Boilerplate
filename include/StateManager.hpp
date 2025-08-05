#pragma once
#include <memory>
#include <stack>
#include "State.hpp"

class StateManager {
public:
    void pushState(std::unique_ptr<State> state);
    void popState();
    void changeState(std::unique_ptr<State> state);
    State* getCurrentState();

private:
    std::stack<std::unique_ptr<State>> states;
};

