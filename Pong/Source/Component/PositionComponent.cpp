#include "PositionComponent.h"

namespace PongGame
{
PositionComponent::PositionComponent() {}

PositionComponent::PositionComponent(Vec2& position) : position(position) {}

PositionComponent::PositionComponent(PositionComponent& other) 
    : position(other.position), velocity(other.velocity) {}

void PositionComponent::apply(const Vec2& impulse)
{
    velocity += impulse;
}
}