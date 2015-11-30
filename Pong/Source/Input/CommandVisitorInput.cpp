#include "CommandVisitorInput.h"

namespace PongGame
{
CommandVisitorInput::CommandVisitorInput(RawInput& input) : input(input) {}

CommandVisitorInput::~CommandVisitorInput() {}

void CommandVisitorInput::visit(InputCommand& command)
{
    value = command.shared_from_this();
}

InputCommandP CommandVisitorInput::get()
{
    return value;
}
}