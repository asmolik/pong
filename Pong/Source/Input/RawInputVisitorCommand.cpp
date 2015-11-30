#include "RawInputVisitorCommand.h"

namespace PongGame
{
RawInputVisitorCommand::RawInputVisitorCommand(InputCommandP& command)
    : command(command) {}

void RawInputVisitorCommand::visit(RawInput& input)
{
    value = command;
}

InputCommandP RawInputVisitorCommand::get()
{
    return value;
}
}