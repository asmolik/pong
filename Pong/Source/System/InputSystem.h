#pragma once

#include <memory>
#include <vector>
#include "Input/InputContext.h"

namespace PongGame
{
///
/// Maps raw input to commands using contexts.
///
class InputSystem
{
    std::vector<std::unique_ptr<InputContext>> contexts;
    std::vector<InputCommandP> commands;
    std::vector<RawInputP> inputs;
public:
    InputSystem();

    void update();
    void addContext(std::unique_ptr<InputContext> context);
    const std::vector<InputCommandP>& currentCommands();
};
}