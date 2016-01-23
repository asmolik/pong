#include "InputSystem.h"

namespace PongGame
{
InputSystem::InputSystem() {}

void InputSystem::setInput(std::vector<Input>& in)
{
    inputs = in;
}

void InputSystem::setInput(std::vector<InputRange>& in)
{
    ranges = in;
}

void InputSystem::update()
{
    for (auto& context : contexts)
    {
        auto commands = context->mapInput(inputs);
        for (auto& c : commands)
        {
            c.get().execute();
        }
        auto rangeCommands = context->mapInput(ranges);
        for (auto& c : rangeCommands)
        {
            c.get().execute();
        }
    }
}

void InputSystem::addContext(std::unique_ptr<InputContext> context)
{
    contexts.push_back(std::move(context));
}
}