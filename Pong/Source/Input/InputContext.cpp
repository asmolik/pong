#include "InputContext.h"

namespace PongGame
{
    InputContext::InputContext(std::unique_ptr<InputCommandFactory> factory)
        : factory(move(factory)) {}

    InputContext::~InputContext() {}

    std::vector<InputCommandP> InputContext::mapInput(
        std::vector<RawInputP>& input)
    {
        std::vector<std::shared_ptr<InputCommand>> commands;
        for (auto& key : input)
        {
            auto command = inputMap[key];
            commands.push_back(factory->create(*key, command));
        }
        return commands;
    }

    void InputContext::addMapping(RawInputP ri, InputCommandP ic)
    {
        inputMap[ri] = ic;
    }
}