#pragma once

#include "Component/PositionComponent.h"

namespace PongGame
{
///
/// A game command.
///
class RangeCommand
{
    float value;
    PositionComponent& position;
public:
    RangeCommand(PositionComponent& position);
    virtual ~RangeCommand();
    virtual void execute();
    // Set the range value for this command.
    // Value should be in [-1.0; 1.0] range.
    void set(float value);
};
}