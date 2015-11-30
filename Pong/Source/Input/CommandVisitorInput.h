#pragma once
#include <memory>
#include "RawInput.h"
#include "RawInputVisitor.h"
#include "InputCommand.h"

namespace PongGame
{
typedef std::shared_ptr<InputCommand> InputCommandP;

///
/// Creates a command based on a RawInput and InputCommand objects.
///
class CommandVisitorInput
{
    RawInput& input;
    InputCommandP value;

public:
    CommandVisitorInput(RawInput& input);
    virtual ~CommandVisitorInput();
    virtual void visit(InputCommand& command);
    virtual InputCommandP get();
};
}