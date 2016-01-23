#include "InputComponent.h"

namespace PongGame
{
InputComponent::InputComponent() {}

InputComponent::~InputComponent() {}

void InputComponent::accept(Command& command)
{
    command.execute();
}
}