#include "InputSystem.h"

namespace PongGame
{
InputSystem::InputSystem() 
{
    commands.reserve(1024);
}

void InputSystem::update()
{
    commands.clear();
    for (auto& context : contexts)
    {
        auto c = context->mapInput(inputs);
        commands.insert(commands.end(), 
            std::make_move_iterator(c.begin()), 
            std::make_move_iterator(c.end()));
    }
}

void InputSystem::addContext(std::unique_ptr<InputContext> context)
{
    contexts.push_back(std::move(context));
}

const std::vector<InputCommandP>& InputSystem::currentCommands()
{
    return commands;
}
}