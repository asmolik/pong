#pragma once

#include <vector>
#include <memory>
#include "Physics/Vec2.h"

namespace PongGame
{
struct PositionComponent
{
    Vec2 position;
    Vec2 velocity;
};
}