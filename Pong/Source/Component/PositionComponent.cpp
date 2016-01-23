#include "PositionComponent.h"

namespace PongGame
{
PositionComponent::PositionComponent() {}

PositionComponent::PositionComponent(Vec2& position) : position(position) {}

void PositionComponent::apply(const Vec2& impulse)
{
    velocity += impulse;
}
}