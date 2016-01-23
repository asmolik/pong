#include "InputContext.h"

namespace PongGame
{
InputContext::InputContext() {}

InputContext::~InputContext() {}

std::vector<std::reference_wrapper<Command>> InputContext::mapInput(
    std::vector<Input>& inputs)
{
    std::vector<std::reference_wrapper<Command>> commands;
    for (auto& key : inputs)
    {
        for (auto it = inputMap.find(key); it == inputMap.end() || it->first != key; ++it)
        {
            commands.push_back(*it->second);
        }
    }
    return commands;
}

std::vector<std::reference_wrapper<RangeCommand>> InputContext::mapInput(
    std::vector<InputRange>& rangeInputs)
{
    std::vector<std::reference_wrapper<RangeCommand>> commands;
    for (auto& key : rangeInputs)
    {
        for (auto it = rangeMap.find(key); it != rangeMap.end() && it->first == key; ++it)
        {
            it->second->set(key.get());
            commands.push_back(*(it->second));
        }
    }
    return commands;
}

void InputContext::addMapping(Input in, std::unique_ptr<Command> c)
{
    inputMap.insert(std::make_pair(in, std::move(c)));
}

void InputContext::addMapping(InputRange in, std::unique_ptr<RangeCommand> c)
{
    rangeMap.insert(std::make_pair(in, std::move(c)));
}
}