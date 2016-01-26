#pragma once

#include <memory>
#include <vector>
#include "Input/InputContext.h"

namespace PongGame
{
//
// Maps input to commands using contexts and then executes the commands.
//
class InputSystem
{
    std::vector<Input> inputs;
    std::vector<InputRange> ranges;
    std::vector<std::unique_ptr<InputContext>> contexts;
public:
    InputSystem();

    // Set the inputs for mapping in the next update.
    void setInput(std::vector<Input>& inputs);
    // Set the ranges for mapping in the next update.
    void setInput(std::vector<InputRange>& ranges);
    // Maps the inputs and executes the commands.
    void update();
    void addContext(std::unique_ptr<InputContext> context);
};
}