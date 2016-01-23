#include "RangeCommand.h"

namespace PongGame
{
RangeCommand::RangeCommand(PositionComponent& position) : position(position) {}

RangeCommand::~RangeCommand() {}

void RangeCommand::execute()
{
    position.velocity.y = value * 500.0f;
}

void RangeCommand::set(float v)
{
    value = v;
}
}