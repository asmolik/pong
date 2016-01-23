#pragma once

#include <memory>
#include <vector>
#include "Component/PositionComponent.h"

namespace PongGame
{
///
/// Simulates game's physics. Integrates velocities and forces.
///
class PhysicsSystem
{
    std::vector<std::shared_ptr<PositionComponent>> objects;
    float time;
public:
    PhysicsSystem();

    void update();
    void addObject(std::shared_ptr<PositionComponent> object);
    void setTime(float time);
};
}