#pragma once

#include <map>
#include <vector>
#include <memory>
#include "RawInput.h"
#include "InputCommand.h"
#include "InputCommandFactory.h"

namespace PongGame
{
typedef std::shared_ptr<RawInput> RawInputP;
typedef std::shared_ptr<InputCommand> InputCommandP;

///
/// Provides a mapping of RawInputs to game commands.
/// Uses a factory to manage creation of the commands.
///
class InputContext
{
    struct PointedCompare
    {
        bool operator() (const RawInputP& l, const RawInputP& r)
        {
            return *l < *r;
        }
    };
protected:
    std::map<RawInputP, InputCommandP, PointedCompare> inputMap;
    std::unique_ptr<InputCommandFactory> factory;

public:
    InputContext(std::unique_ptr<InputCommandFactory> factory);
    virtual ~InputContext();
    ///
    /// Maps raw inputs to game's commands.
    ///
    virtual std::vector<InputCommandP> mapInput(std::vector<RawInputP>& input);

    virtual void addMapping(RawInputP input, InputCommandP command);
};
}