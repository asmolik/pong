#pragma once

#include <memory>
#include "Physics/Vec2.h"

namespace PongGame
{
struct PositionComponent
{
    PositionComponent();
    PositionComponent(Vec2& position);
    PositionComponent(PositionComponent& other);

    Vec2 position;
    Vec2 velocity;

    void apply(const Vec2& impulse);
};
}