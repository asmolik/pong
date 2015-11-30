#pragma once

#include <memory>
#include "InputCommand.h"
#include "RawInput.h"
#include "RawInputVisitorCommand.h"

namespace PongGame
{
typedef std::shared_ptr<InputCommand> InputCommandP;

///
/// Creates an InputCommand object using RawInput and InputCommand objects.
/// Uses double dispatch with visitors.
///
class InputCommandFactory
{
public:
    virtual ~InputCommandFactory();
    virtual InputCommandP create(RawInput& input, InputCommandP& command);
};
}