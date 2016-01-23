#pragma once

#include <map>
#include <vector>
#include <memory>
#include "Input.h"
#include "InputRange.h"
#include "Command.h"
#include "RangeCommand.h"

namespace PongGame
{
///
/// Provides a mapping of Inputs to Commands.
///
class InputContext
{
protected:
    std::multimap<Input, std::unique_ptr<Command>> inputMap;
    std::multimap<InputRange, std::unique_ptr<RangeCommand>> rangeMap;

public:
    InputContext();
    virtual ~InputContext();
    ///
    /// Maps inputs to game's commands. Can remove inputs from the vector
    /// if they are not supposed to be used in other contexts.
    ///
    virtual std::vector<std::reference_wrapper<Command>> mapInput(
        std::vector<Input>& inputs);
    ///
    /// Maps ranges to game's commands. Can remove inputs from the vector
    /// if they are not supposed to be used in other contexts.
    ///
    virtual std::vector<std::reference_wrapper<RangeCommand>> mapInput(
        std::vector<InputRange>& rangeInputs);

    virtual void addMapping(Input input, std::unique_ptr<Command> command);
    virtual void addMapping(InputRange input, std::unique_ptr<RangeCommand> command);
};
}