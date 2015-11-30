#include "InputCommandFactory.h"

namespace PongGame
{
InputCommandFactory::~InputCommandFactory() {}

InputCommandP InputCommandFactory::create(RawInput& input,
    InputCommandP& command)
{
    RawInputVisitorCommand visitor(command);
    input.accept(visitor);
    return visitor.get();
}
}