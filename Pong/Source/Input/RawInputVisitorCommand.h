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
class RawInputVisitorCommand : public RawInputVisitor
{
    InputCommandP& command;
    InputCommandP value;

public:
    RawInputVisitorCommand(InputCommandP& command);
    virtual void visit(RawInput& input);
    InputCommandP get();
};
}